// 18. ENTER THE STRING FROM THE USER AND CONVERT INTO AN INTEGER VALUE?
#include <stdio.h>
#define maxSize 100
// ASCII 0 -> 48 ; 9 -> 57
int strToInt(char str[maxSize])
{
    int result = 0;
    int negative = 0;
    for (int i = 0; str[i] != 0; i++)
    {
        if ((str[i] >= '0') && (str[i] <= '9'))
        {
            result *= 10;
            result += str[i] - 48;
        }
        else
        {
            if ((str[i] == '-') && (i == 0))
            {
                negative = 1;
            }
            else
            {
                return 0;
            }
        }
    }
    if (negative)
    {
        return (-1 * result);
    }

    return result;
}
int main()
{
    char str[maxSize];
    int num;
    printf("Enter string non zero string : ");
    gets(str);
    num = strToInt(str);
    (num) ? printf("String : %d", num) : printf("Invalid String");
    return 0;
}