#include "Stack.h"
#include<stdio.h>


void display(STACK A){ 
    int x;
    for(x = A.TopList;x < MAX ; x++ ){
        printf("%c\n" , A.elem[x]);
    }

}

void insertBottom(STACK *original , char elem){

    int Topndx;
    STACK templist;

    initialize(&templist); // para d mag error ang templist kay garbage pa before sa call ani


    // Loop to transfer All Existing in the Original List to a temp to insert elem to Last
    for(Topndx = top(*original); Topndx != MAX; Topndx = top(*original)){
        push(&templist ,original->elem[Topndx]);
        pop(original);
    }
    push(original,elem);

    for(Topndx = top(templist); Topndx != MAX ; Topndx = top(templist)){
        push(original ,templist.elem[Topndx]);
        pop(&templist);
    }
}

void initialize(STACK *A){
    A->TopList = MAX;
}
void push(STACK *A ,char elem){

    if(!isFull(*A)){
        A->elem[--A->TopList] = elem;
    }
}
void pop(STACK *A){
    if(!isEmpty(*A)){ // if there is nothing to delete
        A->TopList++;
    }
}
int top(STACK A){
    return A.TopList;
}
Boolean isEmpty(STACK A){
    Boolean Ret = A.TopList == MAX ? T:F;
    return Ret;
}
Boolean isFull(STACK A){
    Boolean Ret = A.TopList == -1 ? T:F;
    return Ret;
}
