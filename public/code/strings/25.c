// 25. ENTER THE STRING FROM THE USER AND TRIM/ ELIMINATE THE SPACES FROM BOTH ENDS (IF ANY).
#include <stdio.h>
#define maxSize 100
int getSize(char str[maxSize])
{
    int i;
    for (i = 0; str[i] != 0; i++)
    {
    }
    return i;
}
void trim(char str[maxSize])
{
    int i = 0, j;
    while (str[i] == ' ')
    {
        i++;
    }
    for (j = 0; str[i + j] != 0; j++)
    {
        str[j] = str[i + j];
    }
    str[j] = 0;
    for (int k = j - 1; k >= 0; k--)
    {
        if (str[k] != ' ')
        {
            str[k + 1] = 0;
            break;
        }
    }
}
int main()
{
    char str[maxSize];
    printf("Enter string : ");
    gets(str);
    trim(str);
    printf("Trimmed string : '%s'", str);
    return 0;
}