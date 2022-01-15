#include <stdio.h>
int main()
{
    int A[10];
    int size, k;
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
    for (int i = 1; i < size; i++)
    {
        if (A[i] > max)
        {
            max = A[i];
        }
    }
    printf("\nMaximum value is: %d ", max);
    int H[max];
    printf("Enter the sum: ");
    scanf("%d", &k);
    for (int i = 0; i <= max; i++)
    {
        H[i] = 0;
    }
    for (int i = 0; i < size; i++)
    {
        if (H[k - A[i]] != 0)
        {
            printf("\n %d + %d = %d ", A[i], (k - A[i]), k);
        }
        H[A[i]]++;
    }
}