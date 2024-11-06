
3. CREATE A STACK IMPLEMENTING THE OPERATIONS ON AN INTEGER NODES (DYNAMICALLY) 
(PUSH, POP, PEEK, ISEMPTY, ISFULL)

#include <stdio.h>
#include <stdlib.h>

struct stack {
    int max;
    int top;
    int *array;
};

struct stack s1;

void inti() { 
    printf("\nEnter the max (size of the array): ");
    scanf("%d", &s1.max);
    s1.array = (int *)malloc(sizeof(int) * s1.max);
    s1.top = -1;
    printf("\nThe stack is created. Insert the items.");
}

void push() {
    int item;
    if (s1.top == s1.max - 1) {
        printf("\nThe stack is overflow");
        return;
    }
    printf("\nEnter the item to insert: ");
    scanf("%d", &item);
    s1.top++;
    s1.array[s1.top] = item;
    printf("\nThe item %d is inserted at arr[%d] index", item, s1.top);
}

void pop() {
    int i;
    if (s1.top == -1) {
        printf("Underflow stack");
        return;
    }
    s1.array[s1.top] = 0;
    for (i = s1.top; i >= 0; i--) {
        printf("%d\t", s1.array[i]);
    } 
    s1.top--;
    printf("The item is popped from the stack");
}

void peak() {
    if (s1.top == -1) {
        printf("Underflow stack");
        return;
    }
    printf("The top item %d in the stack is at arr[%d]", s1.array[s1.top], s1.top);
}

void isempty() {
    if (s1.top == -1) {
        printf("Stack is empty.\n");
    } else {
        printf("Stack is not empty.\n");
    }
}

void isfull() {
    if (s1.top == s1.max - 1) {
        printf("Stack is full.\n");
    } else {
        printf("Stack is not full.\n");
    }
}

int main() {
    int choice;
    while (1) {
        printf("\n1. Initialize Stack");
        printf("\n2. Push");
        printf("\n3. Pop");
        printf("\n4. Peek");
        printf("\n5. Is Empty");
        printf("\n6. Is Full");
        printf("\n7. Exit");
        printf("\n\nEnter the choice: ");
        scanf("%d", &choice);
        switch (choice) {
            case 1: inti(); break;
            case 2: push(); break;
            case 3: pop(); break;
            case 4: peak(); break;
            case 5: isempty(); break;
            case 6: isfull(); break;
            case 7: exit(0);
            default: printf("INVALID INPUT\n"); break;
        }
    }
    return 0;
}
