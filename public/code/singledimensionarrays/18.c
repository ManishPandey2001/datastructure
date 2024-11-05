// 18. Find the local minima in the array? (An element in an array is a local minima if it less than the element after it, and the element before it)
#include <stdio.h>
void getArr(int arr[], int size)
{
    for (int i = 0; i < size; i++)
    {
        printf("ENTER ELEMENT %d : ", i);
        scanf("%d", arr + i);
    }
}
void minima(int arr[], int size)
{
    for (int i = 1; i < (size - 1); i++)
    {
        if ((arr[i] < arr[i - 1]) && (arr[i] < arr[i + 1]))
        {
            printf("%d at %d index is a local minima\n", arr[i], i);
        }
    }
}
int main()
{
    int arr[100];
    int size;
    printf("Enter size of the array : ");
    scanf("%d", &size);
    getArr(arr, size);
    minima(arr, size);
    return 0;
}