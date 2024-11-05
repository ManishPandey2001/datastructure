// 6. ENTER THE STRING FROM USER AND FINAL LENGTH OF THE STRING ?
#include <stdio.h>
int strlen(char *str)
{
    int i = 0;
    for (i = 0; str[i] != 0; ++i)
        ;
    return i;
}
int main()
{
    char string[100];
    printf("Enter a string : ");
    gets(string);
    printf("Length of string is : %d", strlen(string));
    return 0;
}