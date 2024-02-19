#include <stdio.h>
#include<stdlib.h>
#include<string.h>

typedef struct sta{
    int data;
    struct sta* link;

}*stack ;

void push(stack *l , int data);
void delete(stack *l);
stack getTop(stack l);
void display(stack l);
void initTop(stack *l);


void cleanUp(stack *l);


int main(void){

    stack top;

    initTop(&top);

    push(&top  , 5);
    push(&top  , 10);
    push(&top  , 15);
    push(&top  , 20);
    stack topnode = getTop(top);
    printf("Top is \033[1;36m%d\033[1;0m\n" , topnode->data);
    display(top);
    printf("\033[1;035mDelete the Top\033[1;0m\n");
    delete(&top);
    delete(&top);

    display(top); 

    //cleaning Up 
    cleanUp(&top);
    if(top == NULL){
        printf("\033[1;035mThe Used Memory is free\033[1;0m\n");
        printf("\033[1;032mClosing The Program...\033[1;0m\n");
    }
    else{
        printf("\033[1;031mFailed to free the Memory\033[1;0m\n");
        
    }



    return 0;
}
void cleanUp(stack *l){

    while(*l != NULL){
        delete(l);
    }
    printf("\n\e[1;93mClearing the Memory used...\e[0m\n");
    getchar();
}
void initTop(stack *l ){
    *l= NULL;
}
void push(stack *l , int data){
    stack newnode = (stack)malloc(sizeof(struct sta));

    if(newnode != NULL){
        printf("Get Number : %d\n",data );
        // scanf("%d", newnode->data);
        newnode->data = data;
        newnode->link = *l;
        *l = newnode;
    }
}
void delete(stack *l){

    stack top = getTop(*l);
    printf("\033[1;31m %5d will be deleted \033[1;0m\n" , top->data);
    *l = top->link;

    free(top);

}
stack getTop(stack l){
    return l;

}
void display(stack l){
    printf("\033[1;035mLists\033[1;0m\n");
    printf("%3s" , " ");
    while( l != NULL){
        printf("\033[1;32m%d \033[1;0m ->" , l->data);
        l = l->link;
    }
    printf("\033[1;32m NULL \033[1;0m\n");

}
