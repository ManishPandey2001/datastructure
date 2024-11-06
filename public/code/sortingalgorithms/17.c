// 17. ENTER A STRING ARRAY FROM THE USER AND PERFORM MERGE SORT ALGORITHM THROUGH ITERATION. ALSO CALCULATE THE WORST AND BEST COMPLEXITY WITH EXACT TIME.
#include < stdio.h>
                    #include < time.h>
                
                #define MAX_SIZE 100 // Maximum number of strings
                #define MAX_LENGTH 100 // Maximum length of each string
                
                void merge(char arr[][MAX_LENGTH], int left, int mid, int right) {
                    int i, j, k;
                    int n1 = mid - left + 1;
                    int n2 = right - mid;
                
                    char L[MAX_SIZE][MAX_LENGTH], R[MAX_SIZE][MAX_LENGTH];
                
                    for (i = 0; i < n1; i++)
                        strcpy(L[i], arr[left + i]);
                    for (j = 0; j < n2; j++)
                        strcpy(R[j], arr[mid + 1 + j]);
                
                    i = 0;
                    j = 0;
                    k = left;
                
                    while (i < n1 && j < n2) {
                        if (compare_strings(L[i], R[j]) <= 0) {
                            strcpy(arr[k], L[i]);
                            i++;
                        } else {
                            strcpy(arr[k], R[j]);
                            j++;
                        }
                        k++;
                    }
                
                    while (i < n1) {
                        strcpy(arr[k], L[i]);
                        i++;
                        k++;
                    }
                
                    while (j < n2) {
                        strcpy(arr[k], R[j]);
                        j++;
                        k++;
                    }
                }
                
                void merge_sort_iterative(char arr[][MAX_LENGTH], int n) {
                    int curr_size;
                    int left_start;
                
                    for (curr_size = 1; curr_size < n; curr_size *= 2) {
                        for (left_start = 0; left_start < n - 1; left_start += 2 * curr_size) {
                            int mid = left_start + curr_size - 1;
                            int right_end = ((left_start + 2 * curr_size - 1) < (n - 1)) ? (left_start + 2 * curr_size - 1) : (n - 1);
                
                            if (mid < right_end)
                                merge(arr, left_start, mid, right_end);
                        }
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
                    merge_sort_iterative(arr, n);
                    clock_t end = clock();
                
                    double time_taken = (double)(end - start) / CLOCKS_PER_SEC;
                
                    printf("Sorted strings:\n");
                    for (int i = 0; i < n; i++) {
                        printf("%s\n", arr[i]);
                    }
                
                    printf("Time taken for sorting: %f seconds\n", time_taken);
                    printf("\nMerge Sort Complexity:\n");
                    printf("Best Case: O(n log n).\n");
                    printf("Worst Case: O(n log n).\n");
                    printf("Average Case: O(n log n).\n");
                
                    return 0;
                }
                     
        
        