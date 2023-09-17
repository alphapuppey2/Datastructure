#include<stdio.h>
#include<stdlib.h>


typedef struct p{
    struct p* next;
    char data;
}*nodetype;

typedef struct q
{
    nodetype front;
    nodetype rear;
}Queue;





void initQueue(Queue * Q);
void Enqueue(Queue *Q , char data);


int main(void){

    Queue X;

    initQueue(&X);




    return 0;
}
void initQueue(Queue * Q){
    Q->front =Q->rear = NULL;
}
void Enqueue(Queue *Q , char data){

    nodetype newnode = malloc(sizeof(struct p));

    if(newnode != NULL){
        newnode->data =data;
        Q->rear = newnode;
        if(Q->front == NULL){
            Q->front = Q->rear;
        }
    }
}