#include<stdio.h>
#include<stdlib.h>
#include<ctype.h>
#define MAX 0xA
#define EMPTY '?'
#define DELETED '-'

typedef char Dictionary[MAX];


void initDic(Dictionary s);
int Hash(char data);
void insert(Dictionary s, char data);
void Display(Dictionary s);
void deleteCell(Dictionary s , char data);

int main(void){

    Dictionary list;

    initDic(list);

    insert(list , 'c');
    insert(list , 'd');
    insert(list , 'e');
    insert(list , 'f');
    insert(list , 'a');
    insert(list , 'g');
    insert(list , 'u');
    insert(list , 'b');
    insert(list , 'z');
    insert(list , 'c');
    
    Display(list);

    deleteCell(list , 'c');
    deleteCell(list , 'd');
    deleteCell(list , 'e');
    deleteCell(list , 'f');
    deleteCell(list , 'g');
    deleteCell(list , 'h');
    deleteCell(list , 'i');
    deleteCell(list , 'j');
    deleteCell(list , 'k');
    deleteCell(list , 'l');
    deleteCell(list , 'c');

    Display(list);

    return 0;
}
int Hash(char data){
    return (tolower(data) - 'a') % MAX;
}
void initDic(Dictionary s){
    int x; 

    for(x = 0; x < MAX ; x++){
        s[x] = EMPTY;
    }
}
void insert(Dictionary s, char data){
    int ndx;
    int count;
    
    for(ndx = Hash(data),count = 0 ; count < MAX && s[ndx] != EMPTY && s[ndx] != DELETED; count++, ndx = (ndx + 1) % MAX ){}
    if(count < MAX){
        s[ndx] = data;
    }
}
void deleteCell(Dictionary s , char data){
    
    int ndx = Hash(data);
    int count;
    for(count = 0; count < MAX && s[ndx] != data;count++ , ndx = (ndx + 1) % MAX){}

    if(count < MAX){
        s[ndx] = DELETED;
    }
}
void Display(Dictionary s){
    int x;
    for(x =0; x < MAX ; x++){
        printf("List[%d] :" , x);
        switch (s[x])
        {
        case EMPTY:
            printf("EMPTY\n");
            break;
        case DELETED:
            printf("DELETED\n");
            break;
        default:
            printf("%c\n" , s[x]);
            break;
        }
    }
}