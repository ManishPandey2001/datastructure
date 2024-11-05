// 3. Enter an array from user and copy the array into second array?
#include <stdio.h>
void display(int arr[], int size)
{
    for (int i = 0; i < size; i++)
    {
        printf("%d ", arr[i]);
    }
}
void copy(int source[], int destination[], int size)
{
    for (int i = 0; i < size; i++)
    {
        destination[i] = source[i];
    }
}
int main()
{
    int arr[100];
    int arr2[100];
    int size;
    printf("ENTER SIZE : ");
    scanf("%d", &size);
    for (int i = 0; i < size; i++)
    {
        printf("ENTER ELEMENT %d : ", i);
        scanf("%d", &arr[i]);
    }
    printf("Arr1 : ");
    display(arr, size);
    copy(arr, arr2, size);
    printf("\nArr2 : ");
    display(arr2, size);
    return 0;
}