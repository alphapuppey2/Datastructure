#include<stdio.h>
#include<stdlib.h>

typedef struct n {
    struct n *LC;
    struct n *RC;
    int elem;
}*BinaryTree;


void initialize(BinaryTree* R);
void Display(BinaryTree R);
void insert(BinaryTree * R, int elem);
void delete(BinaryTree *R , int elem);
int isMember(BinaryTree R , int elem);

int main(void){

    BinaryTree Root;

    initialize(&Root);

    insert(&Root , 15);
    insert(&Root , 20);
    insert(&Root , 30);
    insert(&Root , 30);

    Display(Root);

    return 0;
}
int isMember(BinaryTree R , int elem){

    if(R != NULL){
        if(R->elem != elem){
            isMember(R->LC,elem);
            isMember(R->RC,elem);
        }
        else{
            return 1;
        }
    }
    else{
        return 0;
    }
}
void initialize(BinaryTree *R){
    *R = NULL;
}
void insert(BinaryTree * R, int elem){
    BinaryTree * trav;
    BinaryTree *check;
    int child;


    if(!isMember(*R,elem)){
        for(trav = R ; *trav != NULL;){
            printf("Inserting %d::\nNode: %d \n[0] Left Child\n[1] Right Child \n" ,elem, (*trav)->elem);
            scanf("%d", &child);
            if(child == 0){
                trav = &(*trav)->LC;
            }
            else{
                trav = &(*trav)->RC;
            }
        }
        *trav = (BinaryTree)malloc(sizeof(struct n));

        if(*trav != NULL){
            (*trav)->elem = elem;
            (*trav)->LC = (*trav)->RC = NULL;
        }
    }
    else{
        printf("the %d is found in the tree\n", elem);
    }
}
void Display(BinaryTree R){
    if(R != NULL){
        Display(R->LC);
        printf("%d ",R->elem);
        Display(R->RC);
    }
}
