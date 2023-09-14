#include<stdio.h>
#include<stdlib.h>

typedef struct node{
    int data;
    struct node * next;
}*List, ltype;

void initialize(List *L);
void insertFirst(List *L, int elem);
void insertLast(List *L, int elem);
void insertSorted(List *L, int elem);
List retrieve(List L, int position);
List deleteNode(List *L, int elem);
void printList(List *L);


int main(){
    List head;
    initialize(&head);
      insertFirst(&head, 101);
    insertFirst(&head, 41);
      insertFirst(&head, 32);
      insertFirst(&head, 67);
 
    printList(&head);
    
    initialize(&head);
    printf("\n\n");
    insertLast(&head, 74);
    insertLast(&head, 69);
    insertLast(&head, 81);
    insertLast(&head, 23);
    printList(&head);
    
    initialize(&head);
    printf("\n\n");
    insertSorted(&head, 92);
    insertSorted(&head, 56);
    insertSorted(&head, 116);
    insertSorted(&head, 2);
    
    printList(&head);
    
    initialize(&head);
    printf("\n\n");
    insertSorted(&head, 3);
    insertSorted(&head, 4);
    insertSorted(&head, 9);
    insertSorted(&head, 1);
    
    //head = retrieve(head, 5);
    //printf("retrieved: [%d]" head->data);

    printList(&head);

    printf("\n");
    
    head = deleteNode(&head, 0);
    if(head != NULL)
    printf("deleted: [%d]", head->data); 
    else
     printf("element not found"); 
    
    
    
}

void initialize(List *L){
  *L = NULL;
}

void insertFirst(List *L, int elem){
    List newnode = (List)malloc(sizeof(ltype));
    List * trav;
    for(trav = L; *trav!=NULL; trav = &(*trav)->next){}
    if(newnode!=NULL){
      newnode->data = elem;
      newnode->next = *trav;
      *trav = newnode;
      }
}

void insertLast(List *L, int elem){
    List newnode = (List)malloc(sizeof(ltype));
    List * trav;
 
    for(trav = L; *trav!=NULL && (*trav)->data == elem; trav = &(*trav)->next){}
    if(newnode!=NULL){
      newnode->data = elem;
      newnode->next =*trav;
      *trav = newnode;
 
      }

}

void insertSorted(List *L, int elem){
    List newnode = (List)malloc(sizeof(ltype));
    List * trav;
    for(trav = L; *trav!=NULL && (*trav)->data < elem; trav = &(*trav)->next){}
    if(newnode!=NULL){
        newnode->data = elem;
        newnode->next = *trav;
        *trav = newnode;
    }
}

List retrieve(List L, int pos) {
      int count;
    List trav;

    for(trav = L, count = 1; trav->next!=NULL && count != pos; trav = trav->next, count++){}
    return trav;
    
    
    
}


List deleteNode(List *L, int elem){
    List * trav;
    List temp = NULL;
    for(trav = L; *trav != NULL && (*trav)->data != elem; trav = &(*trav)->next){}
    if(*trav!=NULL){
        temp = *trav;
        *trav = temp->next;        
    }
    return temp;
}

void printList(List *L){
    List print =  *L;
    for(; print!=NULL; print = print->next){
      printf("[%d]", print->data);
      }
  
}