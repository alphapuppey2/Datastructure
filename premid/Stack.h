#ifndef stacklib
#define stacklib
#define MAX 5

typedef struct {
    char elem[MAX];
    int TopList;
}STACK;

void InitStack(STACK *S);
void Push(STACK *S ,char elem);
void Pop(STACK *S);
int Top(STACK S);
void MakeNull(STACK *S);
int isEmpty(STACK S); // either the TOP is -1 or MAX
int isFull(STACK S); // either the TOP is -1 or MAX
void Display(STACK S);
void InsertBottom(STACK *S , char Data);

void Display(STACK S){ 
    int x;
    for(x = S.TopList;x < MAX ; x++ ){
        printf("%c\n" , S.elem[x]);
    }

}

void InsertBottom(STACK *original , char elem){

    int Topndx;
    STACK templist;

    InitStack(&templist); // para d mag error ang templist kay garbage pa before sa call ani


    // Loop to transfer All Existing in the Original List to a temp to insert elem to Last
    for(Topndx = Top(*original); Topndx != MAX; Topndx = Top(*original)){
        Push(&templist ,original->elem[Topndx]);
        Pop(original);
    }
    Push(original,elem);

    for(Topndx = Top(templist); Topndx != MAX ; Topndx = Top(templist)){
        Push(original ,templist.elem[Topndx]);
        Pop(&templist);
    }
}

void InitStack(STACK *S){
    S->TopList = MAX;
}
void Push(STACK *S ,char elem){

    if(!isFull(*S)){
        S->elem[--S->TopList] = elem;
    }
}
void Pop(STACK *S){
    if(!isEmpty(*S)){ // if there is nothing to delete
        S->TopList++;
    }
}
int Top(STACK S){
    return S.TopList;
}
void MakeNull(STACK *S){
    S->TopList = MAX;
}
int isEmpty(STACK S){
    return S.TopList == MAX ? 1 : 0;
}
int isFull(STACK S){
    return S.TopList == -1 ? 1 : 0;
}


#endif