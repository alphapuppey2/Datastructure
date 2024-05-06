#include<stdio.h>
#include<stdlib.h>
#define vertice 9
#define INF 100



typedef int matrix[vertice][vertice];

void floydAlgo(matrix x,matrix floyd);
void display(matrix s);
int main(void){

    matrix graph ={ { INF, 4, INF, INF, INF, INF, INF, 8, INF},
						{ 4, INF, 8, INF, INF, INF, INF, 11, INF },
						{ INF, 8, INF, 7, INF, 4, INF, INF, 2 },
						{ INF, INF, 7, INF, 9, 14, INF, INF, INF },
						{ INF, INF, INF, 9, INF, 10, INF, INF, INF },
						{ INF, INF, 4, 14, 10, INF, 2, INF, INF },
						{ INF, INF, INF, INF, INF, 2, INF, 1, 6 },
						{ 8, 11, INF, INF, INF, INF, 1, INF, 7 },
						{ INF, INF, 2, INF, INF, INF, 6, 7, INF } };
    matrix floyd;
    
    floydAlgo(graph,floyd);

    display(graph);
    // printf("-----------------\n");
    display(floyd);

    return 0;
}

void display(matrix s){
    int x , z ;

    for(x = 0 ; x < vertice; x++){
        for(z =0; z < vertice ; z++){
            if(s[x][z] != INF){
                printf("%-3d ", s[x][z]);
            }
            else{
                printf("%-3c " , 236);
            }
        }
        printf("\n");
    }
     printf("-----------------\n");
}
void floydAlgo(matrix x , matrix floyd){
    int i , j , k;

    for(i = 0; i < vertice ; i++){
        for(j = 0; j < vertice; j++){
            floyd[i][j] = x[i][j]; 
        }
    }
    for(i = 0 ; i < vertice ; i++){
        floyd[i][i] = 0;
    }
    display(floyd);
    for(k =0 ; k < vertice ; k++){
        for(i = 0; i < vertice; i++){
            for(j = 0; j <vertice ; j++){
                if((floyd[i][k] + floyd[k][j]) < floyd[i][j]){
                    floyd[i][j] = floyd[i][k] + floyd[k][j];
                }
            }
        }
    }
}