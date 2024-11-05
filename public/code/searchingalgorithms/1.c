// 1. ENTER A INTEGER ARRAY FROM THE USER, ENTER AN INTEGER VALUE AND PERFORM LINEAR SEARCH ALGORITHM THROUGH ITERATION.
#include <stdio.h>
#define maxSize 100
int linearSearch(int arr[], int size, int ele)
{
    for (int i = 0; i < size; i++)
    {
        if (arr[i] == ele)
        {
            return i;
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
    printf("ENTER SIZE OF ARRAY : ");
    scanf("%d", &size);
    for (int i = 0; i < size; i++)
    {
        printf("ENTER ELEMENT %d : ", i);
        scanf("%d", &arr[i]);
    }
    printf("ENTER ELEMENT TO BE SEARCHED : ");
    scanf("%d", &search);
    result = linearSearch(arr, size, search);
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