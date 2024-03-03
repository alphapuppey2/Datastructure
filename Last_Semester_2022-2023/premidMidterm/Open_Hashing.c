#include <stdio.h>
#include<stdlib.h>
#define MAX 10

typedef struct n{
    int data;
    struct n* link;
}*list;

typedef list Dictionary[MAX];


int hash(int x);
void initDic(Dictionary * l);
void insert(Dictionary *l , int data);
void delete(Dictionary *l , int data);
void findGroup(Dictionary l , int x);

void display(Dictionary l);


int main (void){
    
    Dictionary l;
    initDic(&l);



    
    insert(&l , 19);
    insert(&l , 129);
    insert(&l , 146);
    insert(&l , 515);
    insert(&l , 11);
    insert(&l , 10);

    display(l);

    printf("\nDELETED SOMETHING\n\n");

    delete(&l , 129);
    display(l);

    findGroup(l , 140);




    
    
    
    return 0;
}
void findGroup(Dictionary l , int x){
    
    int pos = hash(x);
    list trav;

    for(trav = l[pos]; trav != NULL && trav->data != x; trav = trav->link){}

    if(trav == NULL){
        printf("could not Find the Group of %d" , x);
    }
    else{
        printf("the group of %d is in group %d " , x , hash(x));
    }
    
}
void display(Dictionary l){
    int c;
    list trav;
    for(c = 0; c < MAX; c++){
            printf("[%d] : " , c);
        for(trav = l[c] ; trav != NULL ; trav = trav->link){
            printf("%d ->", trav->data);
        }
            printf("NULL\n");
    }
}
int hash(int x){
    return x % MAX;
}
void initDic(Dictionary * l){
    int x;

    for(x =0; x < MAX ; x++){
        (*l)[x] = NULL;
    }
}
void insert(Dictionary *l , int data){
    int pos = hash(data);
    list newnode;
    list *trav = &(*l)[pos];

    for(; *trav != NULL ; trav = &(*trav)->link){}

    newnode = (list)malloc(sizeof(struct n));

    if(newnode != NULL){
        newnode->data = data;
        newnode->link = *trav;
        *trav = newnode;
    }
    

}

void delete(Dictionary *l , int data){
    int pos = hash(data);
    list *trav = &(*l)[pos];
    list temp;

    for(; *trav != NULL && (*trav)->data != data ; trav = &(*trav)->link){}

    if(*trav != NULL){
        temp = *trav;
        *trav = temp->link;

        free(temp);
    }

}