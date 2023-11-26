#include <stdio.h>
#include<stdlib.h>
#include<string.h>
#define MAX 5


typedef struct {
    char carModel[40];
    char carBrand[20];
    int carYear;
}carNode;

typedef struct n{
    carNode car;
    int left;
    int right;
}nodetype;

typedef struct virt{
    nodetype nodes[MAX];
    int avails;
}virtualHeap;

typedef int BST;



void initVirtual(virtualHeap *VH);
void initBST(BST * h);

int allocSpace(virtualHeap * VH);

void insertNode(virtualHeap *VH , BST* head ,carNode C);

void populateCarNode(carNode * node);
void display(virtualHeap VH , BST head);



int main(void){

    virtualHeap Space;
    BST rootIdx;

    initVirtual(&Space);
    initBST(&rootIdx);

    display(Space , rootIdx);

    carNode list[MAX] ={{"Ambition Hatchback" , "Audi" , 2014} , 
                        {"BMW 2 series grand coupe M sport sedan" , "BMW" , 2023},
                        {"ATS Premiums Coupe " , "Cadallic" , 2017},
                        {"C-max Grand MPV" , "Ford" , 2011},
                        {"Accent GLS sedan " ,"Hyundai" , 2015},
                        };

    insertNode(&Space, &rootIdx , list[0]);
    insertNode(&Space, &rootIdx , list[1]);
    insertNode(&Space, &rootIdx , list[2]);

    display(Space , rootIdx);



    return 0;
}
void populateCarNode(carNode * node){

    gets(node->carBrand);
    gets(node->carModel);
    scanf("%d" , &node->carYear);
    
}

void insertNode(virtualHeap *VH , BST *h, carNode C){

    int newnode = allocSpace(VH);

    if(newnode != -1){
        int *trav;


        VH->nodes[newnode].car = C;
        VH->nodes[newnode].left = VH->nodes[newnode].right = -1; 

        for(trav = h ; *trav != -1;){
            if(VH->nodes[*trav].car.carYear > C.carYear){
                trav = &VH->nodes[*trav].left;
            }
            else{
                trav = &VH->nodes[*trav].right;
            }
        }
        *trav = newnode;
    }

}

int allocSpace(virtualHeap * VH){
    int ret;

    ret = VH->avails;

    if(ret != -1){
        VH->avails = VH->nodes[ret].left;
    }


    return ret;
    
}

void display(virtualHeap VH , BST head){
    int x;

    printf("ROOT : %d\n" , head);

    for(x = 0; x < MAX  ; x++){
        printf("[%d] %d ::  %d | %d \n", x,VH.nodes[x].car.carYear,VH.nodes[x].left , VH.nodes[x].right);
    }
}

void initVirtual(virtualHeap *VH){
    int x; 

    for(x = 0; x < MAX ; x++){
        VH->nodes[x].left = x - 1;
        VH->nodes[x].right = -1;
    }

    VH->avails = MAX - 1;
}
void initBST(BST * h){
    *h = -1;
}