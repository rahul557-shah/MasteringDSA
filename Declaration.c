//Declaring an Array
#include <stdio.h>
#include <stdlib.h>
void main()
{
    int A[5];
    int B[5] = {1, 2, 3, 4, 5};
    int C[5] = {2, 4};
    int D[5] = {0};
    for (int i = 0; i < 5; i++)
    {
        printf("%d ", A[i]);
    }
    printf("\n");
    for (int i = 0; i < 5; i++)
    {
        printf("%d ", B[i]);
    }
    printf("\n");
    for (int i = 0; i < 5; i++)
    {
        printf("%d ", C[i]);
    }
    printf("\n");
    for (int i = 0; i < 5; i++)
    {
        printf("%d ", D[i]);
    }
    printf("\n");
    for (int i = 0; i < 5; i++)
    {
        printf("%u ", &B[i]); //Address of each array element
    }
    printf("\n");
    int *p = (int *)malloc(5 * sizeof(int));
    p[0] = 3;
    p[1] = 6;
    p[2] = 9;
    p[3] = 17;
    p[4] = 19;
    for (int i = 0; i < 5; i++)
    {
        printf("%d ", p[i]);
    }
}