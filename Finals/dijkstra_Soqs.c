#include <stdio.h>
#include <stdlib.h>
#define infinity 9999
#define MAX 10


typedef int node;
typedef int graph[MAX][MAX];


void initialized(graph A);
void dijkstra(graph list ,graph cost,int distance[MAX], int n , int start );
void display(int rep[MAX] , int n, int start);

int main(void){


    graph matrix;
    graph cost;

    int distance[MAX];

    node start = 0; // node source => connect node to another
    node n = 3;     // total Vertex


    initialized(matrix);
    //all edges has 0 weight

    matrix[0][2] = 1;
    matrix[0][3] = 2;
    
    matrix[1][2] = 2;
    matrix[1][5] = 3;
    
    matrix[2][0] = 1;
    matrix[2][1] = 2;
    matrix[2][3] = 1;
    matrix[2][4] = 3;



    
    dijkstra(matrix , cost ,distance, n,start);
    
    display( distance , n , start);



    return 0;
}
void display(int rep[MAX] , int n , int start){

    int x , z;
    printf("The Graph:: \n");

    for(x = start; x < n; x++)
    {
        if(x != start){
            printf("distance from source to %d :: %d\n" ,x ,rep[x]);
        printf("\n");
        }
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
/*
    n is the total vertex in a graph
    distance[] is used to know the distance between source to vertex
*/
void dijkstra(graph G ,graph costs, int distance[MAX],int n , int start ){


    int pred[MAX];

    int visited[MAX];
    int count, minDistance , nextNode;
    int z,x;

    // costMatrix
    for (z = 0; z < n; z++)
    {
        for (x = 0; x < n; x++)
        {
            //if edge weight == 0
            costs[z][x] = (G[z][x] == 0) ? infinity :  G[z][x];

        }
        
    }

    //initial state for dijkstra algorithm
    // start within the start Node / the source Node
    for (z = 0; z < n; z++)
    {
        /* code */
        distance[z] = costs[start][z];
        pred[z] = start;
        visited[z] = 0;
    }

    distance[start] = 0; // source pointing itself is always 0
    visited[start] = 1; // we are visited the vertex which is the Source Node

    //this is where we start comparing other vertex
    //count = 1; 

    for(count = 1; count <= n ; count++){
        //finding the min weight of a nextnode 
        for(z =0;z < n ;z++ ){
            if(distance[z] < minDistance && !visited[z]){
                minDistance = distance[z];
                nextNode = z;
            }
        }
        // track in visiting each node from the source
        visited[nextNode] = 1;
        for (z = 0; z < n; z++)
        {
            /* code */
            if (!visited[z])
            {
               if(minDistance + costs[nextNode][z] < distance[z]){
                 /* distance is for the source to other vertex */
                distance[z] = minDistance + costs[nextNode][z];
                pred[z] = nextNode;
               }
            }
        } 
    }  
}






