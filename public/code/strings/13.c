// 13. ENTER THE STRING FROM THE USER AND COPY REVERSE OF THE STRING INTO ANOTHER STRING ?
#include <stdio.h>
#define maxSize 100
int getStrLen(char str[maxSize])
{
    int i;
    for (i = 0; str[i] != 0; i++)
        continue;
    return i;
}
void rCopy(char source[maxSize], char destination[maxSize], int size)
{
    int i;
    for (i = 0; i < size; i++)
    {
        destination[i] = source[size - i - 1];
    }
    destination[i] = 0;
}
int main()
{
    char str[maxSize], rStr[maxSize];
    int size;
    printf("Enter string : ");
    gets(str);
    size = getStrLen(str);
    rCopy(str, rStr, size);
    printf("Reverse of %s is %s", str, rStr);
    return 0;
}