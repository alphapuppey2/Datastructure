#ifndef stacklib
#include <stdlib.h>
#define stacklib

typedef struct n{
    char elem;
    struct n* link;
}*STACK;

void InitStack(STACK *S);
void Push(STACK *S ,char elem);
void Pop(STACK *S);
STACK Top(STACK S);
void MakeNull(STACK *S);
int isEmpty(STACK S); // either the TOP is -1 or MAX
int isFull(STACK S); // either the TOP is -1 or MAX
void Display(STACK S);
void InsertBottom(STACK *S , char Data);

void Display(STACK S){ 

    for(; S != NULL ; S = S->link ){
        printf("%c ->" , S->elem);
    }
    printf("NULL \n");
}

void InsertBottom(STACK *original , char elem){

    STACK  TempList;
    STACK trav;

    InitStack(&TempList);


    for(trav = Top(*original) ; trav != NULL ; trav = Top(*original)){
        Push( &TempList , trav->elem);
        Pop(original);
    }

    Push(original , elem);

    for(trav = Top(TempList) ; trav != NULL ; trav = Top(TempList)){
        Push( original , trav->elem);
        Pop(&TempList);
    }
}

void InitStack(STACK *S){
    *S = NULL;
}
void Push(STACK *S ,char elem){
    STACK newnode = (STACK)malloc(sizeof(struct n)); 

    if(newnode != NULL){
        newnode->elem = elem;
        newnode->link = *S;
        *S = newnode;
    }
}
void Pop(STACK *S){
    STACK temp;

    if(!isEmpty(*S)){
        temp = *S;
        *S = temp->link;
        free(temp);
    }

}
STACK Top(STACK S){
    return S;
}
void MakeNull(STACK *S){
    *S = NULL;
}
int isEmpty(STACK S){
    return S == NULL ? 1 : 0;
}


#endif