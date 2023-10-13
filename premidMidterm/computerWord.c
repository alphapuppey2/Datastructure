#include<stdio.h>
#include<stdlib.h>


typedef unsigned char SET;



void displayBits(SET res);
SET Union(SET A ,SET B);
SET Intersection(SET A , SET B);
SET Difference(SET A, SET B);


int main(void){
    // 128 | 64 | 32 | 16 | 8 | 4 | 2 | 1
    //  1  | 0  | 0  | 1  | 0 | 1 | 0 | 1
    SET A = 149;
    //  0  | 1  | 0  | 1  | 0 | 0 | 0 | 0

    //  1  | 0  | 0  | 1  | 0 | 1 | 0 | 1   A
    //  1  | 0  | 1  | 0  | 1 | 1 | 1 | 1   ~B
    SET B = 80;

    SET unionset = Union(A, B);
    SET interSect = Intersection(A , B);
    SET defSet = Difference(A , B);
    printf("A : %d\n" , A);
    printf("B : %d\n" , B);

    printf("SET A:: ");
    displayBits(A);
    printf("SET B:: ");
    displayBits(B);


    printf("Union SET :: ");
    displayBits(unionset);
    printf("Intersection SET :: ");
    displayBits(interSect);
    printf("difference SET :: ");
    displayBits(defSet);

    return 0;
}

void displayBits(SET res){

    char bitSize = sizeof(char) * 8;
    int mask, pos;
    //                  1000 0000                    0100 0000
    for(pos = 1, mask = 1 << bitSize - 1; mask != 0 ; mask = mask >> 1 , pos++){
        printf("%d" , (res & mask) != 0);
        if(pos == 4){
            printf(" ");
        }
    }
    printf("\n");


}
SET Union(SET A ,SET B){
    
    return  A | B;

}
SET Intersection(SET A , SET B){
    
    return A & B;

}
SET Difference(SET A, SET B){

    return A & ~B;

}
int isMember(SET A , int pos){
    
}
