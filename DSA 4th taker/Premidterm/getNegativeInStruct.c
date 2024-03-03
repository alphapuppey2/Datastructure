#include<stdio.h>
#include<stdlib.h>
#define MAX 10


typedef struct{
    int arr[MAX];
    int count;
}arrList;

arrList getAllNegative(arrList l);
void display(arrList l);
int main(void){

    arrList arr = {{2,-1,4,-7}, 4};

    arrList res = getAllNegative(arr);
    display(res);


    return 0;
}
void display(arrList l){
    int x;
    printf("%d ", l.count);
    for(x = 0 ; x < l.count ; x++){
        printf("%d ", l.arr[x]);
    }


}
arrList getAllNegative(arrList l){

    arrList promise;

    promise.count = 0;
    int x;
    for(x =0 ; x < l.count ; x++){
        if(l.arr[x] < 0){
            promise.arr[promise.count++] = l.arr[x];
            // promise.count++;
        }
    }
    return promise;
}