/* 
    This is Version 1 of ADT
    ----------
    FUNCTIONS
    ----------
    initlist()
    findElem()
    insertFirst()
    deleteElem()

*/
#include<stdio.h>
#include<stdlib.h>
#define MAX 10


typedef struct{
    char elem[MAX];
    int count;
}Adt;
typedef enum {TRUE = 1, FALSE = 0}Boolean;

void initList(Adt *list);
int findElem(Adt list , char data);
void insertFirst(Adt *list , char data );
int delete(Adt *list , char data);
void display(Adt list);

int main(void){

    Adt list;

    initList(&list);

    insertFirst(&list , 'u');
    insertFirst(&list , 's');
    insertFirst(&list , 'c');

    display(list);

    insertFirst(&list , 'T');
    insertFirst(&list , 'C');
    insertFirst(&list , 'S');
    insertFirst(&list , 'C');

    display(list);

    if(delete(&list , 'T')){
        display(list);
    }
    else{
        printf("Failed to delete");
    }




    return 0;
}

void display(Adt list){
    int x;

    for (x = 0; x < list.count ; x++)
    {
        printf("%c " , list.elem[x]);
    }
    printf("\n");

}

void initList(Adt *list){
    list->count = 0;
}
int findElem(Adt list , char data){
    int ndx;

    for (ndx = 0; list.count != MAX && ndx < list.count; ndx++){}
    

    return ndx != list.count ? ndx: -1;
}
void insertFirst(Adt *list , char data ){
    int c;

    if(list->count < MAX){
        list->count++;
        for (c = list->count; c > 0; c--){
            list->elem[c] = list->elem[c - 1];
            
        }

        list->elem[c] = data;
    }

}
int delete(Adt *list , char data){

    int c,x;
    int ret = 0;

    //check if the data is exist
    if(list->count > 0){
        for (c = 0; c < list->count && list->elem[c] != data; c++){}
        //shifting

        if(c != list->count){
            for(x = c; x < list->count; x++){
                list->elem[x] = list->elem[x + 1];
            }
            list->count--;
        }
    }
    return (c != list->count) ? 1 : 0;
}


