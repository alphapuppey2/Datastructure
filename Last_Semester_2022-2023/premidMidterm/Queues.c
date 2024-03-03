#include<stdio.h>
#include<stdlib.h>


typedef struct p{
    struct p* next;
    char data;
}*nodetype;

typedef struct q{
    nodetype front;
    nodetype rear;
}Queue;





void initQueue(Queue * Q);
void Enqueue(Queue *Q , char data);
void dequeue(Queue *Q);
void display(nodetype A);


int main(void){

    Queue X;

    initQueue(&X);
    Enqueue(&X ,'A');
    Enqueue(&X ,'B');
    Enqueue(&X ,'C');

    display(X.front);

    dequeue(&X);
    dequeue(&X);
    dequeue(&X);

    display(X.front);

    Enqueue(&X ,'D');
    Enqueue(&X ,'E');
    Enqueue(&X ,'F');

    display(X.front);

    dequeue(&X);
    dequeue(&X);
    dequeue(&X);


    return 0;
}
void display(nodetype A){
    for(; A !=NULL ; A = A->next){
        printf("%c ->" , A->data);
    }
    printf("NULL\n");
}
void initQueue(Queue * Q){
    Q->front =Q->rear = NULL;
}
void Enqueue(Queue *Q , char data){

    nodetype newnode = malloc(sizeof(struct p));

    if(newnode != NULL){
        newnode->data = data;
        newnode->next = NULL;

        if(Q->front == NULL && Q->rear == NULL){
            Q->front = Q->rear = newnode;
        }
        else{
            Q->rear->next = newnode;
            Q->rear = newnode;
        }
    }
}
void dequeue(Queue *Q){

    nodetype temp;

    if(Q->front != NULL){
        temp = Q->front;

        Q->front = ( Q->front == Q->rear) ? Q->rear = NULL :  temp->next;

        // if(Q->front == Q->rear){
        //     Q->rear = Q->front = NULL;
        // }
        // else{
        //     Q->front = temp->next;
        // }
        free(temp);
    }



}