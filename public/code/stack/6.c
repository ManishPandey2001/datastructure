
6. CREATE THE PROGRAM TO MATCH THE SINGLE BRACKET USING STACKS.

#include <stdio.h>

void push(char *exp,int size,char *stack,int ssize) 
{
    int i;
    int j=0;
    for(i=0;exp[i]!='\0';i++) 
    {
        if(exp[i]=='(') 
        {
            stack[j]=exp[i];
            j++;
        }
        else if(exp[i]==')') 
        {
            if(j>0) 
            {
                j--;
            } 
            else 
            {
                printf("brackets are not matched");
            }
        }
    }
    if(j==0) 
    {
        printf("The brackets are matched");
    } 
    else 
    {
        printf("Brackets are not matched");
    }
}

void main() 
{
    char exp[20];
    char stack[20];
    printf("Enter the expression :");
    scanf("%s",exp);
    push(exp,20,stack,20);
}