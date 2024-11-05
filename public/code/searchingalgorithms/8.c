// 8. ENTER A STRING FROM THE USER, ENTER A CHARACTER AND PERFORM BINARY SEARCH ALGORITHM THROUGH ITERATION.
#include <stdio.h>
#define maxSize 100
int binarySearch(char arr[], char ele, int size)
{
    int high = size - 1, low = 0, mid;
    while (high >= low)
    {
        mid = ((high - low) / 2) + low;
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
    result = binarySearch(arr, search, size);
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