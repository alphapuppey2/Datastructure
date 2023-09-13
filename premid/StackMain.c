#include<stdio.h>
// #include "Stack.h"
#include "StackL.h"



int main(void){

    STACK S;

    InitStack(&S);

    Push(&S ,'U');
    Push(&S ,'S');
    Push(&S ,'C');

    Display(S);

    // Pop(&S);
    // printf("\n");

    InsertBottom(&S , 'T');
    Display(S);

    return 0;
}

