// 20. ENTER A STRING ARRAY FROM THE USER AND PERFORM QUICK SORT ALGORITHM THROUGH RECURSION. ALSO CALCULATE THE WORST AND BEST COMPLEXITY WITH EXACT TIME.
#include < stdio.h>
                    #include < time.h>
                
                #define MAX_SIZE 100
                #define MAX_LENGTH 100 
                
                void swap(char a[], char b[]) {
                    char temp[MAX_LENGTH];
                    for (int i = 0; i < MAX_LENGTH; i++) {
                        temp[i] = a[i];
                        a[i] = b[i];
                        b[i] = temp[i];
                    }
                }
                
                int partition(char arr[][MAX_LENGTH], int low, int high) {
                    char pivot[MAX_LENGTH];
                    for (int i = 0; i < MAX_LENGTH; i++) {
                        pivot[i] = arr[high][i];
                    }
                    
                    int i = (low - 1);
                    for (int j = low; j < high; j++) {
                        if (compare_strings(arr[j], pivot) <= 0) {
                            i++;
                            swap(arr[i], arr[j]);
                        }
                    }
                    swap(arr[i + 1], arr[high]);
                    return (i + 1);
                }
                
                void quick_sort_recursive(char arr[][MAX_LENGTH], int low, int high) {
                    if (low < high) {
                        int pivot_index = partition(arr, low, high);
                        quick_sort_recursive(arr, low, pivot_index - 1);
                        quick_sort_recursive(arr, pivot_index + 1, high);
                    }
                }
                
                int compare_strings(const char a[], const char b[]) {
                    int i = 0;
                    while (a[i] != '\0' && b[i] != '\0') {
                        if (a[i] < b[i]) return -1;
                        if (a[i] > b[i]) return 1;
                        i++;
                    }
                    return (a[i] == '\0') ? -1 : 1; // If one is longer
                }
                
                int main() {
                    int n;
                
                    printf("Enter the number of strings (max %d): ", MAX_SIZE);
                    scanf("%d", &n);
                    getchar(); // To consume the newline character left by scanf
                
                    if (n > MAX_SIZE) {
                        printf("Error: Number of strings exceeds maximum size.\n");
                        return 1;
                    }
                
                    char arr[MAX_SIZE][MAX_LENGTH];
                
                    printf("Enter %d strings:\n", n);
                    for (int i = 0; i < n; i++) {
                        fgets(arr[i], MAX_LENGTH, stdin);
                        arr[i][strcspn(arr[i], "\n")] = 0; // Remove the newline character
                    }
                
                    clock_t start = clock();
                    quick_sort_recursive(arr, 0, n - 1);
                    clock_t end = clock();
                
                    double time_taken = (double)(end - start) / CLOCKS_PER_SEC;
                
                    printf("Sorted strings:\n");
                    for (int i = 0; i < n; i++) {
                        printf("%s\n", arr[i]);
                    }
                
                    printf("Time taken for sorting: %f seconds\n", time_taken);
                    printf("\nQuick Sort Complexity:\n");
                    printf("Best Case: O(n log n).\n");
                    printf("Worst Case: O(n^2) when the pivot is the smallest or largest element repeatedly.\n");
                    printf("Average Case: O(n log n).\n");
                
                    return 0;
                }
                      
        
        
