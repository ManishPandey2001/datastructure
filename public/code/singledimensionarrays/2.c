// 2. Enter an array from user and print the array in reverse order ?
#include <stdio.h>
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
    for (int i = (size - 1); i >= 0; i--)
    {
        printf("%d ", arr[i]);
    }

    return 0;
}