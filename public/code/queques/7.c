// 7. IMPLEMENT THE OPERATIONS OF PRIORITY QUEUE IN AN INTEGER ARRAY (INSERT, DELETE, PEEK, ISEMPTY, ISFULL)
#include < stdio.h >
#include < stdlib.h >
#define MAX 5  

typedef struct PriorityQueue {
    int array[MAX]; 
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


void insert(PriorityQueue* pq, int value) {
    if (isFull(pq)) {
        printf("Priority Queue is full! Cannot insert %d.\n", value);
        return;
    }
    
    int i = pq->size - 1;

    
    while (i >= 0 && pq->array[i] < value) {
        pq->array[i + 1] = pq->array[i]; 
        i--;
    }
    pq->array[i + 1] = value; 
    pq->size++;
    printf("%d inserted into the priority queue.\n", value);
}


int delete(PriorityQueue* pq) {
    if (isEmpty(pq)) {
        printf("Priority Queue is empty! Cannot delete.\n");
        return -1; 
    }
    
    int value = pq->array[0]; 
    printf("%d deleted from the priority queue.\n", value);
    
   
    for (int i = 0; i < pq->size - 1; i++) {
        pq->array[i] = pq->array[i + 1];
    }
    pq->size--; 
    return value; 
}


int peek(PriorityQueue* pq) {
    if (isEmpty(pq)) {
        printf("Priority Queue is empty! Nothing to peek.\n");
        return -1; 
    }
    return pq->array[0];
}


int main() {
    PriorityQueue pq;
    initializeQueue(&pq);

    int choice, value;

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

        switch (choice) {
            case 1: 
                printf("Enter value to insert: ");
                scanf("%d", &value);
                insert(&pq, value);
                break;
            case 2: 
                delete(&pq);
                break;
            case 3: 
                value = peek(&pq);
                if (value != -1) {
                    printf("Highest priority element is: %d\n", value);
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


