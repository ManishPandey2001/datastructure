// 11. ENTER THE STRING FROM USER AND CHECK ITS PALINDROME OR NOT?
#include <stdio.h>
#define maxSize 100
int getStrLen(char str[maxSize])
{
    int i;
    for (i = 0; str[i] != 0; i++)
        continue;
    return i;
}
int isPalindrome(char str[maxSize], int size)
{
    for (int i = 0; i < size; i++)
    {
        if (str[i] == str[size - 1 - i])
        {
            continue;
        }
        return 0;
    }
    return 1;
}
int main()
{
    char str[maxSize];
    int size;
    printf("Enter string : ");
    gets(str);
    size = getStrLen(str);
    isPalindrome(str, size) ? printf("String is palindrome") : printf("String is not palindrome");
    return 0;
}