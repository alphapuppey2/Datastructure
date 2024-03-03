#include<stdio.h>
#include<stdlib.h>

#define max 10

typedef struct {
    char data[max];
    int front;
    int rear;
}circular;

void initialize(circular *arr);
void enqueue(circular *arr , char data);
void dequeue(circular *arr);
int isEmpty(circular arr);
int isFull(circular arr);
void display(circular arr);

int main(void){

    circular arr;

    initialize(&arr);

    enqueue(&arr , 'A');
    enqueue(&arr , 'B');
    enqueue(&arr , 'C');
    enqueue(&arr , 'D');
    enqueue(&arr , 'E');
    enqueue(&arr , 'F');
    enqueue(&arr , 'G');
    enqueue(&arr , 'H');
    enqueue(&arr , 'I');
    // no insert will happen because its full
    enqueue(&arr , 'J');

    display(arr);

    dequeue(&arr);

    display(arr);



    return 0;
}
void initialize(circular *arr){
    arr->front = 1;
    arr->rear = 0;
}
void enqueue(circular *arr , char data){

    if(!isFull(*arr)){
        arr->rear =(arr->rear+1) % max;
        arr->data[arr->rear] = data;
    }
}
void dequeue(circular *arr){
    if(!isEmpty(*arr)){
        arr->front = (arr->front + 1) % max;
    }

}
int isEmpty(circular arr){
             
    return ((arr.rear + 1)% max == arr.front) ? 1: 0;

}
int isFull(circular arr){
    return ((arr.rear + 2) % max == arr.front) ? 1 : 0;


}
void display(circular arr){

    int count;
    for(count = arr.front;count != (arr.rear + 1) % max ; count = (count + 1) % max){

        printf("%c->" , arr.data[count]);
        
    }
        printf("\n");

}