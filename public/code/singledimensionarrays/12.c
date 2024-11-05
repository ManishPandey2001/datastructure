// 12. Enter an array from user and remove the duplicate values and fill with zero?
#include <stdio.h>
void duplicate(int arr[], int size)
{
    for (int i = 0; i < ((size / 2) + 1); i++)
    {
        for (int j = (size - 1); j > i; j--)
        {
            if (arr[i] == arr[j])
            {
                arr[j] = 0;
            }
        }
    }
}
void display(int arr[], int size)
{
    for (int i = 0; i < size; i++)
    {
        printf("%d ", arr[i]);
    }
}
int main()
{
    int arr[100];
    int size;
    printf("ENTER SIZE : ");
    scanf("%d", &size);
    for (int i = 0; i < size; i++)
    {
        printf("ENTER ELEMENT %d : ", i);
        scanf("%d", &arr[i]);
    }
    printf("ARR : ");
    display(arr, size);
    duplicate(arr, size);
    printf("\nARR : ");
    display(arr, size);
    return 0;
}