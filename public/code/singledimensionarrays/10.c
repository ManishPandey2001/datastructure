// 10. Enter an array from user and add all values ?
#include <stdio.h>
int sum(int arr[], int size)
{
    int sum = 0;
    for (int i = 0; i < size; i++)
    {
        sum += arr[i];
    }
    return sum;
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
    printf("SUM ARRAY ELEMENT : %d", sum(arr, size));
    return 0;
}