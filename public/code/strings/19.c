// 19. ENTER THE STRING FROM THE USER AND CONVERT INTO A FLOAT VALUE?
#include <stdio.h>
#define maxSize 100
float strToFloat(char str[maxSize])
{
    float result = 0;
    int invert = 0;
    int negative = 0;
    int pow = 1;
    for (int i = 0; str[i] != 0; i++)
    {
        if ((str[i] >= '0') && (str[i] <= '9'))
        {
            if (invert)
            {
                pow *= 10;
                result += ((str[i] - 48) / (float)pow);
            }
            else
            {
                result *= 10;
                result += str[i] - 48;
            }
        }
        else
        {
            if ((str[i] == '-') && (i == 0))
            {
                negative = 1;
            }
            else
            {
                if ((str[i] == '.' && str[i + 1] != 0))
                {
                    invert = 1;
                }
                else
                {
                    return 0;
                }
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
    float num;
    printf("Enter string non zero string : ");
    gets(str);
    num = strToFloat(str);
    (num) ? printf("String : %f", num) : printf("Invalid String");
    return 0;
}