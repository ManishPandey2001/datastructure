// 9. Enter an array from user and find the k-th smallest value?
#include <stdio.h>
void insertionSort(int arr[], int size)
{
    int temp;
    int i = 0;
    for (int j = i + 1; j < size; j++)
    {
        temp = arr[j];
        int k = i;
        while ((arr[k] > temp) && (k >= 0))
        {
            arr[k + 1] = arr[k];
            k--;
        }
        arr[k + 1] = temp;
        i++;
    }
}
int min(int arr[], int size, int pos)
{
    insertionSort(arr, size);
    return arr[pos - 1];
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
    int size;
    int pos;
    printf("ENTER SIZE : ");
    scanf("%d", &size);
    getArr(arr, size);
    printf("ENTER POSITION FROM SMALLEST : ");
    scanf("%d", &pos);
    printf("%d", min(arr, size, pos));
    return 0;
}