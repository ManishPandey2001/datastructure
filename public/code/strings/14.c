// 14. ENTER THE STRING FROM THE USER AND PRINT THE DIFFERENCE OF ASCII VALUE OF EACH CHARACTER ?
#include <stdio.h>
#include <math.h>
#define maxSize 100
int difference(char str1[maxSize], char str2[maxSize])
{
    int diff = 0, i = 0;
    while ((str1[i] != 0) || (str2[i] != 0))
    {
        if ((!str1[i]) == (!str2[i]))
        {
            diff += fabs(str1[i] - str2[i]);
        }
        else
        {
            return -1;
        }
        i++;
    }
    return diff;
}
int main()
{
    char str1[maxSize], str2[maxSize];
    int diff;
    printf("Enter string1 : ");
    gets(str1);
    printf("Enter string2 : ");
    gets(str2);
    diff = difference(str1, str2);
    (diff != -1) ? printf("Sum of absolute differences of ASCII of strings = %d", diff) : printf("Unequal Strings");
    return 0;
}