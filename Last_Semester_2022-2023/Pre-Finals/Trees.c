#include <stdio.h>
#include<stdlib.h>

typedef struct node{
    int data;
    struct node* left;
    struct node* right;
} *tree;

void initTree(tree*);
void display(tree);
void preorder(tree);
void postorder(tree);
void inorder(tree);


int main(void){

    tree treeComp;
    initTree(&treeComp);

    //root
    treeComp = (tree)malloc(sizeof(struct node));
    treeComp->data = 1;
    //1st Level 
    treeComp->left = (tree)malloc(sizeof(struct node));
    treeComp->left->data = 12;
    treeComp->right = (tree)malloc(sizeof(struct node));
    treeComp->right->data = 9;
    treeComp->right->left = treeComp->right->right = NULL;
    //2nd Level
    treeComp->left->left = (tree)malloc(sizeof(struct node));
    treeComp->left->left->data = 5;
    treeComp->left->left->left = NULL;
    treeComp->left->left->right = NULL;

    treeComp->left->right = (tree)malloc(sizeof(struct node));
    treeComp->left->right->data = 6;
    treeComp->left->right->left = NULL;
    treeComp->left->right->right = NULL;


    printf("PreOrder\n");
    preorder(treeComp);
    printf("NULL\n");

    printf("Postorder\n");
    postorder(treeComp);
    printf("NULL\n");

    printf("inorder\n");
    inorder(treeComp);
    printf("NULL\n");



    return 0;
}
void initTree(tree *h){
    *h = NULL;
}

void display(tree h){
    // post- pre- in- order DISPLAYING the Node
    if(h != NULL){
        printf("%d ->" , h->data);
    }
}
void preorder(tree h){
    if(h == NULL){
        return ;
    }
    display(h);
    preorder(h->left);
    preorder(h->right);
}
void postorder(tree h){
    if(h == NULL){
        return ;
    }
    postorder(h->left);
    postorder(h->right);
    display(h);

}
void inorder(tree h){
    if(h == NULL){
        return ;
    }
    inorder(h->left);
    display(h);
    inorder(h->right);
}


