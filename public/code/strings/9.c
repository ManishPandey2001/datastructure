// 9.ENTER THE STRING FROM USER AND COPY IT INTO ANOTHER STRING VARIABLE?
#include <stdio.h>
#define maxSize 100
void strCopy(char source[maxSize], char destination[maxSize])
{
    int i;
    for (i = 0; source[i] != 0; i++)
    {
        destination[i] = source[i];
    }
    destination[i] = 0;
}
int main()
{
    char str1[maxSize], str2[maxSize];
    printf("Enter a string : ");
    gets(str1);
    strCopy(str1, str2);
    printf("You entered : %s", str2);
    return 0;
}