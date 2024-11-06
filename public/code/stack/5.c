5. ENTER THE STRING FROM THE USER AND REVERSE THE STRING USING STACKS.

#include <stdio.h>

struct Node 
{
    char data;
    struct Node* next;
};

struct Node* top = NULL;

void push(char item) 
{
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = item;
    newNode->next = top;
    top = newNode;
}

char pop() 
{
    if (top == NULL) 
    {
        return '\0';
    }
    struct Node* temp = top;
    char data = temp->data;
    top = top->next;
    free(temp);
    return data;
}

int calculateLength(char* str) 
{
    int length = 0;
    while (str[length] != '\0') 
    {
        length++;
    }
    return length;
}

void reverseString(char* str) 
{
    int length = calculateLength(str);
    for (int i = 0; i < length; i++) 
    {
        push(str[i]);
    }
    for (int i = 0; i < length; i++) 
    {
        str[i] = pop();
    }
}

int main() 
{
    char str[100];

    printf("Enter a string: ");
    scanf("%s", str);

    reverseString(str);

    printf("Reversed string: %s\n", str);

    return 0;
}

