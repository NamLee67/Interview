/*Prolem 1: Macro define */
#include <stdio.h>

#define MAX_VALUE(a, b)     (((a) > (b)) ? (a) : (b)) 

int main(void)
{
    int i = 5;
    printf("MAX_VALUE(10, 20) = %d\n", MAX_VALUE(10, 20));
    printf("MAX_VALUE(i, 3) = %d\n", MAX_VALUE(i, 3));

    return 0;
}