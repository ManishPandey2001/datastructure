// 8. Enter an array from user and find maximum and minimum value?
#include <stdio.h>
int max(int arr[], int size)
{
    int max = arr[0];
    for (int i = 0; i < size; i++)
    {
        if (arr[i] > max)
        {
            max = arr[i];
        }
    }
    return max;
}
int min(int arr[], int size)
{
    int min = arr[0];
    for (int i = 0; i < size; i++)
    {
        if (arr[i] < min)
        {
            min = arr[i];
        }
    }
    return min;
}
void getArr(int arr[], int size)
{
    for (int i = 0; i < size; i++)
    {
        printf("ENTER ELEMENT %d : ", i);
        scanf("%d", arr + i);
    }
}
int main()
{
    int arr[100];
    int size;
    printf("ENTER SIZE : ");
    scanf("%d", &size);
    getArr(arr, size);
    printf("%d", max(arr, size));
    printf("\n%d", min(arr, size));
    return 0;
}