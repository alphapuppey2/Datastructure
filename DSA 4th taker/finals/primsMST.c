#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define vertices 6
#define INF INT_MAX


typedef int adjMatrix[vertices][vertices];
typedef int Vertex;
typedef int SET[vertices];

typedef struct n {
    int u;
    int v;
    int weight;
}edgeType;
typedef struct M{
    edgeType edge[vertices];
    int count;
    int Cost; 
}primStruct;

void display(adjMatrix s);
void initMatrix(adjMatrix mx);
void initSet(SET unv);
void findDifference(SET Difference,SET universal);
primStruct primsAlgo(Vertex Start , adjMatrix matrix);
void displayPrims(primStruct s);

int main(void){

    adjMatrix matrix;
    Vertex StartingPoint = 0;
    initMatrix(matrix);
    primStruct primo = primsAlgo(StartingPoint , matrix);
    display(matrix);
    displayPrims(primo);
    return 0;
}
void displayPrims(primStruct s){

    int x;
    for(x = 0; x < s.count ; x++){
        printf("Edge : %d - %d Weight: %d\n" , s.edge[x].u , s.edge[x].v , s.edge[x].weight );
    }
    printf("total Cost :: %d\n", s.Cost);

}

primStruct primsAlgo(Vertex Start , adjMatrix matrix){
    //minimum Spanning Tree

    primStruct primo;
    primo.count=0;
    primo.Cost = 0;
    SET universal;
    int x,z,edges = 0;
    int TotalMinCost = 0;
    int u,v;
    int minPairCost;

    for(x =0 ; x < vertices ; x++){
        universal[x] = 0;    
    }
        universal[Start] = 1;
        //0 meaning unvisited 1 for visited
       
        edges++;
    for(;edges < vertices;edges++){
        minPairCost = INF;
        u = v = 0;
        //universal is a vertex that is visited or Not
        for(x = 0 ; x < vertices ; x++){
            if(universal[x]){
                for(z = 0; z < vertices ;z++){
                    if(!universal[z] && matrix[x][z]){
                        if(minPairCost > matrix[x][z]){
                            u = x;
                            v = z;
                            minPairCost = matrix[x][z];   
                        }
                    }
                }
            }
        }   
                if(minPairCost != INF){
                    primo.edge[primo.count].u = u;
                    primo.edge[primo.count].v = v;
                    primo.edge[primo.count].weight = matrix[u][v];
                    primo.Cost += minPairCost; 
                    primo.count++;
                    universal[v] = 1;
                }
    }
    return primo;
}

void initMatrix(adjMatrix mx){
    int x,z;

    for(x = 0; x < vertices ; x++){
        for(z = 0 ; z < vertices ; z++){
            mx[x][z] = INF;
        }
    }
    // adjMatrix Sample = { { 0, 2, 0, 6, 0 },
    //                     { 2, 0, 3, 8, 5 },
    //                     { 0, 3, 0, 0, 7 },
    //                     { 6, 8, 0, 0, 9 },
    //                     { 0, 5, 7, 9, 0 } };


    //     memcpy(mx , Sample , sizeof(adjMatrix));
    mx[0][1] = 1;
    mx[0][2] = 5;
    mx[0][3] = 4;
    mx[0][4] = 6;
    mx[0][5] = 5;

    mx[1][0] = 1;
    mx[1][2] = 5;
    mx[1][5] = 6;
    
    mx[2][0] = 5;
    mx[2][1] = 5;
    mx[2][3] = 2;
    
    mx[3][0] = 4;
    mx[3][2] = 2;
    mx[3][4] = 1;
    
    mx[4][0] = 6;
    mx[4][3] = 1;
    mx[4][5] = 3;
    
    mx[5][0] = 5;
    mx[5][1] = 6;
    mx[5][4] = 3;
}

void initSet(SET unv){
    int x ;
    for(x = 0; x < vertices ; x++){
        unv[x] = INF;
    }
    
}
void display(adjMatrix s){
    int x , z ;

    for(x = 0 ; x < vertices; x++){
        for(z =0; z < vertices ; z++){
            if(s[x][z] != INF){
                printf("%-3d ", s[x][z]);
            }
            else{
                printf("%-3c " , 236);
            }
        }
        printf("\n");
    }
}