#include<stdio.h>
#include<stdlib.h>


typedef struct POT
{
    int data;
    struct POT * l;
    struct POT * r;
}pot , *potr;
