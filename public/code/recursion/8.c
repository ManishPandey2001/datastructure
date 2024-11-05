8.FIND THE ARITHMETIC MEAN OF AN INTEGER ARRAY USING RECURSION.

#include <stdio.h>

float calculateSum(int arr[], int size) 
{
    if (size == 0) 
    {
        return 0;
    }
    return arr[size - 1] + calculateSum(arr, size - 1);
}

float calculateMean(int arr[], int size) 
{
    if (size == 0) 
    {
        return 0; // To avoid division by zero
    }
    float sum = calculateSum(arr, size);
    return sum / size;
}

int main() 
{
    int size, i;
    printf("Enter the number of elements in the array: ");
    scanf("%d", &size);
    int arr[size];
    printf("Enter %d elements:\n", size);
    for (i = 0; i < size; i++) 
    {
        scanf("%d", &arr[i]);
    }

    float mean = calculateMean(arr, size);
    printf("The arithmetic mean of the array is: %.2f\n", mean);
    
    return 0;
}

