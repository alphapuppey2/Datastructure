#include<stdio.h>  
#include<stdlib.h>

typedef struct n {
    int data;
    struct n * l;
    struct n * r;
}tree ,* treeptr;


void initRoot(treeptr * root);
void insertL(treeptr* A);
void insertR(treeptr* A);
treeptr createNode(int value);

//display Order
void displayPost(treeptr head);
void displayPre(treeptr head);
void displayIn(treeptr head);

int main(void)  
{   // initialize the local variables.  
    treeptr root;

    initRoot(&root);

    insertL(&root);
    insertL(&root);
    insertL(&root);
    insertL(&root);

    printf("\nPostOrder\n");
    displayPost(root);
    printf("\nPreOrder\n");
    displayPre(root);
    printf("\nInOrder\n");
    displayIn(root);
    

    return 0;
}  
void displayPost(treeptr head){

    if(head != NULL){
        displayIn(head->l);
        displayIn(head->r);
        printf("%d " , head->data);
    }
}
void displayPre(treeptr head){

    if(head != NULL){
        printf("%d " , head->data);
        displayIn(head->l);
        displayIn(head->r);
    }
}
void displayIn(treeptr head){
    // display the left most par
    
    if(head != NULL){
        displayIn(head->l);
        printf("%d " , head->data);
        displayIn(head->r);
    }
}

void initRoot(treeptr * root){
    *root = NULL;
}
void insertL(treeptr * A){
    treeptr node;
    int val , cho;

    // left insert
    if(*A == NULL){
        printf("Value for node:");
        scanf("%d" , &val);
        *A = createNode(val);
        printf("END OF INSERT\n\n");
    }
    else{
        printf("asa nimo e butang ang bag o tree node sa |%d| node \n 1 : left\n 2 : right \n" , (*A)->data);
        scanf("%d" , &cho);
        if(cho == 1){
            insertL(&(*A)->l);
        }
        else if(cho == 2){
            insertL(&(*A)->r);
        }
        else{
            printf("error1\n\n");
        }
    }
}
void insertR(treeptr * A){
    treeptr node;
    int val , cho;
    // right insert
    if(A == NULL){
        scanf("%d" , &val);
        *A = createNode(val);
    }
    else{
        printf("Choose||\n 1 : left\n 2 : r \n");
        scanf("%d" , &cho);
        if(cho = 1){
            insertL(&(*A)->l);
        }
        else if(cho = 2){
            insertR(&(*A)->r);
        }
        
    }
}
treeptr createNode(int value){

    treeptr node = (treeptr)malloc(sizeof(tree));

    if(node != NULL){
        node->data = value;
        node->l = NULL;
        node->r = NULL;
    }

    return node;
}