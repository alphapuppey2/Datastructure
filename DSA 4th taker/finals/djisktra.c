#include<stdio.h>
#include<stdlib.h>

#define vertices 9
#define INFINITY 50

typedef int Matrix[vertices][vertices];
typedef int Spath[vertices];
typedef int set[vertices];



void initMatrix(Matrix *graph);
void display(Matrix s);
void displayDjisktra(Spath s);
void djisktraAlgo(Matrix graph);

int main(void){

    Matrix X ={ { 0, 4, 0, 0, 0, 0, 0, 8, 0 },
						{ 4, 0, 8, 0, 0, 0, 0, 11, 0 },
						{ 0, 8, 0, 7, 0, 4, 0, 0, 2 },
						{ 0, 0, 7, 0, 9, 14, 0, 0, 0 },
						{ 0, 0, 0, 9, 0, 10, 0, 0, 0 },
						{ 0, 0, 4, 14, 10, 0, 2, 0, 0 },
						{ 0, 0, 0, 0, 0, 2, 0, 1, 6 },
						{ 8, 11, 0, 0, 0, 0, 1, 0, 7 },
						{ 0, 0, 2, 0, 0, 0, 6, 7, 0 } };
    // initMatrix(&X);

    djisktraAlgo(X);

    // display(X);

    return 0;
}
void displayDjisktra(Spath s){

    int x;
    printf("%-7s %s\n","Vertex" , "Shortest Path from Source");
    for(x =0 ; x < vertices;x++){
        printf("%-8d%4d\n", x , s[x]);
    }

}
void djisktraAlgo(Matrix graph){
    
    int StartVertex = 0;

    //BitVector 
    set S;

    //distance Between starting Vertex to N
    Spath shortPath;
    int sc,scp,c,v , sentinelVertex;

    int min, minidx;
    //initializing S to be False ShortPath to be Infinity
    for(sc =0 ; sc < vertices ; sc++){
        S[sc] = 0;
    }
    for(scp = 0; scp < vertices ; scp++){
        shortPath[scp] = INFINITY;
    }

    shortPath[StartVertex] = 0;
    //find Shortest path for all vertices
    for(sentinelVertex = 0; sentinelVertex < vertices-1; sentinelVertex++){
         //find min distance Vertex
        min = INFINITY;
        for(c = 0 ; c < vertices ; c++){
            if(!S[c] && shortPath[c] <= min){
                min = shortPath[c];
                minidx = c;
            }
        }

        S[minidx] = 1;

    for(v =0 ; v < vertices ; v++){
        if(!S[v] && graph[minidx][v]
         && shortPath[minidx] != INFINITY 
         && shortPath[minidx] + graph[minidx][v] < shortPath[v]){
                shortPath[v] = shortPath[minidx] + graph[minidx][v];
        }
    }
    }
   
    displayDjisktra(shortPath);
}
void display(Matrix s){
    int x , z ;

    for(x = 0 ; x < vertices; x++){
        for(z =0; z < vertices ; z++){
            if(s[x][z] != INFINITY){
                printf("%-3d ", s[x][z]);
            }
            else{
                printf("%-3c " , 236);
            }
        }
        printf("\n");
    }
}
void initMatrix(Matrix *graph){
    
    int x ,z;

    for(x = 0; x < vertices ; x++){
        for(z = 0; z < vertices ; z++){
            (*graph)[x][z] = INFINITY;
        }
    }

    (*graph)[0][1] = 10; 
    (*graph)[0][3] = 30; 
    (*graph)[0][4] = 100; 
    (*graph)[0][1] = 10;

    (*graph)[1][50] = 10; 
    
    (*graph)[2][0] = 20; 
    (*graph)[2][4] = 10;
    
    (*graph)[3][2] = 20;
    (*graph)[3][4] = 60;

    
}
