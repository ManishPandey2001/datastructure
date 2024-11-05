// 17. Merge the two sorted arrays into one array but in sorted order?
#include <stdio.h>
void getArr(int arr[], int size)
{
    for (int i = 0; i < size; i++)
    {
        printf("ENTER ELEMENT %d : ", i);
        scanf("%d", arr + i);
    }
}
void display(int arr[], int size)
{
    for (int i = 0; i < size; i++)
    {
        printf("%d ", arr[i]);
    }
    printf("\n");
}
void sort(int arr1[], int size1, int arr2[], int size2, int result[])
{
    int i = 0, j = 0;
    for (int k = 0; k < (size1 + size2); k++)
    {
        if ((arr1[i] < arr2[j]) && (i < size1))
        {
            result[k] = arr1[i++];
        }
        else
        {
            result[k] = arr2[j++];
        }
    }
}
int main()
{
    int arr1[100], arr2[100];
    int size1, size2;
    int result[200];
    printf("Enter size of array 1: ");
    scanf("%d", &size1);
    getArr(arr1, size1);
    printf("Enter size of array 2: ");
    scanf("%d", &size2);
    getArr(arr2, size2);
    sort(arr1, size1, arr2, size2, result);
    printf("Array 1 : ");
    display(arr1, size1);
    printf("Array 2 : ");
    display(arr2, size2);
    printf("Result : ");
    display(result, size1 + size2);
    return 0;
}