/*
    NOTE

    Review programming 2

*/


#include <stdio.h>
#include <stdlib.h>

typedef struct N{
    char data;
    struct N* link;
}*List;


int insert(char elem , List *trav);
void display(List head);
void freeAll(List head);

int main(void){

    List head = NULL;


    insert('u' , &head) == 0 ? printf("The Insertion failed , either Memory is full or Character %c%c%c is already existed in the List\n" , '"','u' , '"'): printf("");
    insert('s' , &head) == 0 ? printf("The Insertion failed , either Memory is full or Character %c%c%c is already existed in the List\n" , '"','u' , '"'): printf("");
    insert('c' , &head) == 0 ? printf("The Insertion failed , either Memory is full or Character %c%c%c is already existed in the List\n", '"','u' , '"'): printf("");
    insert('u' , &head) == 0 ? printf("The Insertion failed , either Memory is full or Character %c%c%c is already existed in the List\n", '"','u' , '"'): printf("");

    display(head);
    freeAll(head);
    return 0;
}
void freeAll(List head){
    List temp;

    for (temp = head; head != NULL;)
    {
        head = head->link;
        free(temp);
        temp = head;
    }
    
}
void display(List head){


    printf("The List is :: \n");

    for (; head != NULL; head = head->link)
    {
        printf("%c ",head->data);
    }
    

}

 int insert(char elem , List *trav){

    int succession  = 0;

    for(; *trav != NULL && (*trav)->data != elem; trav = &(*trav)->link ){}

    if(*trav == NULL){
        
        *trav = (List)malloc(sizeof(struct N));

       if(*trav != NULL){
        (*trav)->data = elem;
        (*trav)->link = NULL;
         succession = 1;
       }
    }

return succession == 0 ? 0 : 1 ; 
}

