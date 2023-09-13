#include<stdio.h>
#include<stdlib.h>

typedef struct N{
    char data;
    struct N * link;
}*List;

void display(List L);
void InsertSorted(List *head , char Data);

int main(void){
    List head = NULL;

    InsertSorted(&head , 'A');
    InsertSorted(&head , 'C');
    InsertSorted(&head , 'D');
    InsertSorted(&head , 'B');

    display(head);




    return 0;
}

void display(List L){
    for(; L != NULL; L = L->link){
        printf("%c " , L->data);
    }
    printf("\n");
}

void InsertSorted(List *head , char Data){
    List newnode = (List)malloc(sizeof(struct N));
    List *Trav;
    if(newnode != NULL){
        for(Trav = head; *Trav != NULL && (*Trav)->data < Data; Trav = &(*Trav)->link){}

        newnode->data = Data;
        newnode->link = *Trav;
        *Trav = newnode;
    }
    else{
        printf("Full");
    }
}