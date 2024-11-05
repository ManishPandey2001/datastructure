// 7. ENTER A INTEGER ARRAY FROM THE USER, ENTER AN INTEGER VALUE AND PERFORM BINARY SEARCH ALGORITHM THROUGH RECURSION.
#include <stdio.h>
#define maxSize 100
int binarySearch(int arr[], int ele, int low, int high)
{
    if (low > high)
    {
        return -1;
    }
    else
    {
        int mid = ((high - low) / 2) + low;
        // ALTERNATIVE APPROACH FOR (HIGH+LOW)/2 -> AVOIDS POSSIBLE MEMORY OVERFLOW OF (HIGH+LOW)
        // HIGH/2 - LOW/2 + LOW = HIGH/2 + LOW/2
        if (arr[mid] == ele)
        {
            return mid;
        }
        else
        {
            if (arr[mid] > ele)
            {
                binarySearch(arr, ele, low, mid - 1);
            }
            else
            {
                binarySearch(arr, ele, mid + 1, high);
            }
        }
    }
}
int main()
{
    int arr[maxSize];
    int size;
    int search;
    int result;
    printf("ENTER SIZE OF ARRAY : ");
    scanf("%d", &size);
    fflush(stdin);
    for (int i = 0; i < size; i++)
    {
        printf("ENTER ELEMENT %d : ", i);
        scanf("%d", &arr[i]);
        fflush(stdin);
    }
    printf("ENTER ELEMENT TO BE SEARCHED : ");
    scanf("%d", &search);
    result = binarySearch(arr, search, 0, size - 1);
    if (result >= 0)
    {
        printf("ELEMENT FOUND AT INDEX %d", result);
    }
    else
    {
        printf("ELEMENT NOT FOUND");
    }
    return 0;
}