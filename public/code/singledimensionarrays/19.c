// 19. Find the local maxima in the array? (An element in an array is a local maxima if it greater than the element after it, and the element before it)
#include <stdio.h>
void getArr(int arr[], int size)
{
    for (int i = 0; i < size; i++)
    {
        printf("ENTER ELEMENT %d : ", i);
        scanf("%d", arr + i);
    }
}
void maxima(int arr[], int size)
{
    for (int i = 1; i < (size - 1); i++)
    {
        if ((arr[i] > arr[i - 1]) && (arr[i] > arr[i + 1]))
        {
            printf("%d at %d index is a local maxima\n", arr[i], i);
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
    maxima(arr, size);
    return 0;
}