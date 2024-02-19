#include<stdio.h>
#include<stdlib.h>
#define MAX 10

typedef struct node
{
    int data;
    int next;
}Block;

typedef struct CursorBased
{
    Block node[MAX];
    int avail;
    
}VHeap;

typedef int List;

void initialRun(VHeap *heap);
void display(VHeap heap , List head);
void initList(List *head);
int allocSpace(VHeap *heap);
void deallocSpace(VHeap * heap ,int ndx);

void Insert(VHeap *heap , List *head ,int data);
void deletion(VHeap *heap , List *h , int data);

int main(void){

    List orig;
    VHeap heap;

    initialRun(&heap);
    initList(&orig);

    Insert(&heap , &orig , 50);
    Insert(&heap , &orig , 55);
    Insert(&heap , &orig , 57);

    display(heap , orig);

    Insert(&heap , &orig , 70);

    deletion(&heap , &orig , 55);

    display(heap , orig);



    return 0;
}
void deletion(VHeap *heap , List *h , int data){
    List *trav; 

    for(trav = h ; *trav != -1 && heap->node[*trav].data != data ; trav = &heap->node[*trav].next){}

    if(*trav != -1){
        List temp;
        temp = *trav;
        *trav = heap->node[temp].next;
        deallocSpace(heap,temp);
    }
}
void display(VHeap heap , List head){
    while (head != -1)
    {
        printf("%d ->" , heap.node[head].data);
        head = heap.node[head].next;
    }
    printf("NULL\n");
}
void Insert(VHeap *heap , List *head ,int data){
    //insert sorted

    int newnode = allocSpace(heap);

    if(newnode != -1){
        heap->node[newnode].data = data;
        heap->node[newnode].next = *head;
    }
    *head = newnode;

    

}
int allocSpace(VHeap *heap){
    int ret = heap->avail;
    if(ret != -1){
        heap->avail = heap->node[ret].next;
    }
    return ret;
}
void deallocSpace(VHeap * heap ,int ndx){

    if(ndx != -1){
        heap->node[ndx].next = heap->avail;
        heap->avail = ndx;
    }
}
void initList(List *head){
    *head = -1;
}
void initialRun(VHeap *heap){
    int x;
    for(x = 0; x < MAX ; x++){
        heap->node[x].next = x - 1;
    }
    heap->avail = x - 1;

}
