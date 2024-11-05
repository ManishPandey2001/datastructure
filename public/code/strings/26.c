// 26. ENTER THE STRING FROM USER AND SPLITS THE FIRST WORD AND SECOND WORD AND RETURN THE START INDEX OF THE SECOND WORD.
#include <stdio.h>
#define maxSize 100
int split(char str[maxSize], char delimiter)
{
    for (int i = 0; str[i] != 0; i++)
    {
        if (str[i] == delimiter)
        {
            return i + 1;
        }
    }
    return -1;
}
int main()
{
    char str[maxSize];
    int ind;
    printf("Enter space separated string : ");
    gets(str);
    ind = split(str, ' ');
    if (ind != -1)
    {
        printf("String 1 : '");
        for (int i = 0; i < ind - 1; i++)
        {
            printf("%c", str[i]);
        }
        printf("'\nString 2 : '");
        for (int i = ind; str[i] != 0; i++)
        {
            printf("%c", str[i]);
        }
        printf("'");
    }
    else
    {
        printf("Separater not found");
    }

    return 0;
}