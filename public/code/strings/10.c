// 10. ENTER THE STRING FROM USER, ENTER THE INDEX NUMBER AND PRINT CHARACTER PRESENT ON THAT INDEX ?
/*
Explanation -

    FOR EXAMPLE :
    HELLO WORLD
    ENTER THE INDEX : 6
    THE CHARACTER IS W
*/
#include <stdio.h>
#define maxSize 100
int getVal(int ind, char str[maxSize])
{
    int i = 0;
    for (i = 0; (i < maxSize) && (str[i] != 0); i++)
    {
        if (i == ind)
        {
            return str[i];
        }
    }
    return 0;
}
int main()
{
    char str1[100];
    int ind;
    char val;
    printf("Enter string : ");
    gets(str1);
    printf("Enter index : ");
    scanf("%d", &ind);
    val = getVal(ind, str1);
    (val != 0) ? printf("Character at index %d is %c", ind, val) : printf("Value not found");
    return 0;
}