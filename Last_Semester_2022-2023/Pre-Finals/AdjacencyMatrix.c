#include <stdio.h>
#include <string.h>
#define UNDEFINED -9999
#define V_SIZE 5

typedef int matrix[V_SIZE][V_SIZE];

void InitialRun(matrix);
void displayADJ(matrix);
void populateADJ(matrix);

int main(void)
{
    matrix X;

    InitialRun(X);
    populateADJ(X);

    displayADJ(X);

    return 0;
}

void populateADJ(matrix mt)
{
    matrix weight = {{UNDEFINED, 1, 1, 1, 1},
                     {1, 1, UNDEFINED, 1, UNDEFINED},
                     {UNDEFINED, 1, 1, 1, UNDEFINED},
                     {1, UNDEFINED, UNDEFINED, 1, UNDEFINED},
                     {1, UNDEFINED, 1, UNDEFINED, 1}};

    memcpy(mt, weight, sizeof(weight));
}

void displayADJ(matrix mt)
{
    int row, col;
    printf("This is Matrix Representation: \n");
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
                printf("\033[1;32m%3d\033[1;0m", mt[row][col]);
            }
        }
        printf("\n");
    }
    printf("Pairs:: \n");
    int x, y;
    for (x = 0; x < V_SIZE; x++)
    {
        for (y = 0; y < V_SIZE; y++)
        {
            if (mt[x][y] == 1)
            {
                printf("(%d,%d) ,", x, y);
            }
        }
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
