#include <stdio.h>
#include<stdlib.h>
#define MAX 10

typedef struct{
    int treeArray[MAX];
    int size;
}tree;

//function Prototype
void initialize(tree *A);
void createHeap(tree *A);
void swap(int *a , int *b);
void heapify(tree *A , int indx ,int  isMaxHeap);
void buildHeap(tree *A , int isMaxHeap);
void display(tree A);



int main(void){
    tree A;


    createHeap(&A);

    printf("before The heap :");
    display(A);

    buildHeap(&A , 1);
    printf("After Building The Max heap :");
    display(A);

    buildHeap(&A , 0);
    printf("After Building The Min heap :");
    display(A);

    



    return 0;
}
void buildHeap(tree *A , int isMaxHeap){
    for(int x = A->size / 2 - 1 ; x >= 0 ; x--){
        heapify(A , x ,isMaxHeap);
    }
}


void display(tree A){
    int x;
    for(x =0 ; x < A.size ; x++){
        printf("%d ", A.treeArray[x]);
    }
    printf("\n");

}
void createHeap(tree *A){
    
    int x;

    int givenArray[] = {4,10,3,5,1};
    A->size = sizeof(givenArray) / sizeof(int);

    for (x = 0; x < A->size; x++)
    {
        /* code */
        A->treeArray[x] = givenArray[x];
    }
    

}
void heapify(tree *A , int indx , int isMaxheap){
    
    if(A->size == 1){
        printf("Single element in a Heap");
    }
    else{
        int largest ,l,r;
        largest = indx;
        l = 2 * indx + 1; // left child of largest
        r = 2 * indx + 2; // right child of largest

        if(isMaxheap){
            if(l < A->size && A->treeArray[l] > A->treeArray[largest]){
                largest = l;
            }
            else if(r < A->size && A->treeArray[r] > A->treeArray[r]){
                largest = r;
            }
        }
        else{
            //minHeap
            if(l < A->size && A->treeArray[l] < A->treeArray[largest]){
                largest = l;
            }
            else if(r < A->size && A->treeArray[r] < A->treeArray[r]){
                largest = r;
            }
        }
        if(largest != indx){
            int temp = A->treeArray[indx];
            A->treeArray[indx] = A->treeArray[largest];
            A->treeArray[largest] = temp;

            heapify(A , largest , isMaxheap);
        }


    }
}
void swap(int *a , int *b){ 
    int temp = *a;
    a = b;
    *b = temp;

}
void initialize(tree *A){
    int x;

    for(x =0; x < MAX; x++){
        A->treeArray[x] = 0;
    }

    A->size = 0;



}