#include<stdio.h>
#include<stdlib.h>
#define MAX 15


typedef struct Partial{
    int list[MAX];
    int lastNDX;
}POT;

typedef struct SET{
    int elements[MAX];
    int lastNDX;
}SET;

void initialize(POT *root);
void insert(POT *root ,int data);
void display(POT root);
void deletemin(POT *root);

void heapify(POT *ROOT);
POT convertPOT(SET A);
void minHeapify(POT *root, int subRoot);
void maxHeapify(POT *root, int subRoot);

int main (void){
    POT tree;
    SET  A= {{3, 4, 9, 12, 15, 9, 10, 1, 5, 2},9};
    initialize(&tree);
    printf("[");
    insert(&tree ,3);
    insert(&tree ,4);
    insert(&tree ,9);
    insert(&tree ,12);
    insert(&tree ,15);
    insert(&tree ,9);
    insert(&tree ,10);
    printf(" ]\n");
    
    display(tree);
    printf("Inserted 3 elements \n");
    insert(&tree ,1);
    insert(&tree ,5);
    insert(&tree ,2);
    display(tree);


    printf("Deleting min\n");
    deletemin(&tree);
    display(tree);
    printf("Convert SET to POT\n");
    POT heap = convertPOT(A);
    display(heap);
    printf("heapify POT\n");
    heapify(&heap);
    display(heap);

    return 0; 
}
POT convertPOT(SET A){
    POT result;
    initialize(&result);

    printf("[");
    int el;
    for(el = 0 ; el <= A.lastNDX ; el++){
        insert(&result , A.elements[el]);
    }
    printf("]\n");
    return result;

    
}
void heapify(POT *ROOT){
    int parent;

    for(parent = (ROOT->lastNDX  - 1) / 2; parent >= 0 ; parent--){
        maxHeapify(ROOT , parent);
    }
}
void maxHeapify(POT *root, int subRoot){
     //Let the Left Child be the smallest child Since Left Child is always exists
        int Child = subRoot * 2 + 1;
        int temp;

        if(Child <= root->lastNDX){
          
        // If subRoot has 2 Children to compare who is the smallest or the largest
          if(Child + 1 <= root->lastNDX && root->list[Child] < root->list[Child + 1]){
            Child = Child+1;
          }
          

          if(root->list[Child] > root->list[subRoot]){
            temp = root->list[Child];
            root->list[Child] = root->list[subRoot];
            root->list[subRoot] = temp;

            minHeapify(root , Child);
          }
        }
        else{
          return;  
        }
}
void minHeapify(POT *root,int subRoot){

        //Let the Left Child be the smallest child Since Left Child is always exists
        int Child = subRoot * 2 + 1;
        int temp;

        if(Child <= root->lastNDX){
          
        // If subRoot has 2 Children to compare who is the smallest or the largest
          if(Child + 1 <= root->lastNDX && root->list[Child] > root->list[Child + 1]){
            Child = Child+1;
          }
          

          if(root->list[Child] < root->list[subRoot]){
            temp = root->list[Child];
            root->list[Child] = root->list[subRoot];
            root->list[subRoot] = temp;

            minHeapify(root , Child);
          }
        }
        else{
          return;  
        }
        //---------------------------------------------
        
       
}
void display(POT root){
    int x;

    for(x = 0 ; x <= root.lastNDX; x++){
        printf("%02d - ",root.list[x]);
    }
    printf("END-\n");
}
void initialize(POT *root){
    //meaning the tree is empty
    root->lastNDX = -1;
}
void deletemin(POT *root){
    int lastElem = root->lastNDX;
    int trav,LC,RC;
    int temp;
    if(root->lastNDX != -1){
        root->list[0] = root->list[lastElem]; 
        root->lastNDX--;
        for(trav = 0 ; trav <= root->lastNDX ;){
            LC = (2 *trav) + 1;
            RC = LC+1;
            // smallest = trav; 


            if(root->list[LC] < root->list[RC] ){

                temp = root->list[trav];
                root->list[trav] = root->list[LC];
                root->list[LC] = temp;

                trav = LC;
            }
            else if(root->list[RC] < root->list[LC] ){
                temp = root->list[trav];
                root->list[trav] = root->list[RC];
                root->list[RC] = temp;
                
                trav = RC;
            }
            else{
                trav = root->lastNDX + 1;
            }
            

        }
    }
}
void insert(POT *root ,int data){


    if(root->lastNDX + 1 < MAX){
        printf("%d, ", data);
        int temp , parent,child;

        root->lastNDX++;
        child = root->lastNDX;

        for(parent = (child - 1) / 2 ; child > 0 && root->list[parent] < data;){
            root->list[child] = root->list[parent];

            child = parent;
            parent = (parent - 1) / 2;
        }

            root->list[child] = data;
    }
}