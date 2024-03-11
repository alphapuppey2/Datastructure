#include <stdio.h>
#include<stdlib.h>
#include<string.h>
#include<math.h>
#define MAXORDERS 20
#define CUSTBUCKETS 10

int lastOrderNumber = 10000;

typedef enum{OPEN, CLOSED} orderStatus;  //used in Closed Hashing of Orders
typedef enum{PREPARING, SERVED} pizzaStatus;
typedef unsigned char toppingsCW;       //Computer Word representation of toppings
typedef int toppingsBW[8];              //Bit Vector representation of toppings

typedef struct{
    char pizzaName[32];
    toppingsBW pizzaToppings;
}pizzaType;

typedef struct pizzaNode{
    pizzaType P;
    pizzaStatus pStat;                  //PREPARING by default
    struct pizzaNode* nextPizza;
}pizzaNode, *pizzaList;

typedef struct{
    char fName[64];
    char lName[32];
}nameDetails;

typedef struct{
    char customerID[9];
    nameDetails custName;
}customer;

typedef struct customerNode{
    customer C;
    struct customerNode* nextCust;
}customerNode, *custList;

typedef custList cDict[CUSTBUCKETS];    //Open Hashing Representation of Customers

typedef struct{
    int orderNumber;
    customer cust;
    pizzaList pList;
    orderStatus stat;                   //OPEN by default
}orderType;

typedef struct{
    orderType orderList[MAXORDERS];
    int numOrders;
}orderList;                             //Closed Hashing Representation of Orders

void createCustomerFile(void)
{
    customer customers[] = {
            {"CUST001", {"SEAN ANSELMO", "ABELLANA"}},
            {"CUST002", {"VICTOR", "AGUHOB"}},
            {"CUST003", {"YEVGENY GRAZIO MARI", "ALBANO"}},
            {"CUST004", {"MIGUEL CARLOS", "BERINGUEL"}},
            {"CUST005", {"KARYLLE", "BERNATE"}},
            {"CUST006", {"RAYNOR", "BUHIAN"}},
            {"CUST007", {"NIÑO JAN", "CABATAS"}},
            {"CUST008", {"KENNETH JOHN", "CANTILLAS"}},
            {"CUST009", {"VINCEADE", "CENTINO"}},
            {"CUST010", {"JUN", "CHEONG"}},
            {"CUST011", {"CERIL", "HEYROSA"}},
            {"CUST012", {"JEREMIAH JACOB ANTHONY", "JUINIO"}},
            {"CUST013", {"JIWOO", "JUNG"}},
            {"CUST014", {"XANDER JACOB", "LABIDE"}},
            {"CUST015", {"ACHILLE LORENZO", "LANUTAN"}},
            {"CUST016", {"MATT VINCENT", "MAGDADARO"}},
            {"CUST017", {"GREGG ALEXANDER", "MARAYAN"}},
            {"CUST018", {"JASPER LEE", "MARBELLA"}},
            {"CUST019", {"DAN LIUS", "MONSALES"}},
            {"CUST020", {"SHAWN RYAN", "NACARIO"}},
            {"CUST021", {"SHANNEN", "NAZARENO"}},
            {"CUST022", {"OIEU ZHYDD", "NUNEZA"}},
            {"CUST023", {"MARC NELSON", "OCHAVO"}},
            {"CUST024", {"RAY EMANUEL", "PATALINGHUG"}},
            {"CUST025", {"NATHAN ELDRIDGE MITNICK", "PERNITES"}},
            {"CUST026", {"LANCE JUSTIN", "RAMOS"}},
            {"CUST027", {"KENT JOSEPH", "RICONALLA"}},
            {"CUST028", {"JOSHUA LOUI", "SOQUENO"}},
            {"CUST029", {"ASHLENGAIL", "VICTOR"}},
            {"CUST030", {"MURLIWANI", "GANGARAM"}}
        };
        FILE* file = fopen("customers.txt", "w");
        if (file != NULL) {
            for (int i = 0; i < sizeof(customers) / sizeof(customers[0]); i++) {
                fwrite(&customers[i], sizeof(customer), 1, file);
            }
        }
        fclose(file);
}

/*
 initCustomerDict() = This function will receive as parameter a cDict, which is an array of custList (Linked List of Customers). The function will initialize the dictionary by setting each element in cDict to be empty.
 */
void initCustomerDict(cDict customers)
{
    for (int i = 0; i < CUSTBUCKETS; i++)
    {
        customers[i] = NULL;
    }
}

/*
 hashCustomer() = This function will receive as a parameter a customerID. The function will add up the first 3 digits in the customerID and let the remainder of the sum when divided by 10 be returned to the calling function.
 */
int hashCustomer(char customerID[])
{
    int retVal = -1;
    int DigitCount =0;
    int x;
    for(x =0 ; customerID[x] != '\0'; x++ ){
        if(customerID[x] >= '0' && customerID[x] <= '9'){
            retVal += customerID[x] - '0';
        }
    }  
    
    
    return retVal % CUSTBUCKETS;
}

/*
 addNewCustomer() = This function will add a new customer to the cDict given a customer record. The function will only add the customer if the customer does not yet exist. Also, the customer is inserted into its proper "bucket" (linked list at index N based on hash). The new customer should be inserted in its proper place in the list, sorted ascending by family name.
 */
void addNewCustomer(cDict customers, customer C)
{
    int cell = hashCustomer(C.customerID);

    custList *trav;

    for(trav = &customers[cell] ; *trav != NULL && strcmp((*trav)->C.custName.lName , C.custName.lName) > 0 ;trav = &(*trav)->nextCust){}


    custList newNode = (custList)malloc(sizeof(customerNode));
    if(newNode != NULL){
        newNode->C = C;
        newNode->nextCust = *trav;
        *trav = newNode;
    }
    
}

/*
 populateCustomers() = This function will read a file "customers.txt", and populate the given cDict with the customer records in the file. You may use the previously written functions for this function.
 */
void populateCustomers(cDict customers){


    FILE *fptr;


    fptr = fopen("customers.txt", "r");
    customer C;

        if(fptr != NULL){
            while (fread(&C , sizeof(customer),1,fptr))
            {
                addNewCustomer(customers,C);
            }
            
        }
    fclose(fptr);
}

/*
 buildPizza() = This function will receive as parameter a pizzaName, and a list of toppings represented in computer word. Each bit in the CW representation represent the ff:
        0000 0000
        8765 4321
    1 - Pepperoni
    2 - Ham
    3 - Onions
    4 - Pineapples
    5 - Bacon
    6 - Olives
    7 - Bell Peppers
    8 - Mushrooms
    
    For example: A Hawaiian Pizza with mushrooms, pineapples, and pepperoni is represented as: 1000 0101.
 
    Once the pizza record has been built, return it to the calling function.
 */
pizzaType buildPizza(char pizzaName[], toppingsCW toppings)
{
    pizzaType retVal ;
    strcpy(retVal.pizzaName,pizzaName);
    
    int mask;
    int x;
    //convert CW to BW
    for(x =7 ,mask = 1 << 8 - 1; x >= 0 ;x--){
            retVal.pizzaToppings[x] = (toppings & mask) == 1;
    }
    
    return retVal;
}

/*
 hashOrder() = The function will receive an orderID as parameter. The function will take the last 4 digits of the orderID, and return the remainder when it is divided by 20.
 */

int hashOrder(int orderID)
{
    // int d ;
    // int sum = 0;
    // for(d= 0 ; d < 4 ; d++){
    //     sum +=orderID % 10;
    //     orderID = orderID / 10;
    // }

    return orderID % MAXORDERS;
}

/*
 orderPizza() = This function will receive an orderList, a cDict, a customerID, and a pizza to order. The function will add a new order to the orderList for the given customerID and pizza record. Update any fields as necessary. Only add the order if the customer exists. Resolve any collisions using linear probing.
 */

void orderPizza(orderList* orders, cDict customers, char customerID[], pizzaType pizza)
{
    int custNdx = hashCustomer(customerID);
    int ndx = hashOrder(lastOrderNumber + custNdx);
    int OrderCount,orderID;
    custList trav;

    for(trav = customers[custNdx],orderID = 0 ; trav != NULL && strcmp(trav->C.customerID , customerID) != 0; trav = trav->nextCust){}

    for (OrderCount = 0; OrderCount < MAXORDERS && strcmp(orders->orderList[ndx].cust.customerID , customerID) != 0 && orders->orderList[ndx].orderNumber != -1 && orders->orderList[ndx].stat != CLOSED;ndx = (ndx + 1) % MAXORDERS, OrderCount++)
    {}



    if (OrderCount < MAXORDERS && trav != NULL)
    {
        pizzaList newnode = (pizzaList)malloc(sizeof(pizzaNode));
        if(newnode != NULL){
            newnode->P = pizza;
            newnode->pStat = PREPARING;
            newnode->nextPizza = orders->orderList[ndx].pList;
            orders->orderList[ndx].pList = newnode;

            orders->orderList[ndx].orderNumber = lastOrderNumber + custNdx;
            orders->orderList[ndx].cust = trav->C;
        }
    }
    else{
        printf(" \033[1;31mFAILED TO CREATE ORDER DUE TO ID NOT FOUND \033[1;0m\n");
    }
    
}

/*
 updateOrderStatus() = This function will receive an orderList and an orderID. The function will go through the list of pizzas in the order record of the given orderID, and check if all of the pizzas have been SERVED. If they have all been SERVED, then the function will update the orderStatus to CLOSED.
 */


void updateOrderStatus(orderList* orders, int orderNumber)
{
    int orderNDX = hashOrder(orderNumber);
    pizzaList trav;

    for(trav = orders->orderList[orderNDX].pList; trav != NULL && trav->pStat != PREPARING; trav = trav->nextPizza){}

    if(trav == NULL){
         orders->orderList[orderNDX].stat = CLOSED;
    }
}

/*
 servePizza() = This function will receive an orderList, an orderNumber and a pizzaName. The function will go through the given orderList and the pizzas for the specified orderNumber. If the pizza exists, then update the pizzaStatus to be SERVED.
 */
void servePizza(orderList* orders, int orderNumber, char pizzaName[])
{
    // system("CLS");
    int orderNDX = hashOrder(orderNumber);
    pizzaList trav;
    for(trav = orders->orderList[orderNDX].pList;trav != NULL && strcmp(trav->P.pizzaName , pizzaName) != 0; trav = trav->nextPizza){}
    
    if(trav != NULL){
        trav->pStat = SERVED;
    }
    else{
        printf("%s NOT FOUND in order %d\n", pizzaName , orderNumber);
    }
    
    updateOrderStatus(orders , orderNumber);
    
}
/*
 displayOrderList() = This function will go through each order in the orderList and display each of the orders in the ff: format:
 
    OrderNumber:
    Customer ID:
    Customer Name:
    Pizza Orders: pizzaName1(SERVED) -> pizzaName2(PREPARING)
    Order Status:
 */

void displayOrderList(orderList orders)
{
    printf("%s","-----------------------------\n");
    int x;
    char pstatus[][20] = {"SERVED", "PREPARING" };
    int st = 1;
    pizzaList trav;
    
    for(x = 0; x < MAXORDERS; x++){

        if(orders.orderList[x].pList != NULL && orders.orderList[x].pList->pStat == SERVED){
            st = 0;
        }
        else {
            st = 1;
        }
        printf("OrderNumber: %d\n",orders.orderList[x].orderNumber);
        printf("Customer ID: %s\n", orders.orderList[x].cust.customerID);
        printf("Customer Name:%s , %s\n",  orders.orderList[x].cust.custName.lName,orders.orderList[x].cust.custName.fName);
        if(orders.orderList[x].pList != NULL){
            printf("Pizza Orders: ");
            for(trav =orders.orderList[x].pList ; trav != NULL ; trav = trav->nextPizza){
                if(trav->pStat == SERVED){
                    st = 0;
                }
                else {
                    st = 1;
                }
                printf("%s(%s) ->", trav->P.pizzaName ,pstatus[st]);
            }
            printf("END LIST\n");
        }
        else{
            printf("Pizza Orders: No Orders\n");
        }
        if(orders.orderList[x].stat == OPEN){
            printf("Order Status: \033[1;32m%s\033[1;0m\n", "OPEN");
        }
        else{
             printf("Order Status: \033[1;31m%s\033[1;0m\n", "CLOSED");
        }
        printf("%s","-----------------------------\n");
    }
    
}

int main(void)
{
    // createCustomerFile();
    
    cDict Customers;
    orderList odr;
    toppingsBW toppings;
    toppingsCW TopsCW;

    //initialize TOppinBW
    int BWcount; 
    for(BWcount =0 ; BWcount < 8;BWcount++){
        toppings[BWcount] = 0;
    }

    int iOrder;
    char ID[10];
    char pizzaAvail[][50] = {"pizza supreme" ,"hawaiian","beef pepperoni"};
    // pizzaType pizzaAvailable[3] = {{"Pizza Supreme" , 123} , {"Hawaiian",52},{"Beef Pepperoni" , 23}};
    initCustomerDict(Customers);
    populateCustomers(Customers);

    //initialize the Order
    int x;
    for(x =0 ; x < MAXORDERS ; x++){
        odr.orderList[x].orderNumber = -1;
        strcpy(odr.orderList[x].cust.custName.lName,"------");
        strcpy(odr.orderList[x].cust.custName.fName,"------");
        strcpy(odr.orderList[x].cust.customerID,"------");
        odr.orderList[x].stat = OPEN;
        odr.orderList[x].pList = NULL;
    }

    printf("Welcome to PIZZA HUT \n\n");
    printf("May i Take your ID :: CUST001\n");
    // scanf("%s", ID);
    strcpy(ID,"CUST001");

    printf("Menu ::\n");
    printf("------------------------\n");
    printf("[0] Pizza Supreme\n");
    printf("[1] Hawaiian \n");
    printf("[2] Beef Pepporoni\n");
    printf("-------------------\n");
    printf("What is your Order? ");
    iOrder = 1;
    // scanf("%d",&iOrder);
    // system("CLS");
    printf("1\n" );
    printf("you want \033[1;32m[%d]%s\033[1;0m \n" , iOrder,pizzaAvail[iOrder]);
    /*
        1 - Pepperoni
        2 - Ham
        3 - Onions
        4 - Pineapples
        5 - Bacon
        6 - Olives
        7 - Bell Peppers
        8 - Mushrooms
    */
    // int toppingChoose[8] ={1,1,0,1,0,0,0,1};
    // while(toppingChoose != -1){
    //     system("CLS");
        printf("Additional Toppings  :: \n");
        printf("------------\n");
        printf("[0] Pepperoni\n[1] Ham\n[2] Onions\n[3] Pineapples\n[4] Bacon\n[5] Olives\n[6] Bell Peppers\n[7] Mushrooms\n[-1] Done\n 0,1,3,7,-1\n");
    //     scanf("%d",&toppingChoose);
    //     toppings[toppingChoose] = 1;
    //     if(toppingChoose < 8 && toppingChoose >=0){
    //         cwValue += pow(2,toppingChoose);
    //     }
    // }

    /*TESTING VALUE*/
    TopsCW = 145;
    
    /* pizzaType Cooking =  buildPizza(pizzaAvail[iOrder],TopsCW); */
    /*  orderPizza(&odr ,Customers,"CUST001",Cooking); */

    pizzaType Cooking1 =  buildPizza(pizzaAvail[0],51);
    pizzaType Cooking2 =  buildPizza(pizzaAvail[1],23);
    pizzaType Cooking3 =  buildPizza(pizzaAvail[2],62);
    pizzaType Cooking4 =  buildPizza(pizzaAvail[2],165);
    orderPizza(&odr ,Customers,"CUST001",Cooking1);
    orderPizza(&odr ,Customers,"CUST002",Cooking2);
    orderPizza(&odr ,Customers,"CUST001",Cooking3);
    orderPizza(&odr ,Customers,"CUST028",Cooking4);

    displayOrderList(odr);

    servePizza(&odr,10009,"pizza supreme");
    servePizza(&odr,10001,"hawaiian");

    printf("-------SERVED-------\n");
    displayOrderList(odr);

    

    



    


    









    return 0;
}
