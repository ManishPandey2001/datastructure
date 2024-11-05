// 13. Enter an array from user and count the duplicate values?
#include <stdio.h>
int duplicate(int arr[], int size)
{
    int count = 0;
    for (int i = 0; i < ((size / 2) + 1); i++)
    {
        for (int j = (size - 1); j > i; j--)
        {
            if (arr[i] == arr[j])
            {
                count++;
            }
        }
    }
    return count;
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
    printf("%d DUPLICATES FOUND", duplicate(arr, size));
    return 0;
}