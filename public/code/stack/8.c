8. SORT THE STACK IN ASCENDING ORDER USING INTEGER ARRAY.

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
    
    printf("The item %d at stack[%d] is popped.", stack[top], top);
    stack[top] = 0;
    top--;
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

void trav(int *stack, int size)
{
		int i;
		printf("\n The elements present in stack are : ");
		for(i = top; i >= 0; i--)
		{
			printf("%d ", stack[i]);
		}
}	

void sort(int *stack) 
{
    for (int i = 0; i <= top; i++) 
	{
        for (int j = 0; j < top - i; j++) 
		{
            if (stack[j] < stack[j + 1]) 
			{
                int temp = stack[j];
                stack[j] = stack[j + 1];
                stack[j + 1] = temp;
            }
        }
    }
    printf("Stack sorted in ascending order.\n");
}

void main() 
{
    int stack[5];
    int choice;
    while (1) 
	{
        printf("\n1 push():");    
        printf("\n2 pop ():");
        printf("\n3 peek ():");
        printf("\n4 trav ()");
        printf("\n5 sort ():");
        printf("\n6 exit ():");
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
                trav(stack, 5);
                break;        
            case 5:
                sort(stack);
                break;
            case 6:
                exit(0); 
            default:
                printf("INVALID INPUT");
                break;                
        }
    }
}  
