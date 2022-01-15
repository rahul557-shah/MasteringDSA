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
    for (int i = 0; i < arr.length; i++)
    {
        printf("%d ", arr.A[i]);
    }
}
void append(struct Array *arr, int x)
{
    arr->A[arr->length] = x;
    arr->length++;
}
void insert(struct Array *arr, int index, int x)
{
    if (index >= 0 && index <= arr->length)
    {
        for (int i = arr->length; i > index; i--)
        {
            arr->A[i] = arr->A[i - 1];
        }
        arr->A[index] = x;
        arr->length++;
    }
}
int delete (struct Array *arr, int index)
{
    int value = 0;
    if (index >= 0 && index <= arr->length)
    {
        value = arr->A[index];
        for (int i = index; i < arr->length - 1; i++)
        {
            arr->A[i] = arr->A[i + 1];
        }
        arr->length--;
        return value;
    }
    return 0;
}
void main()
{
    int n, x, index;
    struct Array arr;
    printf("Enter the size: ");
    scanf("%d", &arr.size);
    arr.A = (int *)malloc(arr.size * sizeof(int));
    arr.length = 0;
    printf("Enter the number of elements: ");
    scanf("%d", &n);
    printf("Enter the elements: ");
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &arr.A[i]);
    }
    arr.length = n;
    printf("Enter a value to be added: ");
    scanf("%d", &x);
    append(&arr, x);
    printf("Enter the index and value to be inserted: ");
    scanf("%d%d", &index, &x);
    insert(&arr, index, x);
    printf("Enter the index to delete an element: ");
    scanf("%d", &index);
    printf("The deleted item is: %d\n", delete (&arr, index));
    display(arr);
}