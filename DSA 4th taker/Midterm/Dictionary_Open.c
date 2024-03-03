#include<stdio.h>
#include<stdlib.h>

#define MAX 10

typedef struct node {
    int Data;
    struct node* next;
}*OpenHash;

typedef OpenHash Dictionary[MAX];

int Hash(int x);
void display(Dictionary x);
void initDic(Dictionary x);
void insert(Dictionary m , int Data);
int isMember(Dictionary m , int Data);
void displayLL(OpenHash head);
void Delete(Dictionary s , int data);

int main(void){

    Dictionary List;
    initDic(List);

    insert(List , 0);
    insert(List , 13);
    insert(List , 20);
    insert(List , 28);
    insert(List , 30);
    insert(List , 33);
    insert(List , 45);
    insert(List , 48);
    insert(List , 108);

    Delete(List, 108);

    display(List);

    int member;

    member =  isMember(List , 99);

    if(member == 1){
        printf("The Element is Found\n");
    }
    else{
        printf("The Element is Not Found\n");
    }

    return 0;
}
void Delete(Dictionary s , int data){
    int ndx, cnt;
    ndx = Hash(data);
    OpenHash *trav , temp;
    for(trav = &s[ndx]; *trav != NULL && (*trav)->Data != data;trav = &(*trav)->next ){}

    if(*trav != NULL){
        temp = *trav;
        *trav = temp->next;
        printf("temp %d" , temp->Data);
        free(temp);
        printf("Deleted");
    }
}
int isMember(Dictionary m , int Data){
    int index = Hash(Data);

    OpenHash trav;

    for(trav = m[index]; trav != NULL && trav->Data != Data ; trav = trav->next){}

    return trav != NULL ? 1 : 0;
    
}
int Hash(int x){
    return x % 10;
}
void display(Dictionary x){
    int count;

    for(count = 0; count < MAX ; count++){
        printf("array[%d] : ",count);
        displayLL(x[count]);
    }

}
void displayLL(OpenHash head){
    while(head != NULL){
        printf("%d -> " , head->Data);
        head = head->next;
    }
    printf("NULL\n");

}
void insert(Dictionary m , int Data){
    int index = Hash(Data);

   OpenHash newnode = (OpenHash)malloc(sizeof(struct node));

    if(newnode != NULL){
        newnode->Data = Data;
        newnode->next = m[index];
        m[index] = newnode;
    }
}

void initDic(Dictionary x){

    int count;
    for(count = 0; count < MAX ; count++){
        x[count] = NULL;
    }

}