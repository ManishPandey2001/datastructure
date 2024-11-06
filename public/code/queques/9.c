// 9. IMPLEMENT THE OPERATIONS OF DOUBLE ENDED QUEUE IN AN INTEGER ARRAY (INSERT, DELETE, PEEK, ISEMPTY, ISFULL)
#include < stdio.h >
#define MAX 5;
typedef struct Deque {
    int array[MAX]; 
    int front;      
    int rear;       
    int size;     
} Deque;


void initializeDeque(Deque* dq) {
    dq->front = -1;
    dq->rear = -1;
    dq->size = 0;
}


int isEmpty(Deque* dq) {
    return (dq->size == 0);
}


int isFull(Deque* dq) {
    return (dq->size == MAX);
}


void insertFront(Deque* dq, int value) {
    if (isFull(dq)) {
        printf("Deque is full! Cannot insert %d at front.\n", value);
        return;
    }
    
    if (isEmpty(dq)) {
        dq->front = dq->rear = 0; 
    } else {
        dq->front = (dq->front - 1 + MAX) % MAX; 
    }
    
    dq->array[dq->front] = value;
    dq->size++;
    printf("%d inserted at the front of the deque.\n", value);
}


void insertRear(Deque* dq, int value) {
    if (isFull(dq)) {
        printf("Deque is full! Cannot insert %d at rear.\n", value);
        return;
    }

    if (isEmpty(dq)) {
        dq->front = dq->rear = 0; 
    } else {
        dq->rear = (dq->rear + 1) % MAX; 
    }

    dq->array[dq->rear] = value;
    dq->size++;
    printf("%d inserted at the rear of the deque.\n", value);
}


int deleteFront(Deque* dq) {
    if (isEmpty(dq)) {
        printf("Deque is empty! Cannot delete from front.\n");
        return -1; // Return -1 if the deque is empty
    }

    int value = dq->array[dq->front];
    
    if (dq->front == dq->rear) {
        
        dq->front = dq->rear = -1;
    } else {
        dq->front = (dq->front + 1) % MAX; 
    }
    
    dq->size--;
    printf("%d deleted from the front of the deque.\n", value);
    return value;
}


int deleteRear(Deque* dq) {
    if (isEmpty(dq)) {
        printf("Deque is empty! Cannot delete from rear.\n");
        return -1; 
    }

    int value = dq->array[dq->rear];

    if (dq->front == dq->rear) {
        // Only one element was present
        dq->front = dq->rear = -1;
    } else {
        dq->rear = (dq->rear - 1 + MAX) % MAX; 
    }

    dq->size--;
    printf("%d deleted from the rear of the deque.\n", value);
    return value;
}


int peekFront(Deque* dq) {
    if (isEmpty(dq)) {
        printf("Deque is empty! Nothing to peek from front.\n");
        return -1; 
    }
    return dq->array[dq->front]; 
}


int peekRear(Deque* dq) {
    if (isEmpty(dq)) {
        printf("Deque is empty! Nothing to peek from rear.\n");
        return -1;
    }
    return dq->array[dq->rear];
}


int main() {
    Deque dq;
    initializeDeque(&dq);

    int choice, value;

    do {
        printf("\nDouble-Ended Queue Operations Menu:\n");
        printf("1. Insert at Front\n");
        printf("2. Insert at Rear\n");
        printf("3. Delete from Front\n");
        printf("4. Delete from Rear\n");
        printf("5. Peek Front\n");
        printf("6. Peek Rear\n");
        printf("7. Check if Empty\n");
        printf("8. Check if Full\n");
        printf("9. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1: 
                printf("Enter integer to insert at front: ");
                scanf("%d", &value);
                insertFront(&dq, value);
                break;
            case 2: 
                printf("Enter integer to insert at rear: ");
                scanf("%d", &value);
                insertRear(&dq, value);
                break;
            case 3: 
                deleteFront(&dq);
                break;
            case 4: 
                deleteRear(&dq);
                break;
            case 5: 
                {
                    int frontValue = peekFront(&dq);
                    if (frontValue != -1) {
                        printf("Front element is: %d\n", frontValue);
                    }
                }
                break;
            case 6: 
                {
                    int rearValue = peekRear(&dq);
                    if (rearValue != -1) {
                        printf("Rear element is: %d\n", rearValue);
                    }
                }
                break;
            case 7: 
                if (isEmpty(&dq)) {
                    printf("Deque is empty.\n");
                } else {
                    printf("Deque is not empty.\n");
                }
                break;
            case 8:
                if (isFull(&dq)) {
                    printf("Deque is full.\n");
                } else {
                    printf("Deque is not full.\n");
                }
                break;
            case 9:
                printf("Exiting...\n");
                break;
            default:
                printf("Invalid choice! Please try again.\n");
        }
    } while (choice != 9);

    return 0;
}
