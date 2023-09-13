#include<stdio.h>
#include<stdlib.h>
#define MAX 10

typedef struct ADT
{
    char elem[MAX];
    int count;
}Adt;


void initList(Adt *list);
void insert(Adt *list , char data);
void display(Adt list);

int main(void){

    /*This Code will insert in Order*/

    Adt list;

    initList(&list);

    insert(&list , 'B');
    insert(&list , 'A');
    insert(&list , 'C');
    insert(&list , 'C');
    insert(&list , 'D');
    insert(&list , 'A');
    insert(&list , 'B');
    insert(&list , 'D');
    insert(&list , 'E'); 
    insert(&list , 'E');


    display(list);

    return 0;
}

void initList(Adt *list){
    list->count = 0;
}
void insert(Adt *list , char data){

    int x,c;

    if(list->count < MAX){

        // shift all to left until the list->elem[c-1] <= to data
        for(c = list->count ; c > 0 && list->elem[c-1] > data; c--){
                list->elem[c] = list->elem[c-1];
        }
        list->elem[c] = data;
        list->count++;
    }
}
void display(Adt list){
    int x;

    for (x = 0; x < list.count ; x++)
    {
        printf("%c " , list.elem[x]);
    }
    printf("\n");

}