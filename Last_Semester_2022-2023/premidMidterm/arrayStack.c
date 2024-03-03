#include<stdio.h>
#define MAX 5

typedef struct n{
    char elem[MAX];
    int top;
}STACK;
typedef enum{F,T} Boolean;

void initStack(STACK *l);
void push(STACK *l , char elem);
void pop(STACK *l);
int top(STACK l);
void display(STACK l);
Boolean isEmpty(STACK L);
Boolean isFull(STACK L);


int main(void){


    STACK list;
    initStack(&list);

    push(&list , 'U');
    push(&list , 'S');
    push(&list , 'C');
    push(&list , 'T');
    push(&list , 'C');

    push(&list , 'C');

    display(list);
    pop(&list);

    display(list);
    pop(&list);
    
    display(list);


    return 0;
}
void display(STACK l){
    printf("index | Elem\n");
    for(; l.top < MAX; l.top++){
        printf(" %3d | %3c\n" ,l.top,l.elem[l.top]);
    }
    printf("NULL\n");

}
void initStack(STACK *l){
    l->top = MAX;

}
void push(STACK *l , char elem){
    
    if(!isFull(*l)){
        l->elem[--l->top] = elem;
    }
    else{
        printf("element %c cannot be insert due to lack of memory \n" , elem);
    }

}
void pop(STACK *l){

    if(!isEmpty(*l)){
        l->top++;
    }

}
int top(STACK l){
    return l.top;
}
Boolean isEmpty(STACK L){
    return L.top == MAX ? T:F;
}
Boolean isFull(STACK L){
    return L.top == 0 ? T : F;
}