// 11. Enter an array from user and find the duplicate values?
#include <stdio.h>
void duplicate(int arr[], int size)
{
    for (int i = 0; i < ((size / 2) + 1); i++)
    {
        for (int j = (size - 1); j > i; j--)
        {
            if (arr[i] == arr[j])
            {
                printf("DUPLICATE %d\n", arr[i]);
            }
        }
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
    duplicate(arr, size);
    return 0;
}