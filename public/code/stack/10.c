10. ENTER THE INFIX EXPRESSION FROM USER AND CONVERT INTO POSTFIX EXPRESSION.

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
char postfix[1000];
int postfix_index = -1;

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

void checkEndBrackets() 
{
    int x;
    if (infix[0] != '(') 
    {
        for (int i = strlen(infix); i >= 0; i--) 
        {
            infix[i + 1] = infix[i];
        }
        infix[0] = '(';
    }
    if (infix[strlen(infix) - 1] != ')') 
    { 
        x = strlen(infix);
        infix[x] = ')';
        infix[x + 1] = '\0';
    }
}

void convert() 
{
    int i;
    char top_item;

    for (i = 0; infix[i] != '\0'; i++) 
    {
        if (infix[i] == '+' || infix[i] == '-' || infix[i] == '*' || infix[i] == '/' || infix[i] == '^') 
        {
            while (s1.top != -1 && (peek() == '^' || (peek() == '*' || peek() == '/') && 
            (infix[i] == '+' || infix[i] == '-')))
            {
                top_item = pop();
                postfix[++postfix_index] = top_item;
            }
            push(infix[i]);
        } 
        else if (infix[i] == '(') 
        {
            push(infix[i]);
        } 
        else if (infix[i] == ')') 
        {
            while (s1.top != -1 && peek() != '(') 
            {
                postfix[++postfix_index] = pop();
            }
            pop();
        } 
        else 
        {
            postfix[++postfix_index] = infix[i];
        }
    }

    while (s1.top != -1) 
    {
        postfix[++postfix_index] = pop();
    }

    postfix[postfix_index + 1] = '\0';
}

int main() 
{
    printf("Enter the infix expression: ");
    gets(infix);

    init(strlen(infix) + 2);
    checkEndBrackets();
    convert();

    printf("Postfix expression: %s\n", postfix);
    free(s1.array);
    return 0;
}
