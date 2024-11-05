// 15. ENTER THE STRING FROM THE USER, ENTER A CHARACTER ALSO AND SEARCH THE CHARACTER IN THE STRING?
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
    (ind != -1) ? printf("Value found at index %d", ind) : printf("Value not found");
    return 0;
}