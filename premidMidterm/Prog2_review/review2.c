/*Delete all occurences*/



#include<stdio.h>
#include<stdlib.h>
#define MAX 5

typedef struct{
    char Elem[MAX];
    int Count;
}List;


void initCount(int *C);
void insert(char elem,List *node);
void display(List node);
void red();
void insertAt(int Pos ,char elem,List *node);


int main(void){

    List l;

    initCount(&l.Count);

    insert('u' , &l);
    insert('s' , &l);
    insert('c' , &l);
    insert('c' , &l);


    display(l);

    insertAt(3 , 'Z' , &l);

    display(l);



    return 0;
}
void red(){
    // printf("\033[0;31m");
    printf("\033[0;33m");
}
void reset(){
    printf("\033[0m");
}
void initCount(int * C){
    *C = 0;
}
void insert(char elem,List *node){
    if(node->Count < MAX){
        node->Elem[node->Count++] = elem;
    }
    else{
        printf("\033[1;31mThe Array is Full \033[1;0m\n");
        
    }
}
void insertAt(int Pos ,char elem,List *node){
    
    int x;
    
    if(node->Count < MAX){
        for(x = node->Count; x > Pos ; x-- ){
            node->Elem[x] = node->Elem[x-1];
        }
        node->Elem[x] = elem;
        node->Count++;
    }
    else{
        printf("\033[1;31mThe Array is Full \033[1;0m\n");
        
    }
}
void display(List node){
    int x;
    for(x =0; x < node.Count ;x++){
        printf("%c | " , node.Elem[x]);
    }
    printf("\n");
}