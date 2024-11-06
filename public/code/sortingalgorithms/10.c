// 10. ENTER A INTEGER ARRAY FROM THE USER AND PERFORM QUICK SORT ALGORITHM THROUGH RECURSION. ALSO CALCULATE THE WORST AND BEST COMPLEXITY WITH EXACT TIME.
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define maxSize 100
void display(int arr[], int size)
{
    for (int i = 0; i < size; i++)
    {
        printf("%d ", arr[i]);
    }
    printf("\n");
}
int partition(int arr[], int start, int end)
{
    int pivot = arr[start];
    int ind = start, temp;
    int i = start, j = end;
    for (int i = start; i <= end; i++)
    {
        if (arr[i] < pivot)
            ind++;
    }
    temp = arr[ind];
    arr[ind] = arr[start];
    arr[start] = temp;
    while ((i < ind) && (j > ind))
    {
        if (arr[i] > pivot)
        {
            if (arr[j] < pivot)
            {
                temp = arr[i];
                arr[i] = arr[j];
                arr[j] = temp;
            }
            else
                j--;
        }
        else
            i++;
    }
    return ind;
}
// The quicksort algorithm operates by selecting a pivot element from the array and partitioning the other elements into two sub-arrays: those less than the pivot and those greater than the pivot. This process is repeated recursively for the sub-arrays until they are sorted.
void quickSort(int arr[maxSize], int start, int end)
{
    if (start >= end)
    {
        return;
    }
    else
    {
        int p = partition(arr, start, end);
        quickSort(arr, start, p - 1);
        quickSort(arr, p + 1, end);
    }
}
int main()
{
    int arr[maxSize];
    int size;
    clock_t start, end;
    printf("ENTER SIZE OF ARRAY : ");
    scanf("%d", &size);
    for (int i = 0; i < size; i++)
    {
        printf("ENTER ARRAY ELEMENT : ");
        scanf("%d", &arr[i]);
    }
    display(arr, size);
    start = clock();
    quickSort(arr, 0, size - 1);
    end = clock();
    display(arr, size);
    printf("Executed in %fs\n", (double)(end - start) / CLOCKS_PER_SEC);
    return 0;
}