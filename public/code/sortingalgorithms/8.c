// 8. ENTER A INTEGER ARRAY FROM THE USER AND PERFORM MERGE SORT ALGORITHM THROUGH RECURSION. ALSO CALCULATE THE WORST AND BEST COMPLEXITY WITH EXACT TIME.
#include <stdio.h>
#include <stdlib.h>
#define maxSize 100
void display(int arr[], int size)
{
    for (int i = 0; i < size; i++)
    {
        printf("%d ", arr[i]);
    }
    printf("\n");
}
// The array is divided into two halves until each sub-array contains a single element (which is inherently sorted).
int *merge(int arr1[], int size1, int arr2[], int size2)
{
    int *temp = (int *)calloc(sizeof(int), size1 + size2);
    int i = 0, j = 0, k = 0;
    while (i < size1)
    {
        temp[i] = arr1[i++];
    }
    while (j < size2)
    {
        temp[i + j - 1] = arr2[j++];
    }

    printf("%d %d INNER : ", size1, size2);
    display(temp, size1 + size2);
    return temp;
}
int *mergeSort(int arr[], int start, int end)
{
    int size1 = end - start, size2;
    if (size1 < 2)
    {
        return arr;
    }
    printf("%d %d OUTER : ", start, end);
    display(arr, size1);
    size2 = size1 - (size1 / 2);
    size1 /= 2;
    return merge(mergeSort(arr, start, end / 2), size1,
                 mergeSort(arr, (end / 2) + 1, end), size2);
}
int main()
{
    int arr[maxSize];
    int size;
    printf("ENTER SIZE OF ARRAY : ");
    scanf("%d", &size);
    for (int i = 0; i < size; i++)
    {
        printf("ENTER ARRAY ELEMENT : ");
        scanf("%d", &arr[i]);
    }
    for (int i = 0; i < size; i++)
    {
        printf("%d ", arr[i]);
    }
    printf("\n");
    mergeSort(arr, 0, size - 1);
    for (int i = 0; i < size; i++)
    {
        printf("%d ", arr[i]);
    }

    return 0;
}