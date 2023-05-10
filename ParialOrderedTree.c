#include<stdio.h>
#include<stdlib.h>
#define SIZE 10


typedef struct POT
{
    int data[SIZE];
    int lastIndx;
}pot;


//functions
void initRoot(pot *);
void insert(pot *, int);
void display(pot x);


int main(void){
    
    pot root;


    // index 0 is always an Root val
    initRoot(&root);


    
    
    return 0;
}
void initRoot(pot * A){
       A->lastIndx = 0;
}
