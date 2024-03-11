#include<stdio.h>
#include<stdlib.h>

typedef unsigned char SET;
typedef enum {FALSE , TRUE} Boolean;

void insert(int);
void display(SET);
void Delete(SET*);
Boolean isMember(SET);


SET Union(SET, SET);
SET Intersection(SET, SET);
SET Difference(SET, SET);



int main(void){

    SET A = 168;
    SET B = 209;
    SET C = Difference(A , B);
    display(A);
    display(B);
    printf("---------\n");
    display(C);

    return 0;
}
void insert(int ndx){


}
void display(SET A ){
    SET mask;
    char bitSize = sizeof(char) * 8;
    int pos;

    for(pos = 1 ,mask = 1 << bitSize - 1 ;mask != 0 ;pos++, mask = mask >> 1){
        printf("%d" , (A & mask) != 0);
        if(pos % 4 == 0){
            printf(" ");
        }
    }
    printf("\n");

}
SET Union(SET A, SET B){
    return A | B;
}
SET Intersection(SET A, SET B){
    return A & B;
}
SET Difference(SET A, SET B){
    return A & ~B;
}