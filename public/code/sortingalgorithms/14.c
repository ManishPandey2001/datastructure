// 14. ENTER A STRING ARRAY FROM THE USER AND PERFORM BUBBLE SORT ALGORITHM THROUGH RECURSION. ALSO CALCULATE THE WORST AND BEST COMPLEXITY WITH EXACT TIME.
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
                
                int compare_strings(char a[], char b[]) {
                    for (int i = 0; i < MAX_LENGTH; i++) {
                        if (a[i] < b[i]) return -1;
                        if (a[i] > b[i]) return 1;
                        if (a[i] == '\0') break;
                    }
                    return 0;
                }
                
                void bubble_sort_recursive(char arr[][MAX_LENGTH], int n, int i) {
                    if (i == n - 1) return; // Base case
                
                    for (int j = 0; j < n - 1 - i; j++) {
                        if (compare_strings(arr[j], arr[j + 1]) > 0) {
                            swap(arr[j], arr[j + 1]);
                        }
                    }
                    
                    bubble_sort_recursive(arr, n, i + 1); // Recursive call
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
                    bubble_sort_recursive(arr, n, 0);
                    clock_t end = clock();
                
                    double time_taken = (double)(end - start) / CLOCKS_PER_SEC;
                
                    printf("Sorted strings:\n");
                    for (int i = 0; i < n; i++) {
                        printf("%s\n", arr[i]);
                    }
                
                    printf("Time taken for sorting: %f seconds\n", time_taken);
                    printf("\nBubble Sort Complexity:\n");
                    printf("Best Case: O(n) when the array is already sorted.\n");
                    printf("Worst Case: O(n^2) when the array is sorted in reverse order.\n");
                    printf("Average Case: O(n^2).\n");
                
                    return 0;
                }
                