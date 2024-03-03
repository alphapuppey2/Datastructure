#include <stdlib.h>
#include<stdio.h>

typedef struct S
{
    char data;
    struct S* link;

}*Stack;

/*Function Prototype*/
void Push(char elem, Stack *List);
void Intialize(Stack * List);
void Display(Stack List);
char Pop(Stack *head); // removes the Top and Return to the Calling Function
char Top(Stack head);



int main(void){

    Stack top; 

    Intialize(&top);

    Push('U',&top);
    Push('S',&top);
    Push('C',&top);
    
    Display(top);

    Pop(&top);
    Pop(&top);



    
    Display(top);


    return 0;
}
void Push(char elem, Stack *List){

    Stack newnode;

    newnode = (Stack)malloc(sizeof(struct S));

    if(newnode != NULL){
        newnode->data = elem;
        newnode->link = *List;
    }
    
    *List = newnode;


}
void Intialize(Stack * List){
    *List = NULL;
}
void Display(Stack List){
    for (; List != NULL; List = List->link)
    {
        printf("%c -> " , List->data);
    }
        printf("NULL\n");
    
}
char Pop(Stack *head){
    // removes the Top and Return to the Calling Function

    char ret;
    Stack release = *head;
    ret = (*head)->data;
    *head = (*head)->link;

    free(release);

    return ret;

}
char Top(Stack head){
    // returns The top of the Stack

    return head->data;
}
