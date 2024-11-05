//5.FIND THE LARGEST ELEMENT IN THE INTEGER ARRAY USING RECURSION.

#include <stdio.h>

int findLargest(int arr[], int size) 
{
    if (size == 1) 
    {
        return arr[0];
    }
    
    int largest = findLargest(arr, size - 1);
    return arr[size - 1] > largest ? arr[size - 1] : largest;
}

int main() 
{
    int arr[] = {3, 5, 7, 2, 8, 1, 4};
    int size = sizeof(arr) / sizeof(arr[0]);
    
    int largest = findLargest(arr, size);
    printf("The largest element in the array is: %d\n", largest);
    
    return 0;
}
