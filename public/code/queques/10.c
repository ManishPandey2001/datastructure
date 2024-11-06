// 10. IMPLEMENT THE OPERATIONS OF DOUBLE ENDED QUEUE IN AN STRING ARRAY (INSERT, DELETE, PEEK, ISEMPTY, ISFULL)
#include < stdio.h >

#define MAX 5           
#define STRING_LENGTH 100 

typedef struct Deque {
    char array[MAX][STRING_LENGTH]; 
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


void stringCopy(char* dest, const char* src) {
    while (*src) {
        *dest++ = *src++;
    }
    *dest = '\0'; 
}


void insertFront(Deque* dq, const char* value) {
    if (isFull(dq)) {
        printf("Deque is full! Cannot insert \"%s\" at front.\n", value);
        return;
    }

    if (isEmpty(dq)) {
        dq->front = dq->rear = 0;
    } else {
        dq->front = (dq->front - 1 + MAX) % MAX; 
    }

    stringCopy(dq->array[dq->front], value); 
    dq->size++;
    printf("\"%s\" inserted at the front of the deque.\n", value);
}


void insertRear(Deque* dq, const char* value) {
    if (isFull(dq)) {
        printf("Deque is full! Cannot insert \"%s\" at rear.\n", value);
        return;
    }

    if (isEmpty(dq)) {
        dq->front = dq->rear = 0; 
    } else {
        dq->rear = (dq->rear + 1) % MAX; 
    }

    stringCopy(dq->array[dq->rear], value); 
    dq->size++;
    printf("\"%s\" inserted at the rear of the deque.\n", value);
}


char* deleteFront(Deque* dq) {
    if (isEmpty(dq)) {
        printf("Deque is empty! Cannot delete from front.\n");
        return NULL; 
    }

    char* value = dq->array[dq->front]; 

    if (dq->front == dq->rear) {
        
        dq->front = dq->rear = -1;
    } else {
        dq->front = (dq->front + 1) % MAX; 
    }

    dq->size--;
    printf("\"%s\" deleted from the front of the deque.\n", value);
    return value; 
}


char* deleteRear(Deque* dq) {
    if (isEmpty(dq)) {
        printf("Deque is empty! Cannot delete from rear.\n");
        return NULL; 
    }

    char* value = dq->array[dq->rear]; 

    if (dq->front == dq->rear) {
       
        dq->front = dq->rear = -1;
    } else {
        dq->rear = (dq->rear - 1 + MAX) % MAX; 
    }

    dq->size--;
    printf("\"%s\" deleted from the rear of the deque.\n", value);
    return value; 
}


char* peekFront(Deque* dq) {
    if (isEmpty(dq)) {
        printf("Deque is empty! Nothing to peek from front.\n");
        return NULL; 
    }
    return dq->array[dq->front]; 
}


char* peekRear(Deque* dq) {
    if (isEmpty(dq)) {
        printf("Deque is empty! Nothing to peek from rear.\n");
        return NULL; 
    }
    return dq->array[dq->rear]; 
}


int main() {
    Deque dq;
    initializeDeque(&dq);

    int choice;
    char value[STRING_LENGTH]; 

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
        getchar(); 
        switch (choice) {
            case 1: 
                printf("Enter string to insert at front: ");
                fgets(value, sizeof(value), stdin);
                
                value[strcspn(value, "\n")] = 0; 
                insertFront(&dq, value);
                break;
            case 2: 
                printf("Enter string to insert at rear: ");
                fgets(value, sizeof(value), stdin);
                
                value[strcspn(value, "\n")] = 0; 
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
                    char* frontValue = peekFront(&dq);
                    if (frontValue != NULL) {
                        printf("Front element is: \"%s\"\n", frontValue);
                    }
                }
                break;
            case 6: 
                {
                    char* rearValue = peekRear(&dq);
                    if (rearValue != NULL) {
                        printf("Rear element is: \"%s\"\n", rearValue);
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
