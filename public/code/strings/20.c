// 20. ENTER THE STRING FROM THE USER AND COUNT THE NUMBER OF CHARACTERS, WORDS, SPACES AND LINES
#include <stdio.h>
#define maxSize 100
void push(char *stack, int *top, char val)
{
    stack[++(*top)] = val;
}
char pop(char *stack, int *top)
{
    return stack[(*top)--];
}
static inline int isEmpty(char *stack, int *top)
{
    return *top == -1;
}
static inline int isFull(char *stack, int *top)
{
    return *top == (maxSize - 1);
}
void count(char str[maxSize])
{
    int words = 0, spaces = 0, chars = 0, lines = 0, top = -1;
    char stack[maxSize];
    for (chars = 0; str[chars] != 0; chars++)
    {
        if (str[chars] == ' ')
        {
            spaces++;
            if (!isEmpty(stack, &top))
            {
                while (!isEmpty(stack, &top))
                {
                    pop(stack, &top);
                }
                words++;
            }
        }
        else if (str[chars] == '\n')
        {
            if (chars != 0)
            {
                lines++;
            }
            if (!isEmpty(stack, &top))
            {
                while (!isEmpty(stack, &top))
                {
                    pop(stack, &top);
                }
                words++;
            }
        }
        else
        {
            push(stack, &top, str[chars]);
        }
    }
    if (!isEmpty(stack, &top))
    {
        while (!isEmpty(stack, &top))
        {
            pop(stack, &top);
        }
        words++;
    }
    printf("Number of\n Words : %d\n Spaces : %d\n Characters : %d\n Lines : %d", words, spaces, chars, lines);
}
int main()
{
    char str[maxSize];
    printf("Enter string (max %d chars; to end hit enter twice): ", maxSize);
    for (int i = 0; i < maxSize; i++)
    {
        str[i] = getc(stdin);
        if ((i > 0) && (str[i] == '\n') && (str[i] == str[i - 1]))
        {
            str[i] = 0;
            break;
        }
    }
    count(str);
    return 0;
}