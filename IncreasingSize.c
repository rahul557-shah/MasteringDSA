//Increasing the size of an Array
#include <stdio.h>
#include <stdlib.h>
void main()
{
    int *p = (int *)malloc(5 * sizeof(int));
    p[0] = 1;
    p[1] = 3;
    p[2] = 5;
    p[3] = 7;
    p[4] = 9;
    int *q = (int *)malloc(10 * sizeof(int));
    for (int i = 0; i < 5; i++)
    {
        q[i] = p[i];
        printf("%d ", q[i]);
    }
    free(p);
    p = q;
    q = NULL;
    p[6] = 11;
    p[7] = 13;
    printf("\n");
    for (int i = 0; i < 10; i++)
    {
        printf("%d ", p[i]);
    }
}