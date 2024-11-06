// 16. Find Next Smaller Element
#include < stdio.h >
#include < stdlib.h >

void nextSmallerElement(int arr[], int n) {
    int* result = (int*)malloc(n * sizeof(int)); 
    int* stack = (int*)malloc(n * sizeof(int));  
    int top = -1; // Stack top pointer

    
    for (int i = 0; i < n; i++) {
        result[i] = -1;
    }

    for (int i = 0; i < n; i++) {
     
        while (top != -1 && arr[i] < arr[stack[top]]) {
            result[stack[top]] = arr[i]; 
            top--; // Pop the top index
        }
       
        stack[++top] = i;
    }

   
    for (int i = 0; i < n; i++) {
        printf("%d ", result[i]);
    }
    printf("\n");

    free(result); 
    free(stack); 
}


int main() {
    int arr1[] = {4, 8, 5, 2, 25};
    int n1 = sizeof(arr1) / sizeof(arr1[0]);
    printf("Next smaller elements for arr1: ");
    nextSmallerElement(arr1, n1);

    int arr2[] = {13, 7, 6, 12};
    int n2 = sizeof(arr2) / sizeof(arr2[0]);
    printf("Next smaller elements for arr2: ");
    nextSmallerElement(arr2, n2);

    return 0;
}
