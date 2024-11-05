// 10. CALCULATE THE BEST AND WORST COMPLEXITY OF THE BINARY SEARCHING ALGORITHM WITH EXACT TIME TAKEN BY THE ALGORITHM ON INTEGER ARRAY.
#include <stdio.h>
#include <time.h>
#define maxSize 100
int binarySearch(int arr[], int size, int ele)
{
    int low = 0, high = size - 1, mid;
    while (low <= high)
    {
        mid = (high + low) / 2;
        if (arr[mid] == ele)
        {
            return mid;
        }
        else
        {
            if (arr[mid] > ele)
            {
                high = mid - 1;
            }
            else
            {
                low = mid + 1;
            }
        }
    }
    return -1;
}
int main()
{
    int arr[maxSize];
    int size;
    int search;
    int result;
    clock_t start, end;
    printf("ENTER SIZE OF ARRAY : ");
    scanf("%d", &size);
    for (int i = 0; i < size; i++)
    {
        printf("ENTER ELEMENT %d : ", i);
        scanf("%d", &arr[i]);
    }
    printf("ENTER ELEMENT TO BE SEARCHED : ");
    scanf("%d", &search);
    start = clock();
    result = binarySearch(arr, size, search);
    if (result >= 0)
    {
        printf("ELEMENT FOUND AT INDEX %d\n", result);
    }
    else
    {
        printf("ELEMENT NOT FOUND\n");
    }
    end = clock();
    printf("Executed in %fs\n", (double)(end - start) / CLOCKS_PER_SEC);
    return 0;
}