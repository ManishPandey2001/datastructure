9. ENTER THE INFIX EXPRESSION FROM USER AND CONVERT INTO PREFIX EXPRESSION.

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct stack 
{
    int max;
    char *array;
    int top;	
};

struct stack s1;
char infix[1000];
char prefix[1000];
int prefix_index = -1;

void init(int size) 
{
    s1.max = size;
    s1.array = (char *) malloc(sizeof(char) * s1.max);
    s1.top = -1;
}

void push(char item) 
{
    if (s1.top == s1.max - 1) 
    {
        printf("\nOverflow!");
        return;
    }
    s1.top++;
    s1.array[s1.top] = item;
}

char peek() 
{
    if (s1.top == -1) 
    {
        printf("\nEmpty Stack, cannot peek!");
        return '\0';
    }
    return s1.array[s1.top];
}

char pop() 
{
    if (s1.top == -1) 
    {
        printf("\nUnderflow!");
        return '\0';
    }
    return s1.array[s1.top--];
}

int precedence(char op) 
{
    if (op == '^') return 3;
    if (op == '*' || op == '/') return 2;
    if (op == '+' || op == '-') return 1;
    return 0;
}

void reverse(char *exp) 
{
    int n = strlen(exp);
    for (int i = 0; i < n / 2; i++) 
    {
        char temp = exp[i];
        exp[i] = exp[n - i - 1];
        exp[n - i - 1] = temp;
    }
}

void convert() 
{
    reverse(infix);
    int i;
    char top_item;
    
    for (i = 0; infix[i] != '\0'; i++) 
    {
        if (isalnum(infix[i])) 
        {
            prefix[++prefix_index] = infix[i];
        } 
        else if (infix[i] == '+' || infix[i] == '-' || infix[i] == '*' || infix[i] == '/' || infix[i] == '^') 
        {
            while (s1.top != -1 && precedence(peek()) > precedence(infix[i])) 
            {
                top_item = pop();
                prefix[++prefix_index] = top_item;
            }
            push(infix[i]);
        } 
        else if (infix[i] == ')') 
        {
            push(infix[i]);
        } 
        else if (infix[i] == '(') 
        {
            while (s1.top != -1 && peek() != ')') 
            {
                prefix[++prefix_index] = pop();
            }
            pop();
        }
    }
    
    while (s1.top != -1) 
    {
        prefix[++prefix_index] = pop();
    }
    
    prefix[prefix_index + 1] = '\0';
    reverse(prefix);
}

int main() 
{
    printf("Enter the infix expression: ");
    gets(infix);

    init(strlen(infix) + 2);
    convert();

    printf("Prefix expression: %s\n", prefix);
    free(s1.array);
    return 0;
}