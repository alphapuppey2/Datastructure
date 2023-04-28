#include<stdio.h>
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
void deleteNode(treeptr *rootN , int val);


int main(void){
    treeptr root;
    int delval;
    char resp;

    initroot(&root);

    insert(&root , 5);
    insert(&root , 3);
    insert(&root , 7);
    insert(&root , 1);
    insert(&root , 9);
    insert(&root , 4);

    printf("Do you want to Delete Node:: y ");
    resp = 'y';
    // scanf("%c" , &resp);
    if( resp == 'y'){
        printf("What Value : 3");
        delval = 3;
        // scanf("%d" , &delval);

        deleteNode(&root , delval);
    }
    displayIN(root);

    return 0;
}
void deleteNode(treeptr *rootN , int val){
    treeptr temp;
    if(*rootN != NULL){
        if((*rootN)->data == val){
        //delete Here
        temp = *rootN;

        //setting the ptr to its right child
        *rootN = (*rootN)->r;

        // set the remaining child of DeleteNode to a New *rootN value/address
        /*
                         5                                              5
                   3          7           NEW value=>            4             7
               1       4           9                         1                       9
        
        */

        (*rootN)->l = temp->l;
        }
        else{
            //traverse until val == (*rootN)->data
            deleteNode(&(*rootN)->l , val);
            deleteNode(&(*rootN)->r , val);
        }

        free(temp);
    }

}
void initroot(treeptr *root){
    *root = NULL;
}
treeptr createNode(int data){
    
    treeptr node = (treeptr)malloc(sizeof(tree));
    if(node != NULL){
        node->data = data;
        node->l = node->r = NULL;
    }

    return node;
}
void insert(treeptr *root , int val){

    if(*root == NULL){
        *root =  createNode(val);
    }
    else{
        if((*root)->data > val){
            insert(&(*root)->l , val);
        }
        else if((*root)->data < val){
            insert(&(*root)->r , val);
        }
    }

}
void displayIN(treeptr x){

    if(x != NULL){
        displayIN(x->l);
        printf("%d " , x->data);
        displayIN(x->r);
    }
}
