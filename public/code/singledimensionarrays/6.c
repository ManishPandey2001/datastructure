// 6. Enter an array from user and print the number which is positive ?
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
    for (int i = 0; i < size; i++)
    {
        if (arr[i] > 0)
        {
            printf("%d ", arr[i]);
        }
    }

    return 0;
}