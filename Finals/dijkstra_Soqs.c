#include <stdio.h>
#include <stdlib.h>
#define infinity 9999
#define MAX 10


typedef int node;
typedef int graph[MAX][MAX];


void initialized(graph A);
void dijkstra(int graph[MAX][MAX] , int n , int start );
void display(graph rep , int n, int start);

int main(void){


    graph a;

    node start = 0; // first vertex
    node n = 7;     // last vertex


    initialized(a);

    // a[0][0] = 0;
    // a[0][1] = 0;
    // a[0][2] = 0;
    // a[0][3] = 0;
    // a[0][4] = 0;
    // a[0][5] = 0; 
    // a[0][6] = 0; 

    display(a , n , start);



    return 0;
}
void display(graph rep , int n , int start){

    int x , z;
    printf("The Graph:: \n");

    for(x = start; x < n; x++){
        for ( z = 0; z < n; z++)
        {
            printf("Graph[%d][%d] :: %d\n" ,x,z, rep[x][z]);
        }
        printf("\n");
    }



    // for (z=0; z < n; z++)
    // {
    //     if(z != start){
    //         printf("Souir")
    //     }
    // }
    


}
void initialized(graph A){
    int z,x;

    for(z = 0; z < MAX ; z++){
        for (x = 0; x < MAX; x++)
        {
            A[z][x] = 0;
        }
        
    }


}
void dijkstra(graph G , int n , int start ){


    graph costs;
    graph distance;
    graph pred;

    int visited[MAX];
    int count, minDistance , nextNode;
    int z,x;

    // Weights
    for (z = 0; z < n; z++)
    {
        for (x = 0; x < n; x++)
        {
            if(G[z][x] == 0){
                costs[z][x] = infinity;
            }
            else{
                costs[z][x] = G[z][x];
            }
        }
        
    }
    




}



