
7. CREATE TWO INTEGER STACKS IN A SINGLE ARRAY.
#include <stdio.h>
#include <stdlib.h>

#define SIZE 10

int array[SIZE];
int top1 = -1;
int top2 = SIZE;

void push1(int data) 
{  
    if (top1 < top2 - 1) 
    {  
        top1++;  
        array[top1] = data;  
    } 
    else 
    {  
        printf("Stack 1 is full\n");  
    }  
}  

void push2(int data) 
{  
    if (top1 < top2 - 1) 
    {  
        top2--;  
        array[top2] = data;   
    } 
    else 
    {  
        printf("Stack 2 is full\n");  
    }  
}  

void display_stack1() 
{  
    printf("Stack 1: ");
    for (int i = top1; i >= 0; --i) 
    {  
        printf("%d ", array[i]);  
    }  
    printf("\n");  
}  

void display_stack2() 
{  
    printf("Stack 2: ");
    for (int i = top2; i < SIZE; ++i) 
    {  
        printf("%d ", array[i]);  
    }  
    printf("\n");  
}  

int main() 
{  
    int i;  
    printf("We can push a total of 20 values\n");  

    for (i = 1; i <= 5; ++i) 
    {  
        push1(i);  
        printf("Value Pushed in Stack 1 is %d\n", i);  
    }  

    for (i = 6; i <= 10; ++i) 
    {  
        push2(i);  
        printf("Value Pushed in Stack 2 is %d\n", i);  
    }  

    display_stack1();  
    display_stack2();  

    printf("Pushing Value in Stack 1 is %d\n", 11);  
    push1(11);  

    return 0;  
}  