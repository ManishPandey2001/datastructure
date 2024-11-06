// 11. IMPLEMENT THE OPERATIONS OF PRIORITY QUEUE DYNAMICALLY OF INTEGERS (INSERT, DELETE, PEEK, ISEMPTY, ISFULL)
#include < stdio.h >
#include < stdlib.h >

typedef struct Node {
    int data;                 
    int priority;             
    struct Node* next;     
} Node;

typedef struct PriorityQueue {
    Node* front;           
} PriorityQueue;


Node* createNode(int data, int priority) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->data = data;
    newNode->priority = priority;
    newNode->next = NULL;
    return newNode;
}


void initializeQueue(PriorityQueue* pq) {
    pq->front = NULL;
}


int isEmpty(PriorityQueue* pq) {
    return (pq->front == NULL);
}


void insert(PriorityQueue* pq, int data, int priority) {
    Node* newNode = createNode(data, priority);

    if (isEmpty(pq) || pq->front->priority < priority) {
        
        newNode->next = pq->front;
        pq->front = newNode;
    } else {
        
        Node* current = pq->front;
        while (current->next != NULL && current->next->priority >= priority) {
            current = current->next;
        }
        newNode->next = current->next;
        current->next = newNode;
    }

    printf("Inserted %d with priority %d\n", data, priority);
}


int delete(PriorityQueue* pq) {
    if (isEmpty(pq)) {
        printf("Priority queue is empty! Cannot delete.\n");
        return -1; 
    }

    Node* temp = pq->front;
    int deletedData = temp->data;
    pq->front = pq->front->next;
    free(temp); 

    printf("Deleted %d from the priority queue\n", deletedData);
    return deletedData;
}


int peek(PriorityQueue* pq) {
    if (isEmpty(pq)) {
        printf("Priority queue is empty! Nothing to peek.\n");
        return -1; 
    }

    return pq->front->data; 
}


int main() {
    PriorityQueue pq;
    initializeQueue(&pq);

    int choice, data, priority;

    do {
        printf("\nPriority Queue Operations Menu:\n");
        printf("1. Insert\n");
        printf("2. Delete\n");
        printf("3. Peek\n");
        printf("4. Check if Empty\n");
        printf("5. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1: 
                printf("Enter integer to insert: ");
                scanf("%d", &data);
                printf("Enter priority (higher number means higher priority): ");
                scanf("%d", &priority);
                insert(&pq, data, priority);
                break;
            case 2: 
                delete(&pq);
                break;
            case 3:
                {
                    int frontData = peek(&pq);
                    if (frontData != -1) {
                        printf("Highest priority element is: %d\n", frontData);
                    }
                }
                break;
            case 4: 
                if (isEmpty(&pq)) {
                    printf("Priority queue is empty.\n");
                } else {
                    printf("Priority queue is not empty.\n");
                }
                break;
            case 5: 
                printf("Exiting...\n");
                break;
            default:
                printf("Invalid choice! Please try again.\n");
        }
    } while (choice != 5);

  
    while (!isEmpty(&pq)) {
        delete(&pq);
    }

    return 0;
}

