// 3. ENTER A INTEGER ARRAY FROM THE USER, ENTER AN INTEGER VALUE AND PERFORM LINEAR SEARCH ALGORITHM THROUGH RECURSION.
#include <stdio.h>
#define maxSize 100
int linearSearch(int arr[], int size, int ele, int index)
{
    if (arr[index] == ele)
    {
        return index;
    }
    else if (index == size)
    {
        return -1;
    }
    else
    {
        linearSearch(arr, size, ele, index + 1);
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
    for (int i = 0; i < size; i++)
    {
        printf("ENTER ELEMENT %d : ", i);
        scanf("%d", &arr[i]);
    }
    printf("ENTER ELEMENT TO BE SEARCHED : ");
    scanf("%d", &search);
    result = linearSearch(arr, size, search, 0);
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