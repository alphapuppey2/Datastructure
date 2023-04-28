#include <stdio.h>
#include<stdlib.h>

typedef struct n{
    int data;
    struct n* l;
    struct n* r;
}tree , *treeptr;

treeptr createNode(int data);
void initroot(treeptr *root);
void insert(treeptr *root , int val);
void displayIN(treeptr x);


int main(void){
    treeptr root;

    initroot(&root);



    return 0;
}
void initroot(treeptr *root){
    *root = NULL;
}
treeptr createNode(int data){
    
}
void insert(treeptr *root , int val){

}
void displayIN(treeptr x){

}
