// 2. ENTER A STRING FROM THE USER, ENTER A CHARACTER AND PERFORM LINEAR SEARCH ALGORITHM THROUGH RECURSION.
#include <stdio.h>
#define maxSize 100
int linearSearch(char arr[], int size, char ele, int index)
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