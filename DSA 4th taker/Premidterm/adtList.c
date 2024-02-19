/*Version 1*/

#include<stdio.h>
#include<stdlib.h>
#define MAX 10

typedef struct adtList
{
    int elem[MAX];
    int count;
}adList;

void initialize(adList * L);
adList initRetval();

void InsertFirst(adList *L , int Data);
void InsertN(adList *L , int idx,int Data);
void InsertLast(adList *L , int Data);
void InsertSorted(adList *L , int Data);

void DeleteFirst(adList* L);
void DeleteN(adList* L , int idx);
void DeleteLast(adList* L);
void DeleteOccurence(adList* L , int data);

void display(adList A);

int main(void){

    adList v1;
    initialize(&v1);
    InsertFirst(&v1 , 5);
    InsertFirst(&v1 , 10);
    InsertFirst(&v1 , 15);
    InsertFirst(&v1 , 20);
    InsertFirst(&v1 , 500);
    InsertFirst(&v1 , 240);

    InsertN(&v1 ,5, 1000000);
    display(v1);

    // DeleteFirst(&v1);
    // DeleteN(&v1 , 4);
    DeleteOccurence(&v1 , 500);
    display(v1);


    // adList sorted;
    // initialize(&sorted);
    // InsertSorted(&sorted , 100);
    // InsertSorted(&sorted , 101);
    // InsertSorted(&sorted , 102);

    // display(sorted);






    return 0;
}
//initialization

void initialize(adList * L){
        L->count = 0;
}
adList initRetval(){
    adList ret = {.count= 0};

    return ret;
}

//Insert
void InsertFirst(adList *L , int Data){

    /*This is Runs O(N) cause of shift */
    int shift;
    for(shift = L->count; shift > 0; shift--){
        L->elem[shift] = L->elem[shift - 1];
    }

    L->elem[shift] = Data;
    L->count++;
}
void InsertN(adList *L , int idx, int Data){

    /*This is Runs O(N) cause of shift */

    int shift;
   if(L->count < MAX){
     for(shift = L->count ; shift > 0 && shift < idx ; shift--){
        L->elem[shift] = L->elem[shift - 1];
    }
    L->elem[shift] = Data;
    L->count++;
   }
    

}
void InsertLast(adList *L , int Data){
    /*This is Runs O(1), no Loop */
    if(L->count < MAX){
        L->elem[L->count] = Data;
        L->count++;
    }

}
void InsertSorted(adList *L , int Data){
     int shift;

    for(shift = L->count - 1; shift > 0 && L->elem[shift] > Data; shift--){
        L->elem[shift + 1] = L->elem[shift];
    }

    L->elem[shift + 1] = Data;
    L->count++;

}
//Delete 
void DeleteFirst(adList* L){
    int dx;

   if(L->count > 0){
     for(dx = 0 ; dx < L->count ; dx++){
        L->elem[dx] = L->elem[dx + 1];
    }
    L->count--;
   }

}
void DeleteN(adList* L , int idx){

    int x;
    
    if(L->count > 0){
        for(x =idx ; x < L->count;x++){
            L->elem[x] = L->elem[x+1];
        }
        L->count--;
    }
    

}
void DeleteLast(adList* L){
    if(L->count > 0){
        L->count--;
    }
}
void DeleteOccurence(adList* L ,int data){
    int search ; 
    int traverse;

    for(search = 0; search < L->count && L->elem[search] != data; search++){}

    if(search < L->count){
        for(traverse = search ; traverse < L->count ; traverse++){
            L->elem[traverse] = L->elem[traverse + 1];
        }
        L->count--;
    }

}

void display(adList A){

    int x; 
    printf("---START OF ARRAY---\n");
    for(x =0; x < A.count ; x++){
        printf("%5sA[%d]: %2d\n" , " ",x, A.elem[x]);
    }
    printf("%1s---END OF ARRAY---\n" ," ");
}
