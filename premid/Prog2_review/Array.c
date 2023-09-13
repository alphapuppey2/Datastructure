#include <stdio.h>
#include <stdlib.h>

typedef struct {
   int ID;
   char  LN[16], FN[24], MI;  //Lastname, Firstname, Middle Initial
   char course[8];          
   int yearLevel;
}Studrec;
typedef struct node {
    Studrec stud;
    struct node *link;
}*StudList;   //Definition of the List
Studrec DeleteStudent(StudList *headList , int ID);

int main(void){

    StudList List = NULL;

    Studrec me = {19103296 , "Soqueno" ,"Joshua loui",'R' ,2 };
    // me.FN = "Joshua loui";
    // me.LN = "Soqueno";
    // me.MI = 'R';
    // me.yearLevel = 2;
    // me.ID = 19103296;
    printf("%d , %s %s %c\n",123456, "Soqueno" , "asd" , 'R');
    printf("HAHAHAHAHAHAH\n");

    Studrec deletedRecord = DeleteStudent(&List , 19103296);
    printf("%d , %s %s %c\n" , deletedRecord.ID , deletedRecord.FN , deletedRecord.LN , deletedRecord.MI);


    return 0;
}


Studrec DeleteStudent(StudList *headList , int ID){

    StudList *trav; 
    StudList freeNode;
    Studrec studentRecord = {0, "XXXXX" , "XXXXX" ,'X' , "XXXX" , 0};

    for(trav = headList ; *trav != NULL && (*trav)->stud.ID != ID ; trav = &(*trav)->link){}

    if(*trav != NULL){
        freeNode = *trav;
        studentRecord = (*trav)->stud;
        *trav = (*trav)->link;
        free(freeNode);
    }
    //   printf("%d , %s %s %c\n" , studentRecord.ID , studentRecord.FN , studentRecord.LN , studentRecord.MI);
    return studentRecord;

}