//All the operations on an Array
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
    printf("\nElements are: ");
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
void swap(int *x, int *y)
{
    int temp;
    temp = *x;
    *x = *y;
    *y = temp;
}
int LinearSearch(struct Array *arr, int key)
{
    for (int i = 0; i < arr->length; i++)
    {
        if (arr->A[i] == key)
        {
            return i;
        }
    }
    return -1;
}
int BinarySearch(struct Array arr, int key)
{
    int l = 0;
    int h = arr.length - 1;
    int mid;
    while (l <= h)
    {
        mid = (l + h) / 2;
        if (key == arr.A[mid])
            return mid;
        else if (key < arr.A[mid])
            h = mid - 1;
        else
            l = mid + 1;
    }
    return -1;
}
int delete (struct Array *arr, int index)
{
    int value = 0;
    if (index >= 0 && index <= arr->length - 1)
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
int Get(struct Array arr, int index)
{
    if (index >= 0 && index <= arr.length - 1)
    {
        return arr.A[index];
    }
}
void Set(struct Array *arr, int index, int x)
{
    if (index >= 0 && index <= arr->length - 1)
    {
        arr->A[index] = x;
    }
}
int Max(struct Array arr)
{
    int max = arr.A[0];
    for (int i = 0; i < arr.length; i++)
    {
        if (arr.A[i] > max)
        {
            max = arr.A[i];
        }
    }
    return max;
}
int Min(struct Array arr)
{
    int min = arr.A[0];
    for (int i = 0; i < arr.length; i++)
    {
        if (arr.A[i] < min)
        {
            min = arr.A[i];
        }
    }
    return min;
}
int Sum(struct Array arr)
{
    int sum = 0;
    for (int i = 0; i < arr.length; i++)
    {
        sum += arr.A[i];
    }
    return sum;
}
void Reverse(struct Array *arr)
{
    for (int i = 0, j = arr->length - 1; i < j; i++, j--)
    {
        swap(&arr->A[i], &arr->A[j]);
    }
}
void LShift(struct Array *arr)
{
    for (int i = 0; i < arr->length; i++)
    {
        arr->A[i] = arr->A[i + 1];
    }
    arr->A[arr->length - 1] = 0;
}
void LRotate(struct Array *arr)
{
    for (int i = 0; i < arr->length; i++)
    {
        arr->A[i] = arr->A[i + 1];
    }
    arr->A[arr->length - 1] = arr->A[0];
}
void InsertInASorted(struct Array *arr, int key)
{
    int i = arr->length - 1;
    while (arr->A[i] > key)
    {
        arr->A[i + 1] = arr->A[i];
        i--;
    }
    arr->A[i + 1] = key;
    arr->length++;
}
int IsSorted(struct Array arr)
{
    for (int i = 0; i < arr.length - 1; i++)
    {
        if (arr.A[i] > arr.A[i + 1])
        {
            return 0;
        }
    }
    return 1;
}
void Rearrange(struct Array *arr)
{
    int i = 0;
    int j = arr->length - 1;
    while (i < j)
    {
        while (arr->A[i] < 0)
            i++;
        while (arr->A[j] > 0)
            j--;
        if (i < j)
        {
            swap(&arr->A[i], &arr->A[j]);
        }
    }
}
struct Array *Merge(struct Array *arr, struct Array *arr1)
{
    int i = 0, j = 0, k = 0;
    struct Array *arr2 = (struct Array *)malloc(sizeof(struct Array));
    while (i < arr->length && j < arr1->length)
    {
        if (arr->A[i] < arr1->A[j])
        {
            arr2->A[k] = arr->A[i];
            i++;
            k++;
        }
        else
        {
            arr2->A[k] = arr1->A[j];
            j++;
            k++;
        }
    }
    while (i < arr->length)
    {
        arr2->A[k] = arr->A[i];
        i++;
        k++;
    }
    while (j < arr1->length)
    {
        arr2->A[k] = arr1->A[j];
        j++;
        k++;
    }
    arr2->length = arr->length + arr1->length;
    arr2->size = arr->size;
    return arr2;
}
struct Array *Union(struct Array *arr, struct Array *arr1)
{
    int i = 0, j = 0, k = 0;
    struct Array *arr2 = (struct Array *)malloc(sizeof(struct Array));
    while (i < arr->length && j < arr1->length)
    {
        if (arr->A[i] < arr1->A[j])
        {
            arr2->A[k] = arr->A[i];
            i++;
            k++;
        }
        else if (arr->A[i] > arr1->A[j])
        {
            arr2->A[k] = arr1->A[j];
            j++;
            k++;
        }
        else
        {
            arr2->A[k] = arr->A[i];
            i++;
            j++;
            k++;
        }
    }
    while (i < arr->length)
    {
        arr2->A[k] = arr->A[i];
        i++;
        k++;
    }
    while (j < arr1->length)
    {
        arr2->A[k] = arr1->A[j];
        j++;
        k++;
    }
    arr2->length = k;
    arr2->size = arr->size;
    return arr2;
}
struct Array *Intersection(struct Array *arr, struct Array *arr1)
{
    int i = 0, j = 0, k = 0;
    struct Array *arr2 = (struct Array *)malloc(sizeof(struct Array));
    while (i < arr->length && j < arr1->length)
    {
        if (arr->A[i] < arr1->A[j])
        {
            i++;
        }
        else if (arr->A[i] > arr1->A[j])
        {
            j++;
        }
        else
        {
            arr2->A[k] = arr->A[i];
            i++;
            j++;
            k++;
        }
    }
    arr2->length = k;
    arr2->size = 10;
    return arr2;
}
struct Array *SetDifference(struct Array *arr, struct Array *arr1)
{
    int i = 0, j = 0, k = 0;
    struct Array *arr2 = (struct Array *)malloc(sizeof(struct Array));
    while (i < arr->length && j < arr1->length)
    {
        if (arr->A[i] < arr1->A[j])
        {
            arr2->A[k] = arr->A[i];
            i++;
            k++;
        }
        else if (arr->A[i] > arr1->A[j])
        {
            j++;
        }
        else
        {
            i++;
            j++;
        }
    }
    while (i < arr->length)
    {
        arr2->A[k] = arr->A[i];
        i++;
        k++;
    }
    arr2->length = k;
    arr2->size = arr->size;
    return arr2;
}
int main()
{
    int n, x, index, key, ch;
    struct Array arr, arr1, *arr2;
    printf("Enter the size of an array: ");
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
    printf("Enter the size of an array: ");
    scanf("%d", &arr1.size);
    arr1.A = (int *)malloc(arr1.size * sizeof(int));
    arr1.length = 0;
    printf("Enter the number of elements: ");
    scanf("%d", &n);
    printf("Enter the elements: ");
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &arr1.A[i]);
    }
    arr1.length = n;
    do
    {
        printf("\nMENU ARE BELOW: ");
        printf("\n1. Append at the end of array: ");
        printf("\n2. Insert at any index: ");
        printf("\n3. Linear Search: ");
        printf("\n4. Binary Search: ");
        printf("\n5. Delete an element: ");
        printf("\n6. Get an element from a index: ");
        printf("\n7. Maximum: ");
        printf("\n8. Minimum: ");
        printf("\n9. Sum: ");
        printf("\n10. Reverse: ");
        printf("\n11. Set: ");
        printf("\n12. Display: ");
        printf("\n13. Is Sorted: ");
        printf("\n14. Merge: ");
        printf("\n15. Set Union: ");
        printf("\n16. Set Intersection: ");
        printf("\n17. Set Difference: ");
        printf("\n18. Exit: ");
        printf("\nEnter your choice: ");
        scanf("%d", &ch);
        switch (ch)
        {
        case 1:
            printf("Enter the element to be added: ");
            scanf("%d", &x);
            append(&arr, x);
            break;
        case 2:
            printf("Enter an element to be inserted at a given index: ");
            scanf("%d%d", &index, &x);
            insert(&arr, index, x);
            break;
        case 3:
            printf("\nEnter a value to be searched: ");
            scanf("%d", &key);
            printf("The element is at index: %d ", LinearSearch(&arr, key));
            break;
        case 4:
            printf("\nEnter a value to be searched: ");
            scanf("%d", &key);
            printf("The element is at: %d ", BinarySearch(arr, key));
        case 5:
            printf("\nEnter the index to delete an element: ");
            scanf("%d", &index);
            printf("Deleted element is: %d\n", delete (&arr, index));
            break;
        case 6:
            printf("\nEnter the index to get the element: ");
            scanf("%d", &index);
            printf("The element at index %d is: %d", index, Get(arr, index));
            break;
        case 7:
            printf("\nThe maximum value is: %d ", Max(arr));
            break;
        case 8:
            printf("\nThe minimum value is: %d ", Min(arr));
            break;
        case 9:
            printf("\nThe sum of elements is: %d ", Sum(arr));
            break;
        case 10:
            Reverse(&arr);
            break;
        case 11:
            printf("\nEnter the index and value to be set: ");
            scanf("%d%d", &index, &x);
            Set(&arr, index, x);
            break;
        case 12:
            display(arr);
            break;
        case 13:
            printf("Is sorted :%d ", IsSorted(arr));
            break;
        case 14:
            arr2 = Merge(&arr, &arr1);
            display(*arr2);
            break;
        case 15:
            arr2 = Union(&arr, &arr1);
            display(*arr2);
            break;
        case 16:
            arr2 = Intersection(&arr, &arr1);
            display(*arr2);
            break;
        case 17:
            arr2 = SetDifference(&arr, &arr1);
            display(*arr2);
            break;
        }
    } while (ch < 18);
    return 0;
}
/*  LShift(&arr);
    display(arr);
    printf("\nEnter a value to be inserted in a sorted array: ");
    scanf("%d", &key);
    InsertInASorted(&arr, key);
    display(arr);
    printf("\n Rearranging the list: ");
    Rearrange(&arr);
    display(arr);
*/