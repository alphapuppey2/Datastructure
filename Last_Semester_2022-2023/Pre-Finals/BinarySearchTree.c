#include <stdio.h>
#include <stdlib.h>

// change this to any for the datatype of a item
// you can change it to what ever you like it
// if you want to use refer to variationTypes to know better
typedef int Datatype;
// VARIATIONS
typedef struct n
{
    Datatype item;
    struct n *LC;
    struct n *RC;
} *List;

typedef enum
{
    FALSE,
    TRUE
} BOOLEAN;

void InitialRun(List *l);
void insert(List *l, Datatype L);
void display(List l);
void deleteN(List *l, Datatype L);
BOOLEAN isMember(List root, Datatype Member);

// Remember Datatype is a ADT
int main(void)
{

    List Root;

    InitialRun(&Root);

    // 10,5,3,8,13,20,2,4,7,9

    insert(&Root, 10);
    insert(&Root, 5);
    insert(&Root, 3);
    insert(&Root, 8);
    insert(&Root, 13);
    insert(&Root, 20);
    insert(&Root, 2);
    insert(&Root, 4);
    insert(&Root, 7);
    insert(&Root, 9);

    if (isMember(Root, 50))
    {
        printf("%d is a Member of BST\n");
    }
    else
    {
        printf("%d is NOT a Member of BST\n");
    }
    display(Root);
    printf("\nDELETING NODE 5\n");

    deleteN(&Root, 2);

    printf("\nNew List\n");
    display(Root);

    return 0;
}
void InitialRun(List *l)
{
    *l = NULL;
}
BOOLEAN isMember(List root, Datatype Member)
{
    if (root != NULL && root->item == Member)
    {
        return TRUE;
    }
    else if (root == NULL)
    {
        return FALSE;
    }

    return Member < root->item ? isMember(root->LC, Member) : isMember(root->RC, Member);
}
void deleteNonRecursion(List *l, Datatype L)
{
}

void deleteN(List *l, Datatype L)
{

    if (*l == NULL)
    {
        return;
    }
    else if ((*l)->item == L)
    {
        List *temptrav;
        List temp;
        for (temptrav = &(*l)->RC; *temptrav != NULL && (*temptrav)->LC != NULL; temptrav = &(*temptrav)->LC)
        {
        }
        temp = *temptrav;
        if (*temptrav == NULL)
        {
            temp = *l;
            *l = temp->RC;
        }
        else
        {
            (*l)->item = temp->item;
            *temptrav = temp->LC;
        }

        free(temp);
        return;
    }
    //
    if (L < (*l)->item)
    {
        deleteN(&(*l)->LC, L);
    }
    else
    {
        deleteN(&(*l)->RC, L);
    }
}
void insert(List *l, Datatype L)
{
    if (*l == NULL)
    {
        List newnode = (List)malloc(sizeof(struct n));

        if (newnode != NULL)
        {
            newnode->item = L;
            newnode->LC = newnode->RC = NULL;
            *l = newnode;
        }
        return;
    }

    L < (*l)->item ? insert(&(*l)->LC, L) : insert(&(*l)->RC, L);
}
void display(List l)
{
    // we use Recursion
    if (l == NULL)
    {
        return;
    }

    display(l->LC);
    printf("%d,", l->item);
    display(l->RC);
}