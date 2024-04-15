#include<stdio.h>
#include<stdlib.h>
#define MAX 10


typedef struct Partial{
    int list[MAX];
    int lastNDX;
}POT;

typedef struct SET{
    int elem[MAX];
    int lastElem;
}SET;
void initialize(POT *root);
void insert(POT *root ,int data);
void display(POT root);
POT heapify(SET ROOT);
void minHeapify(POT *root, int SubRoot);
void deletemin(POT *root);

int main (void){
    POT tree;
    SET A = {{1,4,7,8,2,3,5,6,0,9},9};
    initialize(&tree);
    
    insert(&tree ,1);
    insert(&tree ,4);
    insert(&tree ,7);
    insert(&tree ,8);
    insert(&tree ,2);
    insert(&tree ,3);
    insert(&tree ,5);
    insert(&tree ,6);
    insert(&tree ,0);
    insert(&tree ,9);

    display(tree);

    printf("Deleting min\n");
    deletemin(&tree);
    display(tree);
    printf("MinHeapify\n");
    POT conversion;
    conversion = heapify(A);

    display(conversion);
    
    

    return 0; 
}
POT heapify(SET ROOT){

    POT result;
    initialize(&result);

    int el;
    for(el = 0 ; el <= ROOT.lastElem ; el++){
        insert(&result , ROOT.elem[el]);
    }

    return result;
}
void minHeapify(POT *root,int subRoot){

        //Choose Among the Child of the subRoot who is the smallest or the largest
        int Child = subRoot * 2 + 1;
        int temp;


        // If subRoot has 2 Children to compare who is the smallest or the largest
        if(Child + 1 < root->lastNDX){
            Child = root->list[Child] < root->list[Child+1] ? Child : Child + 1;
        }
        if(root->list[Child] < root->list[subRoot]){
            temp = root->list[Child];
            root->list[Child] = root->list[subRoot];
            root->list[subRoot] = temp;

            minHeapify(root , temp);
        }

        //---------------------------------------------
        
       
}
void display(POT root){
    int x;

    for(x = 0 ; x <= root.lastNDX; x++){
        printf("indx[%d]: %d\n", x,root.list[x]);
    }
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
        for(trav = 0 ; trav > root->lastNDX ;){
            LC = (2 *trav) + 1;
            RC = (2 *trav) + 2;
            // smallest = trav; 


            if(root->list[LC] > root->list[RC] ){

                temp = root->list[trav];
                root->list[trav] = root->list[LC];
                root->list[LC] = temp;

                trav = LC;
            }
            else if(root->list[RC] > root->list[LC] ){
                temp = root->list[trav];
                root->list[trav] = root->list[RC];
                root->list[RC] = temp;
                
                trav = RC;
            }
            else{
                trav = root->lastNDX;
            }
            

        }
    }
}
void insert(POT *root ,int data){

    int temp , parent,child;
    


    if(root->lastNDX + 1 < MAX){

        root->lastNDX++;
        child = root->lastNDX;
        for(parent = (root->lastNDX - 1) / 2 ; child > 0 && root->list[parent] < data;){
            root->list[child] = root->list[parent];

            child = parent;
            parent = (parent - 1) / 2;
        }

            root->list[child] = data;

    }
}