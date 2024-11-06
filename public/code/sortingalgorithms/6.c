//6.code
#include < stdio.h>
                    #include < time.h>
                
                void insertion_sort_recursive(int arr[], int n) {
                    if (n <= 1) {
                        return;
                    }
                
                    insertion_sort_recursive(arr, n - 1);
                
                    int key = arr[n - 1];
                    int j = n - 2;
                
                    while (j >= 0 && arr[j] > key) {
                        arr[j + 1] = arr[j];
                        j--;
                    }
                    arr[j + 1] = key;
                }
                
                int main() {
                    int n;
                
                    printf("Enter the number of elements: ");
                    scanf("%d", &n);
                
                    int arr[n];
                
                    printf("Enter %d integers:\n", n);
                    for (int i = 0; i < n; i++) {
                        scanf("%d", &arr[i]);
                    }
                
                    clock_t start = clock();
                    insertion_sort_recursive(arr, n);
                    clock_t end = clock();
                
                    double time_taken = (double)(end - start) / CLOCKS_PER_SEC;
                
                    printf("Sorted array:\n");
                    for (int i = 0; i < n; i++) {
                        printf("%d ", arr[i]);
                    }
                    printf("\nTime taken for sorting: %f seconds\n", time_taken);
                
                    printf("\nInsertion Sort Complexity:\n");
                    printf("Best Case: O(n)\n");
                    printf("Worst Case: O(n^2)\n");
                    printf("Average Case: O(n^2)\n");
                
                    return 0;
                }
                       