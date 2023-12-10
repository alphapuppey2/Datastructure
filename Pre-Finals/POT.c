// Partial Ordered Tree

#include <stdio.h>
#include <stdlib.h>
#define MAX 15
typedef struct n
{
    int data;
    struct n *LC;
    struct n *RC;
} *POTList;

typedef struct n2
{
    int POT[MAX];
    int count;
} arr;

// Partial Ordered Tree
// parent <= Child

void insert(arr *Node, int data);
void initial(arr *Node);
void minDelete(arr *Node);
void minHeapify(arr *Node);
void maxHeapify(arr *Node);
void display(arr root);

int main(void)
{

    arr root;

    initial(&root);

    // 4 5 9 8 6 9 10 10 18 9  2

    insert(&root, 16);
    insert(&root, 8);
    insert(&root, 12);
    insert(&root, 4);
    insert(&root, 7);
    insert(&root, 20);
    // insert(&root, 4);
    // insert(&root, 5);
    // insert(&root, 9);
    // insert(&root, 8);
    // insert(&root, 6);
    // insert(&root, 9);
    // insert(&root, 10);
    // insert(&root, 10);
    // insert(&root, 18);
    // insert(&root, 9);
    // insert(&root, 2);

    display(root);
    // minDelete(&root);

    // display(root);

    return 0;
}
void minDelete(arr *Node)
{
    // we delete the Root Node because the root Node has the lowest value

    int temp = Node->POT[0];
    Node->POT[0] = Node->POT[Node->count];
    Node->POT[Node->count] = temp;

    Node->count--;

    minHeapify(Node);
}

void display(arr root)
{
    int c;

    for (c = 0; c <= root.count; c++)
    {
        printf("%d | ", root.POT[c]);
    }
    printf("\n");
}
void initial(arr *Node)
{
    Node->count = -1;
}
void insert(arr *Node, int data)
{
    if (Node->count < MAX)
    {
        Node->POT[++Node->count] = data;
    }

    // Must be in Proper position
    maxHeapify(Node);
}
void minHeapify(arr *Node)
{
    // this is MinHeapify

    int parentNdx;
    int LC;
    int RC;
    int tempData;

    for (parentNdx = (Node->count - 1) / 2; parentNdx >= 0; parentNdx--)
    {
        LC = (parentNdx * 2) + 1;
        RC = (parentNdx * 2) + 2;
        //                                       change >= to <= to make it maxHeapify
        if (LC <= Node->count && Node->POT[parentNdx] >= Node->POT[LC])
        // Check if The Parent's left child is , alive ? oh so DARK
        {
            tempData = Node->POT[parentNdx];
            Node->POT[parentNdx] = Node->POT[LC];
            Node->POT[LC] = tempData;
        }
        //                                       change >= to <= to make it maxHeapify
        else if (RC <= Node->count && Node->POT[parentNdx] >= Node->POT[RC])
        {
            tempData = Node->POT[parentNdx];
            Node->POT[parentNdx] = Node->POT[RC];
            Node->POT[RC] = tempData;
        }
    }
}
void maxHeapify(arr *Node)
{
    // this is MaxHeapify

    int parentNdx;
    int LC;
    int RC;
    int tempData;

    for (parentNdx = (Node->count - 1) / 2; parentNdx >= 0; parentNdx--)
    {
        LC = (parentNdx * 2) + 1;
        RC = (parentNdx * 2) + 2;
        //                                       change >= to <= to make it maxHeapify
        if (LC <= Node->count && Node->POT[parentNdx] <= Node->POT[LC])
        {
            tempData = Node->POT[parentNdx];
            Node->POT[parentNdx] = Node->POT[LC];
            Node->POT[LC] = tempData;
        }
        //                                       change >= to <= to make it maxHeapify
        else if (RC <= Node->count && Node->POT[parentNdx] <= Node->POT[RC])
        {
            tempData = Node->POT[parentNdx];
            Node->POT[parentNdx] = Node->POT[RC];
            Node->POT[RC] = tempData;
        }
    }
}