#define MAX 10;

typedef struct queue{
  int item[MAX];
  int front;
  int rear;
}*Queue;

typedef struct node{
  int vertex;
  struct node *next;
}*Node;

typedef struct graph{
  int numVertices;
  int *visited;
  struct node **adjacent
}*Graph;


Graph createGraph(int vertices){
  Graph ret = malloc(sizeof(struct graph));
  ret->numVertices = vertices;
  ret->visited = calloc(vertices,sizeof(int));
  ret->adjacent = calloc(vertices,sizeof(Node));
  return ret;
}

void addEdge(Graph A, int s, int d){
  Node temp = calloc(1,sizeof(struct node));
  temp->vertex = d;
  A->adjacent[s] = temp;
  
  temp = calloc(1,sizeof(struct node));
  temp->vertex = s;
  A->adjacent[d] = temp;
}

Queue createQ(){
  Queue Q = malloc(sizeof(struct queue));
  Q->front = -1;
  Q->rear = -1;
  return Q;
}

void enqueue(Queue Q, int x){
  if(Q->rear == MAX-1)
    return;
  if(Q->front == -1)
    Q->front = 0;
  Q->rear++;
  Q->item[Q->rear] = x;
}

int dequeue(Queue Q){
  int val;
  
  if(Q->front == -1)
    return -1;
    
  val = Q->item[Q->front];
  Q->front++;
  
  if(Q->front > Q->rear)
    Q->front = Q->rear = -1;
    
  return val;
}

void bfs(Graph A, int s){
  Queue Q = createQ(); 
  int currentVertex, adjVertex;
  
  A->visited[s] = 1;
  enqueue(Q, s);
  
  while(Q->rear != -1){
    //print
    currentVertex = dequeue(Q);
    Node temp = A->adjacent[currentVertex];
    
    while(temp != NULL){
      adjVertex = temp->vertex;
      if(A->visited[adjVertex] == 0){
        A->visited[adjVertex] = 1;
        enqueue(Q, adjVertex);
      }
      temp = temp->next;
    }
  }
}



int main(){
  Graph A = createGraph(4);
  addEdge(A,0,1);
  return 0;
}
