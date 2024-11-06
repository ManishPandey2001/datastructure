// 15. ENTER A STRING ARRAY FROM THE USER AND PERFORM INSERTION SORT ALGORITHM THROUGH ITERATION. ALSO CALCULATE THE WORST AND BEST COMPLEXITY WITH EXACT TIME.
#include < stdio.h>
                     #include < time.h>
                
                  #define MAX_SIZE 100 
                  #define MAX_LENGTH 100 
                
                void insertion_sort(char arr[][MAX_LENGTH], int n) {
                    for (int i = 1; i < n; i++) {
                        char key[MAX_LENGTH];
                        strcpy(key, arr[i]);
                        int j = i - 1;
                
                        while (j >= 0 && strcmp(arr[j], key) > 0) {
                            strcpy(arr[j + 1], arr[j]);
                            j--;
                        }
                        strcpy(arr[j + 1], key);
                    }
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
                    insertion_sort(arr, n);
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
                    
        
        