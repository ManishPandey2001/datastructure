// 15. Find the Next Greater Element
#include < stdio.h >
#include < stdlib.h >

void nextGreaterElement(int arr[], int n) {
    int* result = (int*)malloc(n * sizeof(int));
    int* stack = (int*)malloc(n * sizeof(int));  
    int top = -1; 

   
    for (int i = 0; i < n; i++) {
        result[i] = -1;
    }

    for (int i = 0; i < n; i++) {
       
        while (top != -1 && arr[i] > arr[stack[top]]) {
            result[stack[top]] = arr[i]; 
            top--; 
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
    int arr1[] = {1, 3, 2, 4};
    int n1 = sizeof(arr1) / sizeof(arr1[0]);
    printf("Next greater elements for arr1: ");
    nextGreaterElement(arr1, n1);

    int arr2[] = {6, 8, 0, 1, 3};
    int n2 = sizeof(arr2) / sizeof(arr2[0]);
    printf("Next greater elements for arr2: ");
    nextGreaterElement(arr2, n2);

    return 0;
}
