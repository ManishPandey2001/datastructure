// 18. Reverse First K elements of Queue
#include < stdio.h >
#include < stdlib.h >

typedef struct Queue {
    int* arr;
    int front;
    int rear;
    int size;
    int capacity;
} Queue;


Queue* createQueue(int capacity) {
    Queue* queue = (Queue*)malloc(sizeof(Queue));
    queue->capacity = capacity;
    queue->front = 0;
    queue->size = 0;
    queue->rear = capacity - 1;
    queue->arr = (int*)malloc(queue->capacity * sizeof(int));
    return queue;
}


int isFull(Queue* queue) {
    return (queue->size == queue->capacity);
}

int isEmpty(Queue* queue) {
    return (queue->size == 0);
}

void enqueue(Queue* queue, int item) {
    if (isFull(queue)) return;
    queue->rear = (queue->rear + 1) % queue->capacity;
    queue->arr[queue->rear] = item;
    queue->size++;
}

int dequeue(Queue* queue) {
    if (isEmpty(queue)) return -1;
    int item = queue->arr[queue->front];
    queue->front = (queue->front + 1) % queue->capacity;
    queue->size--;
    return item;
}

int front(Queue* queue) {
    if (isEmpty(queue)) return -1;
    return queue->arr[queue->front];
}


void reverseFirstKElements(Queue* queue, int K) {
    if (isEmpty(queue) || K > queue->size) return;

    
    int* stack = (int*)malloc(K * sizeof(int));
    int count = 0;

   
    while (count < K && !isEmpty(queue)) {
        stack[count++] = dequeue(queue);
    }

 
    for (int i = count - 1; i >= 0; i--) {
        enqueue(queue, stack[i]);
    }

  
    for (int i = 0; i < queue->size - count; i++) {
        enqueue(queue, dequeue(queue));
    }

    free(stack); 
}


void printQueue(Queue* queue) {
    for (int i = 0; i < queue->size; i++) {
        printf("%d ", queue->arr[(queue->front + i) % queue->capacity]);
    }
    printf("\n");
}


int main() {
    Queue* queue = createQueue(100);
    int K;

    int arr1[] = {5, 3, 1, 2, 3, 4, 5};
    K = 3;
    for (int i = 0; i < sizeof(arr1) / sizeof(arr1[0]); i++) {
        enqueue(queue, arr1[i]);
    }
    printf("Original Queue: ");
    printQueue(queue);
    reverseFirstKElements(queue, K);
    printf("Queue after reversing first %d elements: ", K);
    printQueue(queue);

  
    free(queue->arr);
    free(queue);
    queue = createQueue(100);

   
    int arr2[] = {4, 4, 4, 3, 2, 1};
    K = 4;
    for (int i = 0; i < sizeof(arr2) / sizeof(arr2[0]); i++) {
        enqueue(queue, arr2[i]);
    }
    printf("Original Queue: ");
    printQueue(queue);
    reverseFirstKElements(queue, K);
    printf("Queue after reversing first %d elements: ", K);
    printQueue(queue);

    free(queue->arr);
    free(queue);
    return 0;
}

