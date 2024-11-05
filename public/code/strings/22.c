// 22. ENTER THE STRING FROM THE USER, SORT THE STRING IN ASCENDING ORDER AND PRINT IT.
#include <stdio.h>
#define maxSize 100
char lowerCase(char val)
{
    if ((val >= 65) && (val <= 90))
        return val + 32;
    return val;
}
void sort(char str[maxSize])
{
    char temp;
    // ASCII A = 65  Z = 90 a = 97 z = 122
    for (int j = 0; str[j] != 0; j++)
    {
        for (int i = 0; str[i] != 0; i++)
        {
            if ((str[i + 1] != 0) && (lowerCase(str[i]) > lowerCase(str[i + 1])))
            {
                temp = str[i + 1];
                str[i + 1] = str[i];
                str[i] = temp;
            }
        }
    }
}
int main()
{
    char str[maxSize];
    printf("Enter string : ");
    gets(str);
    sort(str);
    printf("Sorted string : %s", str);
    return 0;
}