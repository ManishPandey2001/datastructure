// 8. IMPLEMENT THE OPERATIONS OF PRIORITY QUEUE IN AN STRING ARRAY (INSERT, DELETE, PEEK, ISEMPTY, ISFULL)
#include < stdio.h >
#define MAX 5            
#define STRING_LENGTH 100 
typedef struct PriorityQueue {
    char array[MAX][STRING_LENGTH]; 
    int size;                       
} PriorityQueue;


void initializeQueue(PriorityQueue* pq) {
    pq->size = 0;
}


int isEmpty(PriorityQueue* pq) {
    return (pq->size == 0);
}


int isFull(PriorityQueue* pq) {
    return (pq->size == MAX);
}


int stringCompare(const char* str1, const char* str2) {
    while (*str1 && *str2) {
        if (*str1 != *str2) {
            return (*str1 - *str2); 
        }
        str1++;
        str2++;
    }
    return (*str1 - *str2); 
}


void stringCopy(char* dest, const char* src) {
    while (*src) {
        *dest++ = *src++;
    }
    *dest = '\0'; 
}


void insert(PriorityQueue* pq, const char* value) {
    if (isFull(pq)) {
        printf("Priority Queue is full! Cannot insert \"%s\".\n", value);
        return;
    }

    int i = pq->size - 1;

    
    while (i >= 0 && stringCompare(pq->array[i], value) > 0) {
        stringCopy(pq->array[i + 1], pq->array[i]); 
        i--;
    }
    stringCopy(pq->array[i + 1], value);
    pq->size++;
    printf("\"%s\" inserted into the priority queue.\n", value);
}


char* delete(PriorityQueue* pq) {
    if (isEmpty(pq)) {
        printf("Priority Queue is empty! Cannot delete.\n");
        return NULL; 
    }

    char* value = pq->array[0]; 
    printf("\"%s\" deleted from the priority queue.\n", value);

   
    for (int i = 0; i < pq->size - 1; i++) {
        stringCopy(pq->array[i], pq->array[i + 1]);
    }
    pq->size--; 
    return value;
}


char* peek(PriorityQueue* pq) {
    if (isEmpty(pq)) {
        printf("Priority Queue is empty! Nothing to peek.\n");
        return NULL;
    }
    return pq->array[0]; 
}


int main() {
    PriorityQueue pq;
    initializeQueue(&pq);

    int choice;
    char value[STRING_LENGTH]; 
    do {
        printf("\nPriority Queue Operations Menu:\n");
        printf("1. Insert\n");
        printf("2. Delete\n");
        printf("3. Peek\n");
        printf("4. Check if Empty\n");
        printf("5. Check if Full\n");
        printf("6. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        getchar(); 

        switch (choice) {
            case 1: 
                printf("Enter string to insert: ");
                fgets(value, sizeof(value), stdin);
                value[stringCompare(value, "\n")] = 0; 
                insert(&pq, value);
                break;
            case 2: 
                delete(&pq);
                break;
            case 3: 
                {
                    char* frontValue = peek(&pq);
                    if (frontValue != NULL) {
                        printf("Highest priority element is: \"%s\"\n", frontValue);
                    }
                }
                break;
            case 4: 
                if (isEmpty(&pq)) {
                    printf("Priority Queue is empty.\n");
                } else {
                    printf("Priority Queue is not empty.\n");
                }
                break;
            case 5: 
                if (isFull(&pq)) {
                    printf("Priority Queue is full.\n");
                } else {
                    printf("Priority Queue is not full.\n");
                }
                break;
            case 6: 
                printf("Exiting...\n");
                break;
            default:
                printf("Invalid choice! Please try again.\n");
        }
    } while (choice != 6);

    return 0;
}

       

