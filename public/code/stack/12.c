
12. CREATE A PROGRAM TO EVALUATE THE POSTFIX EXPRESSION.
#include <stdio.h>
#include <math.h>
#define size_INT16_MAX_ 100

void push(int *stack, int *top, int val) 
{
    stack[++(*top)] = val;
}

int pop(int *stack, int *top) 
{
    return stack[(*top)--];
}

int peek(int *stack, int *top) 
{
    return stack[*top];
}

int main() 
{
    int size = size_INT16_MAX_;
    int top = -1;
    char exp[size];
    int stack[size];
    int result;
    char curr;
    int ind = 0;
    int opr1, opr2;
    int i;
    
    printf("ENTER A POSTFIX EXPRESSION : ");
    gets(exp);
    
    for (i = 0; exp[i] != 0; i++) 
    {
        if ((exp[i] == '^') || (exp[i] == '*') || (exp[i] == '/') || (exp[i] == '+') || (exp[i] == '-')) 
        {
            opr2 = (int)(pop(stack, &top)); 
            opr1 = (int)(pop(stack, &top)); 
            if (exp[i] == '^') 
            {
                push(stack, &top, pow(opr1, opr2));
            }
            if (exp[i] == '*') 
            {
                push(stack, &top, opr1 * opr2);
            }
            if (exp[i] == '/') 
            {
                push(stack, &top, opr1 / opr2);
            }
            if (exp[i] == '+') 
            {
                push(stack, &top, opr1 + opr2);
            }
            if (exp[i] == '-') 
            {
                push(stack, &top, opr1 - opr2);
            }
        } 
        else if ((exp[i] > 47) && (exp[i] < 58)) 
        {
            push(stack, &top, exp[i] - 48);
        }
    }
    
    result = pop(stack, &top);
    printf("RESULT : %d", result);
    return 0;
}