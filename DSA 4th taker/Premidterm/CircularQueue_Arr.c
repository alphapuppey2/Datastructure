#include<stdio.h>

#define MAX 10
typedef struct {
    int elem[MAX];
    int front;
    int rear;
}QueueArr;

void initQueue(QueueArr *QR);
void enqueue(QueueArr *QR , int elem);
void dequeue(QueueArr *QR); // should be Deleting in the front
int isEmpty(QueueArr QR);
int isFull(QueueArr QR);
void display(QueueArr Q);

int main(void){

    QueueArr orig;
    initQueue(&orig);

    enqueue(&orig , 5);
    enqueue(&orig , 10);
    enqueue(&orig , 15);

    display(orig);





    return 0;
}
void initQueue(QueueArr *QR){
    QR->front = 1;
    QR->rear = 0;

}
void enqueue(QueueArr *QR , int elem){

    if(!isFull(*QR)){
        QR->rear = (QR->rear + 1) % MAX;
        QR->elem[QR->rear] = elem;
    }

    
}
void dequeue(QueueArr *QR){

    if(!isEmpty(*QR)){
        QR->front = (QR->front + 1) % MAX;
    }
    
}
int isEmpty(QueueArr QR){
    return ((QR.rear + 1) % MAX == QR.front ) ? 1 : 0 ;

}
int isFull(QueueArr QR){
return (QR.rear + 2) % MAX == QR.front  ? 1 : 0 ;
}
void display(QueueArr Q){
    while (!isEmpty(Q))
    {
        printf("%d ->" , Q.elem[Q.front]);
        dequeue(&Q);
    }
    printf("NULL \n");
}