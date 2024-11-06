// 5. ENTER A INTEGER ARRAY FROM THE USER AND PERFORM INSERTION SORT ALGORITHM THROUGH ITERATION. ALSO CALCULATE THE WORST AND BEST COMPLEXITY WITH EXACT TIME.
#include <stdio.h>
#define maxSize 100
// inserts element from unsorted array to sorted array at its correct place
void insertionSort(int arr[], int size)
{
    int temp;
    int i = 0;
    for (int j = i + 1; j < size; j++)
    {
        temp = arr[j];
        int k = i;
        while ((arr[k] > temp) && (k >= 0))
        {
            arr[k + 1] = arr[k];
            k--;
        }
        arr[k + 1] = temp;
        i++;
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
    insertionSort(arr, size);
    printf("\n");
    for (int i = 0; i < size; i++)
    {
        printf("%d ", arr[i]);
    }

    return 0;
}