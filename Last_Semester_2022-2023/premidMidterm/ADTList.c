#include <stdio.h>
#include<stdlib.h>
#define MAX 10

typedef struct {
    char Firstname[24];
    char Lastname[16];
    char Mi;
}NameType;
typedef struct {
    NameType name;
    int ID;
    char Course[8];
    int year;
}record;
typedef struct {
    record Student[MAX];
    int Count;
}List;


// Version

void InitList(List *HeadList);
int Insert(List *headList , record data);
int Locate(List headList, int ID);
void MakeNull(List *head);
void printList(List head);



int main(void){

    List l; 
    InitList(&l);

    // initialized Data
    record student[5] = {{{"Joshua loui" , "Soqueno",'R'} , 19103296 , "BSIT" , 2},
                         {{"Juan" , "one",'1'} , 20230001 , "BSIT" , 2},
                         {{"tou" , "two",'2'} , 20230002 , "BSIT" , 2},
                         {{"toree" , "three",'3'} , 20230003 , "BSIT" , 2},
                         {{"Foor" , "four",'4'} , 20230004 , "BSIT" , 2}};
    int x;

    // 5 data to be inserted
    for(x = 0 ; x < 5; x++){
        if (!Insert(&l , student[x]))
        {
            printf("Failed!");
        }
    }

    printList(l);
    
    int found = Locate(l , 20230003);

    if(getchar() == '\n')
        found > -1 ? printf("The ID Found At Index :: %d" , found): printf("Data not Found\n");

    return 0;
}
void InitList(List *HeadList){
    HeadList->Count = 0;

}
int Insert(List *headList , record data){

   if(headList->Count < MAX){
     headList->Student[headList->Count ++] = data;
   }
    return headList->Count < MAX ? 1:0;
}
int Locate(List headList, int ID){
    int x; 
    for(x =0; x < headList.Count && headList.Student[x].ID != ID; x++){}

        printf("Locating %d Loading ... " , ID);

    return x < headList.Count ? x: -1;
}
void MakeNull(List *head){
    head->Count = 0;
}
void printList(List head){
    int x;
    printf("students Are :: \n");
    for(x =0; x < head.Count ; x++){
        printf("%d | %s ,%s %c %s %d\n" , head.Student[x].ID , head.Student[x].name.Lastname , head.Student[x].name.Firstname , head.Student[x].name.Mi , head.Student->Course , head.Student[x].year);
    }
}











