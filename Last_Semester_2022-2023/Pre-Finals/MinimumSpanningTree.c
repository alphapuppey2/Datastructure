#include <stdio.h>
#include <string.h>
#define UNDEFINED -9999
#define V_SIZE 5

typedef int matrix[V_SIZE][V_SIZE];

void InitialRun(matrix);
void displayMST(matrix);
void populateMST(matrix);

int main(void)
{
    matrix X;

    InitialRun(X);
    populateMST(X);

    displayMST(X);

    return 0;
}

void populateMST(matrix mt)
{
    matrix weight = {{UNDEFINED, 1, 5, 4, 6},
                     {5, 1, UNDEFINED, 5, UNDEFINED},
                     {UNDEFINED, 6, 5, 5, UNDEFINED},
                     {2, UNDEFINED, UNDEFINED, 4, UNDEFINED},
                     {2, UNDEFINED, 1, UNDEFINED, 6}};

    memcpy(mt, weight, sizeof(weight));
}

void displayMST(matrix mt)
{
    int row, col;

    for (row = 0; row < V_SIZE; row++)
    {
        for (col = 0; col < V_SIZE; col++)
        {
            // code here
            if (mt[row][col] == UNDEFINED)
            {
                printf("\033[1;31m%3c\033[1;0m", 'X');
            }
            else
            {
                printf("%3d", mt[row][col]);
            }
        }
        printf("\n");
    }
}
void InitialRun(matrix mt)
{
    int x, c;

    for (x = 0; x < V_SIZE; x++)
    {
        for (c = 0; c < V_SIZE; c++)
        {
            mt[x][c] = UNDEFINED;
        }
    }
}
