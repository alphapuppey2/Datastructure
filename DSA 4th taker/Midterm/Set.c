#include<stdio.h>
#include<stdlib.h>
#define MAX 10


typedef int SET[8];

void AddElement(SET P, int element);
void DisplaySet(SET P);
void DeleteElement(SET P , int element);
void Initialize(SET P);
//Operations
SET * UnionSet(SET A , SET B);
SET * IntersectionSet(SET A , SET B);
SET * DifferenceSet(SET A , SET B);


int main(void){
    SET A; 
    SET B;

    SET* unionSet ;
    Initialize(A);
    Initialize(B);
    Initialize(unionSet);

    unionSet = UnionSet(A,B) ;

    DisplaySet(A);
    DisplaySet(B);
    // DisplaySet(*unionSet);

    return 0;
}

void Initialize(SET P){

   int x;
   for(x =0 ; x < MAX ; x++){
    P[x] = 0;
   }
}
void AddElement(SET P, int element){
    if(element < MAX){
        P[element] = 1;
    }
}
void DisplaySet(SET P){
    
    int x;
    for(x =0; x < MAX; x++){
        printf("%d" , P[x]);
    }
        printf("\n");
}
void DeleteElement(SET P , int element){
    if(element < MAX){
        P[element] = 0;
    }
}
SET * UnionSet(SET A , SET B){
    SET * C = (SET *)malloc(sizeof(SET));

    if(C != NULL){
        int x; 
        for(x =0; x < MAX; x++){
            (*C)[x] = A[x] | B[x];
        }
    }
    return C;
}
SET * IntersectionSet(SET A , SET B){

}
SET * DifferenceSet(SET A , SET B){

}
