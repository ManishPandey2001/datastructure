
11. CREATE A PROGRAM TO EVALUATE THE PREFIX EXPRESSION.
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

struct stack 
{
    int max;
    double *array;
    int top;	
};

struct stack s1;
char infix[1000];
char prefix[1000];
int prefix_index = -1;

void init(int size) 
{
    s1.max = size;
    s1.array = (double *) malloc(sizeof(double) * s1.max);
    s1.top = -1;
}

void push(double item) 
{
    if (s1.top == s1.max - 1) 
    {
        printf("\nOverflow!");
        return;
    }
    s1.top++;
    s1.array[s1.top] = item;
}

double pop() 
{
    if (s1.top == -1) 
    {
        printf("\nUnderflow!");
        return 0;
    }
    return s1.array[s1.top--];
}

int isDigit(char c) 
{
    return c >= '0' && c <= '9';
}

double evaluatePrefix() 
{
    for (int i = prefix_index; i >= 0; i--) 
    {
        if (isDigit(prefix[i])) 
        {
            push(prefix[i] - '0');
        } 
        else 
        {
            double operand1 = pop();
            double operand2 = pop();
            switch (prefix[i]) 
            {
                case '+': push(operand1 + operand2); break;
                case '-': push(operand1 - operand2); break;
                case '*': push(operand1 * operand2); break;
                case '/': push(operand1 / operand2); break;
                case '^': push(pow(operand1, operand2)); break;
            }
        }
    }
    return pop();
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

int precedence(char op) 
{
    if (op == '^') return 3;
    if (op == '*' || op == '/') return 2;
    if (op == '+' || op == '-') return 1;
    return 0;
}

void convert() 
{
reverse(infix);
for (int i = 0; infix[i] != '\0'; i++) 
{
    if (isDigit(infix[i])) 
    {
        prefix[++prefix_index] = infix[i];
    } 
    else if (infix[i] == '+' || infix[i] == '-' || infix[i] == '*' || infix[i] == '/' || infix[i] == '^') 
    {
        while (s1.top != -1 && precedence(s1.array[s1.top]) > precedence(infix[i])) 
        {
            prefix[++prefix_index] = pop();
        }
        push(infix[i]);
    } 
    else if (infix[i] == ')') 
    {
        push(infix[i]);
    } 
    else if (infix[i] == '(') 
    {
        while (s1.top != -1 && s1.array[s1.top] != ')') 
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
    double result = evaluatePrefix();
    printf("Evaluation result: %.2f\n", result);
    
    free(s1.array);
    return 0;
}