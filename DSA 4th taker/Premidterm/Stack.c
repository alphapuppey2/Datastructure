#include<stdio.h>
#include<stdlib.h>
#define max 10

typedef struct stk{
    int elem[max];
    int top;
}Stack;


void push(Stack * stk, int data);
void pop(Stack* stk);
int Top(Stack stk);
void initStack(Stack *stk);
int isEmpty(Stack stk);
int isFull(Stack stk);
void display(Stack stk);


int main(void){

    Stack original;

    initStack(&original);

    push(&original,5);
    push(&original,10);
    push(&original,15);

    display(original);







    return 0;
}
void display(Stack stk){

    while(stk.top != -1){
        printf("%d -> " , stk.elem[stk.top]);
        pop(&stk);
    }
    printf("NULL");

}
void push(Stack * stk, int data){

    if(stk->top < max)
    {
        stk->top++;
        stk->elem[stk->top] = data;
    }
}
void pop(Stack* stk){
    if(stk->top != -1){
        stk->top--;
    }
    
}
int isEmpty(Stack stk){
    return (stk.top == -1) ? 1: 0;
}
int isFull(Stack stk){
    return (stk.top == max) ? 1: 0;
}
int Top(Stack stk){
    return stk.top;
}
void initStack(Stack *stk){
    stk->top = -1;
}