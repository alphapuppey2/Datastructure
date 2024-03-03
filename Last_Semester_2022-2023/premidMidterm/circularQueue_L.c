#include <stdio.h>
#include <stdlib.h>
#define max 10

typedef struct n
{
    int data;
    struct n *prev;
    struct n *next;
} *circular;

void enqueue(circular *head, int data);
void dequeue(circular *head);
void initialize(circular *head);
void display(circular L);

int main(void)
{

    circular list;
    initialize(&list);
    
    enqueue(&list,5);
    enqueue(&list,4);
    enqueue(&list,2);

    display(list);
    
    dequeue(&list);
    


    display(list);

    return 0;
}
void dequeue(circular *head){
    circular temp = *head;

    *head = (*head)->next;
    (*head)->prev = temp->prev;

    free(temp);
}
void enqueue(circular *head, int data)
{

    circular *traverse;

    circular node = (circular)malloc(sizeof(struct n));
    if (node != NULL)
    {
        node->data = data;

        if (*head == NULL)
        {
            node->prev = node;
            node->next = node;

            *head = node;
        }
        else
        {
            for(traverse = head ; (*traverse)->next != *head; traverse = &(*traverse)->next){}

            node->next = (*traverse)->next;
            node->prev = *traverse;
            (*traverse)->next = node;
            (*head)->prev = node;

        }
    }
}
void initialize(circular *head)
{
    *head = NULL;
}
void display(circular L)
{
    circular terminator;
    for(terminator = L ; L != terminator->prev ; L = L->next){
        printf(" %d <==>" , L->data);
    }
        printf(" %d\n" ,L->data);
}