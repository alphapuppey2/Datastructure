#include<stdio.h>
#include<stdlib.h>

typedef struct node{
  int vertex;
  struct node *next;
}*NODE;

typedef struct list{
  int count;
  int *visited;
  struct node **adjacent;
}*GRAPH;





GRAPH createGraph(int vertices){
  GRAPH ret = malloc(sizeof(struct list));
  ret->count = vertices;
  ret->visited = calloc(vertices,sizeof(int));
  ret->adjacent = calloc(vertices,sizeof(NODE));
  return ret;
}


void addEdge(GRAPH A, int s, int d){
  NODE temp = malloc(sizeof(struct node));
  temp->vertex = d;
  temp->next = A->adjacent[s];
  A->adjacent[s] = temp;
}

void DFS(GRAPH A, int s){
  NODE trav = A->adjacent[s]; 
  NODE temp = trav;
  int conn;
  
  A->visited[temp] = 1;
  printf("%d") = temp;
  
  while(temp != NULL){
    conn = temp->vertex;
    if(A->visited[conn] == 0){
      DFS(A, conn);
    }
    temp = temp->next
  }
}


int main() {
  int C[4][2] = {0,1,0,2,1,2,2,3};
  GRAPH A = createGraph(4);
  addEdge(A, 0, 1);
}
