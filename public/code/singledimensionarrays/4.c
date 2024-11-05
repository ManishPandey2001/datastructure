// 4. Enter an array from user and copy it into another array in reverse order?
#include <stdio.h>
void display(int arr[], int size)
{
    for (int i = 0; i < size; i++)
    {
        printf("%d ", arr[i]);
    }
}
void rcopy(int source[], int destination[], int size)
{
    for (int i = 0; i < size; i++)
    {
        destination[i] = source[size - i - 1];
    }
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
    int arr2[100];
    int size;
    printf("ENTER SIZE : ");
    scanf("%d", &size);
    getArr(arr, size);
    printf("Arr1 : ");
    display(arr, size);
    rcopy(arr, arr2, size);
    printf("\nArr2 : ");
    display(arr2, size);
    return 0;
}