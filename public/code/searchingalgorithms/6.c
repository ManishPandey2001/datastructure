// 6. ENTER A STRING FROM THE USER, ENTER A CHARACTER AND PERFORM BINARY SEARCH ALGORITHM THROUGH RECURSION.
#include <stdio.h>
#define maxSize 100
int binarySearch(char arr[], char ele, int low, int high)
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
    char arr[maxSize];
    int size;
    char search;
    char result;
    printf("ENTER SIZE OF ARRAY : ");
    scanf("%d", &size);
    fflush(stdin);
    for (int i = 0; i < size; i++)
    {
        printf("ENTER ELEMENT %d : ", i);
        scanf("%c", &arr[i]);
        fflush(stdin);
    }
    printf("ENTER ELEMENT TO BE SEARCHED : ");
    scanf("%c", &search);
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