//Find a single missing element in an array
#include <stdio.h>
#include <stdlib.h>
struct Array
{
    int *A;
    int size;
    int length;
};
void display(struct Array arr)
{
    printf("The list is: ");
    for (int i = 0; i < arr.length; i++)
    {
        printf("%d ", arr.A[i]);
    }
}
int SingleMissing(struct Array arr)
{
    int sum = 0, s;
    for (int i = 0; i < arr.length; i++)
    {
        sum = sum + arr.A[i];
    }
    s = arr.A[arr.length - 1] * (arr.A[arr.length - 1] + 1) / 2;
    return s - sum;
}
int SingleMissing2(struct Array arr)
{
    int diff = arr.A[0] - 0;
    int miss;
    for (int i = 0; i < arr.length; i++)
    {
        if (arr.A[i] - i != diff)
        {
            miss = i + diff;
            break;
        }
    }
    return miss;
}
//Multiple Missing Element
int MultipleMissing(struct Array arr)
{
    int diff = arr.A[0] - 0;
    int miss;
    for (int i = 0; i < arr.length; i++)
    {
        if (arr.A[i] - i != diff)
        {
            while (diff < arr.A[i] - i)
            {
                printf("\nMissing element is: %d ", i + diff);
                diff++;
            }
        }
    }
}
//Duplicates in a sorted Array
void Duplicates(struct Array arr)
{
    int lastDuplicate = 0;
    for (int i = 0; i < arr.length; i++)
    {
        if (arr.A[i] == arr.A[i + 1] && arr.A[i] != lastDuplicate)
        {
            printf("\nDuplicate elements is: %d ", arr.A[i]);
            lastDuplicate = arr.A[i];
        }
    }
}
//Counting the number of duplicates in a sorted array
void CountDuplicates(struct Array arr)
{
    int j;
    for (int i = 0; i < arr.length; i++)
    {
        if (arr.A[i] == arr.A[i + 1])
        {
            j = i + 1;
            while (arr.A[i] == arr.A[j])
            {
                j++;
            }
            printf("\n%d appears for %d times ", arr.A[i], j - i);
            i = j - 1;
        }
    }
}
//Counting the number of duplicates in an unsorted array
void UnsortedDuplicates(struct Array arr)
{
    for (int i = 0; i < arr.length - 1; i++)
    {
        int count = 1;
        if (arr.A[i] != -1)
        {
            for (int j = i + 1; j < arr.length; j++)
            {
                if (arr.A[i] == arr.A[j])
                {
                    count++;
                    arr.A[j] = -1;
                }
            }
            if (count > 1)
                printf("\n%d appears %d times.", arr.A[i], count);
        }
    }
}
//Find a pair with sum k(a+b=k) in an unsorted array
void UnsortedPairSum(struct Array arr)
{
    int k;
    printf("\nEnter the sum to be found: ");
    scanf("%d", &k);
    for (int i = 0; i < arr.length - 1; i++)
    {
        for (int j = i + 1; i < arr.length; j++)
        {
            if (arr.A[i] + arr.A[j] == k)
                printf("%d + %d = %d ", arr.A[i], arr.A[j], k);
        }
    }
}
//Find a pair with sum k(a+b=k) in an unsorted array
void SortedPairSum(struct Array arr)
{
    int k;
    printf("\nEnter the sum to be found: ");
    scanf("%d", &k);
    for (int i = 0, j = arr.length - 1; i < j;)
    {
        if (arr.A[i] + arr.A[j] == k)
        {
            printf("\n%d + %d = %d ", arr.A[i], arr.A[j], k);
            i++;
            j--;
        }
        else if (arr.A[i] + arr.A[j] < k)
        {
            i++;
        }
        else
        {
            j--;
        }
    }
}
int main()
{
    int n, k, ch;
    struct Array arr;
    printf("Enter the size of an array: ");
    scanf("%d", &arr.size);
    arr.A = (int *)malloc(arr.size * sizeof(int));
    printf("Enter the number of elements: ");
    scanf("%d", &n);
    printf("Enter the elements: ");
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &arr.A[i]);
    }
    arr.length = n;
    display(arr);
    do
    {
        printf("\nMENU ARE BELOW: ");
        printf("\n1. Single missing element: ");
        printf("\n2. Multiple Missing elements: ");
        printf("\n3. Duplicates in a sorted array: ");
        printf("\n4. Counting Duplicates in a sorted array: ");
        printf("\n5. Counting Duplicates in an unsorted array: ");
        printf("\n6. Unsorted Pair Sum: ");
        printf("\n7. Sorted Pair sum: ");
        printf("\n8. Exit: ");
        printf("\nEnter your choice: ");
        scanf("%d", &ch);
        switch (ch)
        {
        case 1:
            printf("\nMissing element is: %d ", SingleMissing(arr));
            break;
        case 2:
            MultipleMissing(arr);
            break;
        case 3:
            Duplicates(arr);
            break;
        case 4:
            CountDuplicates(arr);
            break;
        case 5:
            UnsortedDuplicates(arr);
            break;
        case 6:
            UnsortedPairSum(arr);
            break;
        case 7:
            SortedPairSum(arr);
            break;
        }
    } while (ch < 8);
    return 0;
}