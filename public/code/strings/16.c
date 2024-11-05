// 16. ENTER THE STRING FROM THE USER, ALSO ENTER A CHARACTER AND PRINT THE INDEX OF THE CHARACTER IF IT IS EXIST IN THE STRING ELSE PRINT -1.
#include <stdio.h>
#define maxSize 100
int search(char val, char str[maxSize])
{
    for (int i = 0; str[i] != 0; i++)
    {
        if (val == str[i])
        {
            return i;
        }
    }
    return -1;
}
int main()
{
    char str[maxSize], val;
    int ind;
    printf("Enter a string : ");
    gets(str);
    fflush(stdin);
    printf("Enter value to be searched : ");
    val = getchar();
    ind = search(val, str);
    (ind != -1) ? printf("Value found at index %d", ind) : printf("%d", ind);
    return 0;
}