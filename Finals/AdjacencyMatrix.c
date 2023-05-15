#include <stdio.h>
#define MAX 10
#define INFINITY 999

typedef int graph[MAX][MAX];


void initGraph(graph A ,int vertexSize);
void setWeightEdges(graph A , int source ,int destination,int weight ,int vertexSize);
void displayMatrix(graph A, int size);

int main(void){

    int vertexSize = 5;
    graph A;
    
    initGraph(A , vertexSize);
     setWeightEdges(A , 0 , 2, 5 ,vertexSize);
     setWeightEdges(A , 1 , 4, 2 ,vertexSize);
     setWeightEdges(A , 2 , 0, 4 ,vertexSize);
     setWeightEdges(A , 3 , 3, 10 ,vertexSize);
     setWeightEdges(A , 4 , 1, 8 ,vertexSize);
     setWeightEdges(A , 4 , 1, 8 ,vertexSize);

    displayMatrix(A , vertexSize);



    return 0;
}
void displayMatrix(graph A, int size){
    int x , z,c;

    printf("---------------WEIGHT------------\n");
    printf("%2c" , ' ');
    for(c = 0 ; c < size ; c++){
        printf("%2d " , c);
    }

    printf("\n");



    for(x = 0; x < size ; x++){
        printf("%2d" , x);
        for(z = 0; z < size ; z++){
            (A[x][z] == INFINITY) ? printf("%2c ", '-') : printf("%2d " , A[x][z]);
        }
        printf("\n");
    }
}

void initGraph(graph A , int vertexSize){
    int x ,z;

    for(x = 0 ; x < vertexSize ; x++){
        for (z = 0; z < vertexSize; z++)
        {
            /* code */
            A[x][z] = INFINITY;
        }
        
    }
}

void setWeightEdges(graph A , int source ,int destination,int weight ,int vertexSize){

    if(A[source][destination] == INFINITY){
        A[source][destination] = weight;
    }
    else{
        printf("connecting vertex to vertex is existed!\n");
    }

}