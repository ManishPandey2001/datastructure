// 17. Queue based approach for first non-repeating character in a stream
#include < stdio.h >
#include < stdlib.h >

#define MAX_CHAR 256 

void firstNonRepeatingCharacter(char stream[], int n) {
    int freq[MAX_CHAR] = {0}; 
    char* queue = (char*)malloc(n * sizeof(char));
    int front = 0; 
    int rear = -1; 
    for (int i = 0; i < n; i++) {
        char current = stream[i];
        freq[current]++; 

        
        if (freq[current] == 1) {
            queue[++rear] = current;
        }

        
        while (front <= rear && freq[queue[front]] > 1) {
            front++; 
        }

       
        if (front <= rear) {
            printf("%c ", queue[front]);
        } else {
            printf("-1 "); 
        }
    }
    printf("\n");

    free(queue); 
}

int main() {
    char stream1[] = {'a', 'a', 'b', 'c'};
    int n1 = sizeof(stream1) / sizeof(stream1[0]);
    printf("First non-repeating characters for stream1: ");
    firstNonRepeatingCharacter(stream1, n1);

    char stream2[] = {'a', 'a', 'c'};
    int n2 = sizeof(stream2) / sizeof(stream2[0]);
    printf("First non-repeating characters for stream2: ");
    firstNonRepeatingCharacter(stream2, n2);

    return 0;
}
