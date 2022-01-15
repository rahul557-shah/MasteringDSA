//Missing Element in an Unsorted Array Using HashTable
#include <stdio.h>
int main()
{
    int A[10];
    int size;
    printf("Enter the size of the array: ");
    scanf("%d", &size);
    printf("Enter the elements: ");
    for (int i = 0; i < size; i++)
    {
        scanf("%d", &A[i]);
    }
    printf("\nThe list is: ");
    for (int i = 0; i < size; i++)
    {
        printf("%d ", A[i]);
    }
    int max = A[0];
    int min = A[0];
    for (int i = 1; i < size; i++)
    {
        if (A[i] > max)
        {
            max = A[i];
        }
    }
    printf("\nMaximum value is: %d ", max);
    for (int i = 1; i < size; i++)
    {
        if (A[i] < min)
        {
            min = A[i];
        }
    }
    printf("\nMinimum value is: %d ", min);
    int H[max];
    for (int i = 0; i <= max; i++)
    {
        H[i] = 0;
    }
    for (int i = 0; i < size; i++)
    {
        H[A[i]]++;
    }
    for (int i = min; i <= max; i++)
    {
        if (H[i] == 0)
        {
            printf("\nMissing values are: %d", i);
        }
    }
}