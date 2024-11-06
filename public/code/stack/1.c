// 1. CREATE A STACK IMPLEMENTING THE OPERATIONS ON AN INTEGER ARRAY (PUSH, POP, PEEK, ISEMPTY, ISFULL)

#include <stdio.h>
#include <stdlib.h>

int top = -1;
void push(int *stack, int size)
{
    int item;
    if (top == size - 1)
    {
        printf("!OVERFLOW");
        return;
    }
    
    printf("\nEnter the item: ");
    scanf("%d", &item);
    
    top++;
    stack[top] = item;
    printf("The item %d inserted at index stack[%d]", item, top);    
}

void pop(int *stack, int size)
{
    if (top == -1)
    {
        printf("!UNDERFLOW");
        return;    
    }    
    
    else
    {
        printf("The item %d at stack[%d] is popped.", stack[top], top);
        stack[top] = 0;
        top--;
    }
}

void peek(int *stack, int size)
{
    if (top == -1)
    {
        printf("UNDERFLOW!");
        return;
    }
    printf("\nThe top most item is %d at index stack[%d]", stack[top], top);
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

void main()
{
    int stack[5];
    int choice;
    while (1)
    {
        printf("\nEnter the 1 for push ():");    
        printf("\nEnter the 2 for pop ():");
        printf("\nEnter the 3 for peek ():");
        printf("\nEnter the 4 for isempty ():");
        printf("\nEnter the 5 for isfull ():");
        printf("\nEnter the 6 for exit ():");
        printf("\nEnter the choice : ");
        scanf("%d", &choice);
        switch (choice)
        {
            case 1:
                push(stack, 5);
                break;
            case 2:
                pop(stack, 5);
                break;
            case 3:
                peek(stack, 5);
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
                printf("INVALID INPUT");
                break;                
        }
    }
}