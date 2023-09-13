#include<stdio.h>
#include<stdlib.h>
#define MemorySize 10


typedef struct name{
    char First[24];
    char Last[16];
    char Middle;
}nameType;
typedef struct record{
    nameType name;
    char Course[8];
    int ID;
    int yrlvl;
}record;
typedef struct{
    record enrollee;
    int Link;
}node;
typedef struct Virtual{
    node student[MemorySize];
    int Available;
}Heap , *VrtHeap;


typedef int head;

/* 
    Heap is Version 1 while VrtHeap serve as Version 2  
    --head that Points to the first Node in the List--
*/

void initializeHeap(Heap * Memory);
void initLists(head* ndx);
void insert(head* ndx , Heap * vh);
void delete(head* ndx ,Heap * vh ,int ID);

int memAlloc(Heap *V);
void release(Heap *V  ,int ndx);
void display(Heap V,head ndx);

//Function Definations Version 1


//Function Definations Version 2


 record newLists[5] = {{{"first0" , "Last0" , '0'} , "BSIT" ,19101010 ,1},
                       {{"first1" , "Last1" , '1'} , "BSIT" ,19101011 ,1},
                       {{"first2" , "Last2" , '2'} , "BSIT" ,19101012 ,1},
                       {{"first3" , "Last3" , '3'} , "BSIT" ,19101013 ,1},
                       {{"first4" , "Last4" , '4'} , "BSIT" ,19101010 ,1}};
    int inputsCount = 0;

int main(void){

    //Version 1
    head List;
    Heap VT;

    initLists(&List);
    initializeHeap(&VT);

    insert(&List , &VT);
    insert(&List , &VT);
    insert(&List , &VT);

    display(VT , List);
    printf("\n");
    delete(&List , &VT , 19101011);
    display(VT , List);


    return 0;
}
void display(Heap V, head ndx){

    // int x;
    // printf("STUDENT DATA :: INDEX\n" );
    // for(x =0; x < MemorySize ; x++){
    //     printf("%-12s :: %3d\n" , "Student",V.student[x].Link);
    // }

    for(; ndx != -1 ; ndx = V.student[ndx].Link){
        printf("%d %s ,%s %c %s %d\n" , V.student[ndx].enrollee.ID , V.student[ndx].enrollee.name.Last , V.student[ndx].enrollee.name.First , V.student[ndx].enrollee.name.Middle , V.student[ndx].enrollee.Course , V.student[ndx].enrollee.yrlvl);
    }


}

void initializeHeap(Heap * Memory){
    int x;

    for(x = 1 ; x < MemorySize ; x++){
        Memory->student[x -1].Link = x; 
    }
        Memory->student[x -1].Link = -1;
        Memory->Available = 0;



}
void initLists(head* ndx){
    *ndx = -1;
}
void insert(head* ndx , Heap * vh){


    // node newNode = {.enrollee = newLists[inputsCount++]};
    head newN;
    head *trav;

        newN = memAlloc(vh);


       if(newN != -1){
            for(trav = ndx; *trav != -1 && vh->student[*trav].enrollee.ID < newLists[inputsCount].ID ; trav = &vh->student[*trav].Link ){}

            vh->student[newN].enrollee = newLists[inputsCount++];
            vh->student[newN].Link = *trav;
            *trav = newN; 
       }

                
}
int memAlloc(Heap *V){
    int ndxRet = V->Available;

    if(ndxRet != -1){
        V->Available = V->student[ndxRet].Link;
    }
    return ndxRet;
}
void delete(head* ndx ,Heap * vh,int ID){

    head *trav; 
    head temp;
    for(trav = ndx ; *trav != -1 && vh->student[*trav].enrollee.ID != ID ; trav = &vh->student[*trav].Link){}

    if(*trav != -1){
        temp = *trav;
        *trav = vh->student[*trav].Link;
        release(vh , temp);
    }


}

void release(Heap *V , int ndx){
    V->student[ndx].Link = V->Available;
    V->Available = ndx;

}

//Version 1 Functions


//Version 2 Functions