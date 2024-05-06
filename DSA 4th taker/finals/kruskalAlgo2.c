#include<stdio.h>
#include<stdlib.h>
#define vertexSize 6
#define edgeSize vertexSize*vertexSize


typedef int SET[vertexSize];
typedef int adjMatrix[vertexSize][vertexSize];
typedef struct Eg
{
    int u;
    int v;
    int weight;
}edgeT;
typedef struct {
    edgeT edge[edgeSize];
    int edgeCount;
    int minCost;
}kruskalGraph;


kruskalGraph kruskalAlgo(adjMatrix sample);
void sort(kruskalGraph *G);
void  displayKruskal(kruskalGraph g);

int main(void){
    adjMatrix Sample = { { 0, 4, 4, 0, 0, 0},
                         { 4, 0, 2, 0, 0, 0},
                         { 4, 2, 0, 3, 4, 2},
                         { 0, 0, 3, 0, 3, 0},
                         { 0, 0, 4, 3, 0, 3},
                         { 0, 0, 2, 0, 3, 0}};

    kruskalGraph graph = kruskalAlgo(Sample);

    displayKruskal(graph);

    printf("Last In Main\n");

    return 0;
}
void  displayKruskal(kruskalGraph g){
    int x;
    int totalCost =0;
    for(x =0 ; x < g.edgeCount ; x++){
        printf("(%d,%d)%d\n", g.edge[x].u,g.edge[x].v,g.edge[x].weight);
        totalCost += g.edge[x].weight;
    }
    printf("Total Cost: %d\n",totalCost);
}
kruskalGraph kruskalAlgo(adjMatrix sample){
    /*
        initialize Disjoint to -1
        Sort all edges first from lowest to highest weight

        
    */
    SET disjoint;
    kruskalGraph graph;
    kruskalGraph kruskal;

    kruskal.edgeCount = 0;
    kruskal.minCost = 0;
    int sentinelEdge=0;

    int x,z;
    for(x =0; x < vertexSize ; x++){
        disjoint[x] = x;
    }
    graph.edgeCount = 0;
    for(x = 0; x < vertexSize ;x++){
       for(z =0 ; z < vertexSize ; z++){
         if(sample[x][z] != 0){
            graph.edge[graph.edgeCount].u = x;
            graph.edge[graph.edgeCount].v = z;
            graph.edge[graph.edgeCount].weight = sample[x][z];
            graph.edgeCount++;
         }
       }
    }
    // printf("ELIST \n");

    edgeT edgeTemp;
    for(x =1 ; x < graph.edgeCount; x++){
        for(z = 0 ; z < graph.edgeCount-1; z++){
            if(graph.edge[ z ].weight > graph.edge[z+1].weight){
                edgeTemp = graph.edge[z];
                graph.edge[z] = graph.edge[z+1];
                graph.edge[z + 1] = edgeTemp;
            }
        }
    }
    int uRep, vRep,uni;
    //NOTE :: 
    for(sentinelEdge = 0 ; sentinelEdge < graph.edgeCount; sentinelEdge++){
        //find Representative of u
            uRep = disjoint[graph.edge[sentinelEdge].u];
        //find Represenstative of v
            vRep = disjoint[graph.edge[sentinelEdge].v];
            if(uRep != vRep){
                kruskal.edge[kruskal.edgeCount] = graph.edge[sentinelEdge];
                kruskal.edgeCount++;
                // join Higher of vRep representative to uRep
                for(uni = 0 ; uni < vertexSize; uni++){
                    if(disjoint[uni] == vRep){
                        disjoint[uni] = uRep;
                    }
                }

            }
    }

    return kruskal;
}
void sort(kruskalGraph *G){
    int x,z;
    edgeT edgeTemp;
    for(x =1 ; x < G->edgeCount; x++){
        for(z = 0 ; z < G->edgeCount-1; z++){
            if(G->edge[ z ].weight > G->edge[z+1].weight){
                edgeTemp = G->edge[z];
                G->edge[z] = G->edge[z+1];
                G->edge[z + 1] = edgeTemp;
            }
        }
    }
}

