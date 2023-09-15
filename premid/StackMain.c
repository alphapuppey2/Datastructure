#include<stdio.h>
#include "Stack.h"
// #include "StackL.h"



int main(void){

    STACK S;

    initialize(&S);

    push(&S ,'U');
    push(&S ,'S');
    push(&S ,'C');

    display(S);

    // pop(&S);
    // printf("\n");

    insertBottom(&S , 'T');
    display(S);

    return 0;
}

