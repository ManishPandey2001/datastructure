// 2. ENTER A INTEGER ARRAY FROM THE USER AND PERFORM SELECTION SORT ALGORITHM THROUGH RECURSION. ALSO CALCULATE THE WORST AND BEST COMPLEXITY WITH EXACT TIME.
#include <stdio.h>
#define maxSize 100
// selection sorts looks for smallest element in the sorted array
void selectionSort(int arr[], int size, int i, int j, int min)
{
    if (i < (size - 1))
    {
        if (j == size)
        {
            int temp = arr[i];
            arr[i] = arr[min];
            arr[min] = temp;
            i++;
            min = i;
            j = min + 1;
        }
        if (arr[j] < arr[min])
        {
            selectionSort(arr, size, i, j + 1, j);
        }
        else
        {
            selectionSort(arr, size, i, j + 1, min);
        }
    }
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
    selectionSort(arr, size, 0, 1, 0);
    printf("\n");
    for (int i = 0; i < size; i++)
    {
        printf("%d ", arr[i]);
    }

    return 0;
}