
2. CREATE A STACK IMPLEMENTING THE OPERATIONS ON THE CHARACTERS ARRAY 
(PUSH, POP, PEEK, ISEMPTY, ISFULL)

#include <stdio.h>
#include <stdlib.h>

int top = -1;

void push(char *stack, int size) 
{
    char item;
    if (top == size - 1) 
    {
        printf("!OVERFLOW\n");
        return;
    }
    
    printf("\nEnter the item: ");
    scanf(" %c", &item);
    
    top++;
    stack[top] = item;
    printf("The item '%c' inserted at index stack[%d]\n", item, top);
}

void pop(char *stack) 
{
    if (top == -1) 
    {
        printf("!UNDERFLOW\n");
        return;    
    }    
    
    printf("The item '%c' at stack[%d] is popped.\n", stack[top], top);
    stack[top] = 0;
    top--;
}

void peek(char *stack) 
{
    if (top == -1) 
    {
        printf("!UNDERFLOW\n");
        return;
    }
    printf("The top most item is '%c' at index stack[%d]\n", stack[top], top);
}

void isempty() 
{
    if (top == -1) 
    {
        printf("Stack is empty.\n");
    } 
    else 
    {
        printf("Stack is not empty.\n");
    }    
}

void isfull(int size) 
{
    if (top == size - 1) 
    {
        printf("Stack is full.\n");
    } 
    else 
    {
        printf("Stack is not full.\n");
    }
}

int main() 
{
    char stack[5];
    int choice;
    while (1) 
    {
        printf("\n1. Push\n");
        printf("2. Pop\n");
        printf("3. Peek\n");
        printf("4. Check if Empty\n");
        printf("5. Check if Full\n");
        printf("6. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        switch (choice) 
        {
            case 1:
                push(stack, 5);
                break;
            case 2:
                pop(stack);
                break;
            case 3:
                peek(stack);
                break;        
            case 4:
                isempty();
                break;        
            case 5:
                isfull(5);
                break;        
            case 6:
                exit(0); 
            default:
                printf("INVALID INPUT\n");
                break;                
        }
    }
    return 0;
}
