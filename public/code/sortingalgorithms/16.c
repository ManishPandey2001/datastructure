// 16. ENTER A STRING ARRAY FROM THE USER AND PERFORM INSERTION SORT ALGORITHM THROUGH RECURSION. ALSO CALCULATE THE WORST AND BEST COMPLEXITY WITH EXACT TIME.
#include < stdio.h>
                 #include < time.h>
                
                #define MAX_SIZE 100 
                #define MAX_LENGTH 100 
                
                void copy_string(char dest[], const char src[]) {
                    int i = 0;
                    while (src[i] != '\0' && i < MAX_LENGTH) {
                        dest[i] = src[i];
                        i++;
                    }
                    dest[i] = '\0';
                }
                
                int compare_strings(const char a[], const char b[]) {
                    int i = 0;
                    while (a[i] != '\0' && b[i] != '\0') {
                        if (a[i] < b[i]) return -1;
                        if (a[i] > b[i]) return 1;
                        i++;
                    }
                    if (a[i] == '\0' && b[i] == '\0') return 0;
                    return (a[i] == '\0') ? -1 : 1; // If one is longer
                }
                
                void insertion_sort_recursive(char arr[][MAX_LENGTH], int n, int index) {
                    if (index >= n) return; // Base case
                
                    char key[MAX_LENGTH];
                    copy_string(key, arr[index]);
                    int j = index - 1;
                
                    while (j >= 0 && compare_strings(arr[j], key) > 0) {
                        copy_string(arr[j + 1], arr[j]);
                        j--;
                    }
                    copy_string(arr[j + 1], key);
                
                    // Recursive call for the next index
                    insertion_sort_recursive(arr, n, index + 1);
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
                    insertion_sort_recursive(arr, n, 1);
                    clock_t end = clock();
                
                    double time_taken = (double)(end - start) / CLOCKS_PER_SEC;
                
                    printf("Sorted strings:\n");
                    for (int i = 0; i < n; i++) {
                        printf("%s\n", arr[i]);
                    }
                
                    printf("Time taken for sorting: %f seconds\n", time_taken);
                    printf("\nInsertion Sort Complexity:\n");
                    printf("Best Case: O(n) when the array is already sorted.\n");
                    printf("Worst Case: O(n^2) when the array is sorted in reverse order.\n");
                    printf("Average Case: O(n^2).\n");
                
                    return 0;
                }
                     
        