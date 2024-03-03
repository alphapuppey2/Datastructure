#include <stdio.h>
#include<stdlib.h>



int * getAllNegative(int [], int size);
void display(int [], int size);


int main(void){

    int A[] = {2,-1,3,-7};

    int * result = getAllNegative(A , sizeof(A) / sizeof(int));


    display(result ,result[0] + 1);

    return 0;
}

void display(int arr[] , int size){

    int x;
    for(x =0; x < size ; x++){
        printf("%d ", arr[x]);
    }

}

int * getAllNegative(int arr[], int size){

    int *res = (int *)malloc(sizeof(int) * size);

    if(res != NULL){
        int x,y =1;

        for(x =0 ; x < size ; x++){
            if (arr[x] < 0){
                res[++res[0]] = arr[x]; 
            }
        }
        // res[0] = y - 1;
    }

    return res;
}
