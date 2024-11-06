// 12. IMPLEMENT THE OPERATIONS OF PRIORITY QUEUE DYNAMICALLY OF STRING (INSERT, DELETE, PEEK, ISEMPTY, ISFULL)
#include < stdio.h >
#include < stdlib.h >
typedef struct Node {
    char* data;                
    int priority;              
    struct Node* next;         
} Node;

// Priority Queue structure
typedef struct PriorityQueue {
    Node* front;              
} PriorityQueue;

Node* createNode(const char* data, int priority) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    
    
    newNode->data = (char*)malloc(100 * sizeof(char)); 
    int i = 0;
    while (data[i] != '\0' && i < 99) {
        newNode->data[i] = data[i];
        i++;
    }
    newNode->data[i] = '\0'; 
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


int isFull(PriorityQueue* pq) {
    return 0; 
}

void insert(PriorityQueue* pq, const char* data, int priority) {
    Node* newNode = createNode(data);

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

    printf("Inserted \"%s\" with priority %d\n", newNode->data, priority);
}


char* delete(PriorityQueue* pq) {
    if (isEmpty(pq)) {
        printf("Priority queue is empty! Cannot delete.\n");
        return NULL; 
    }

    Node* temp = pq->front;
    char* deletedData = temp->data; 
    pq->front = pq->front->next;
    free(temp);

    printf("Deleted \"%s\" from the priority queue\n", deletedData);
    return deletedData; 
}


char* peek(PriorityQueue* pq) {
    if (isEmpty(pq)) {
        printf("Priority queue is empty! Nothing to peek.\n");
        return NULL;
    }

    return pq->front->data;
}


int main() {
    PriorityQueue pq;
    initializeQueue(&pq);

    int choice, priority;
    char value[100]; 

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
                int index = 0;
                while ((value[index] = getchar()) != '\n' && index < 99) {
                    index++;
                }
                value[index] = '\0';
                printf("Enter priority (higher number means higher priority): ");
                scanf("%d", &priority);
                insert(&pq, value, priority);
                break;
            case 2: 
                delete(&pq);
                break;
            case 3: 
                {
                    char* frontData = peek(&pq);
                    if (frontData != NULL) {
                        printf("Highest priority element is: \"%s\"\n", frontData);
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
                if (isFull(&pq)) {
                    printf("Priority queue is full.\n");
                } else {
                    printf("Priority queue is not full (dynamic).\n");
                }
                break;
            case 6: 
                printf("Exiting...\n");
                break;
            default:
                printf("Invalid choice! Please try again.\n");
        }
    } while (choice != 6);

    
    while (!isEmpty(&pq)) {
        delete(&pq);
    }

    return 0;
}
