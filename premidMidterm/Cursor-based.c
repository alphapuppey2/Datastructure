#include<stdio.h>
#include<stdlib.h>
#define MAX 10

typedef struct n{
    char data;
    int link;
}node;
typedef struct{
    node Box[MAX];
    int avail;
}VirtualHeap;

typedef int List;


void InitList(VirtualHeap *V);
int AllocSpace(VirtualHeap *V);
void DeallocSpace(VirtualHeap *V , int dx);

void display(VirtualHeap V);
void insertFirst(List *head , VirtualHeap *V ,char Data);
void displayList(VirtualHeap V, List head );

void deleteFirst(List *head , VirtualHeap *V);
void deleteSpecific(List * head , VirtualHeap* V , int elem);




int main(void){
    VirtualHeap Heap;
    List head = -1;

    InitList(&Heap);


    insertFirst(&head , &Heap , 'A');
    insertFirst(&head , &Heap , 'B');
    insertFirst(&head , &Heap , 'C');
    insertFirst(&head , &Heap , 'C');
    insertFirst(&head , &Heap , 'C');

    // display(Heap);


    displayList(Heap , head);

    deleteFirst(&head , &Heap);
    deleteFirst(&head , &Heap);
    deleteFirst(&head , &Heap);

    displayList(Heap , head);

    return 0;
}
void deleteFirst(List *head , VirtualHeap *V){
    int temp = *head;
    *head = V->Box[*head].link;

    DeallocSpace(V , temp);
}
void deleteSpecific(List * head , VirtualHeap* V , int elem){}

void insertFirst(List *head , VirtualHeap *V ,char Data){

    int newnode = AllocSpace(V);

    if(newnode != -1){
        V->Box[newnode].data = Data;
        V->Box[newnode].link = *head;
       *head = newnode;
    }
}
void displayList(VirtualHeap V, List head ){

    for(; head != -1 ; head = V.Box[head].link){
        printf("%c-> " , V.Box[head].data);
    }
        printf("NULL\n");
}
void display(VirtualHeap V){
    int x;

    for(x =0 ; x<MAX ; x++){
        printf("Link for mem %d ::  %d\n" , x , V.Box[x].link);
    }
}
void InitList(VirtualHeap *V){
    int x;
    for(x =1; x < MAX; x++){
        V->Box[x-1].link  = x;
    }
    V->Box[x-1].link = -1;
    V->avail = 0;

}



int AllocSpace(VirtualHeap *V){
    int ndx = V->avail;

    if(ndx != -1){
        V->avail = V->Box[ndx].link;
    }
    return ndx;
}
void DeallocSpace(VirtualHeap *V , int dx){
   if(dx != -1){
    V->Box[dx].link = V->avail;
    V->avail = dx;
   }
}