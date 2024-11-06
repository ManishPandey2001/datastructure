// 7. ENTER A INTEGER ARRAY FROM THE USER AND PERFORM MERGE SORT ALGORITHM THROUGH ITERATION. ALSO CALCULATE THE WORST AND BEST COMPLEXITY WITH EXACT TIME.
#include < stdio.h>
                     #include < time.h>
                
                #define MAX_SIZE 1000 // Define a maximum size for the array
                
                void merge(int arr[], int left, int mid, int right, int temp[]) {
                    int i = left;
                    int j = mid + 1;
                    int k = left;
                
                    while (i <= mid && j <= right) {
                        if (arr[i] <= arr[j]) {
                            temp[k] = arr[i];
                            i++;
                        } else {
                            temp[k] = arr[j];
                            j++;
                        }
                        k++;
                    }
                
                    while (i <= mid) {
                        temp[k] = arr[i];
                        i++;
                        k++;
                    }
                
                    while (j <= right) {
                        temp[k] = arr[j];
                        j++;
                        k++;
                    }
                
                    for (i = left; i <= right; i++) {
                        arr[i] = temp[i];
                    }
                }
                
                void merge_sort_iterative(int arr[], int n) {
                    int temp[MAX_SIZE]; // Auxiliary array for merging
                    int current_size;
                    int left_start;
                
                    for (current_size = 1; current_size < n; current_size *= 2) {
                        for (left_start = 0; left_start < n - 1; left_start += 2 * current_size) {
                            int mid = left_start + current_size - 1;
                            int right_end = (left_start + 2 * current_size - 1 < n - 1) ? left_start + 2 * current_size - 1 : n - 1;
                
                            merge(arr, left_start, mid, right_end, temp);
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
                    merge_sort_iterative(arr, n);
                    clock_t end = clock();
                
                    double time_taken = (double)(end - start) / CLOCKS_PER_SEC;
                
                    printf("Sorted array:\n");
                    for (int i = 0; i < n; i++) {
                        printf("%d ", arr[i]);
                    }
                    printf("\nTime taken for sorting: %f seconds\n", time_taken);
                
                    printf("\nMerge Sort Complexity:\n");
                    printf("Best Case: O(n log n)\n");
                    printf("Worst Case: O(n log n)\n");
                    printf("Average Case: O(n log n)\n");
                
                    return 0;
                }
                     
        
        