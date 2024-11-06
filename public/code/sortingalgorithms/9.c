// 9. ENTER A INTEGER ARRAY FROM THE USER AND PERFORM QUICK SORT ALGORITHM THROUGH ITERATION. ALSO CALCULATE THE WORST AND BEST COMPLEXITY WITH EXACT TIME.
#include < stdio.h>
                    #include < time.h>
                
                      #define MAX_SIZE 1000
                
                void swap(int* a, int* b) {
                    int temp = *a;
                    *a = *b;
                    *b = temp;
                }
                
                int partition(int arr[], int low, int high) {
                    int pivot = arr[high];
                    int i = (low - 1);
                    
                    for (int j = low; j < high; j++) {
                        if (arr[j] <= pivot) {
                            i++;
                            swap(&arr[i], &arr[j]);
                        }
                    }
                    swap(&arr[i + 1], &arr[high]);
                    return (i + 1);
                }
                
                void quick_sort_iterative(int arr[], int n) {
                    int stack[MAX_SIZE];
                    int top = -1;
                
                    stack[++top] = 0;
                    stack[++top] = n - 1;
                
                    while (top >= 0) {
                        int high = stack[top--];
                        int low = stack[top--];
                
                        int pivot_index = partition(arr, low, high);
                
                        if (pivot_index - 1 > low) {
                            stack[++top] = low;
                            stack[++top] = pivot_index - 1;
                        }
                        if (pivot_index + 1 < high) {
                            stack[++top] = pivot_index + 1;
                            stack[++top] = high;
                        }
                    }
                }
                
                int main() {
                    int n;
                
                    printf("Enter the number of elements (max %d): ", MAX_SIZE);
                    scanf("%d", &n);
                
                    if (n > MAX_SIZE) {
                        printf("Error: Number of elements exceeds maximum size.\n");
                        return 1;
                    }
                
                    int arr[MAX_SIZE];
                
                    printf("Enter %d integers:\n", n);
                    for (int i = 0; i < n; i++) {
                        scanf("%d", &arr[i]);
                    }
                
                    clock_t start = clock();
                    quick_sort_iterative(arr, n);
                    clock_t end = clock();
                
                    double time_taken = (double)(end - start) / CLOCKS_PER_SEC;
                
                    printf("Sorted array:\n");
                    for (int i = 0; i < n; i++) {
                        printf("%d ", arr[i]);
                    }
                    printf("\nTime taken for sorting: %f seconds\n", time_taken);
                
                    printf("\nQuicksort Complexity:\n");
                    printf("Best Case: O(n log n)\n");
                    printf("Worst Case: O(n^2)\n");
                    printf("Average Case: O(n log n)\n");
                
                    return 0;
                }
                
        