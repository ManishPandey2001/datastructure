// 23. ENTER A SENTENCE FROM USER AND THEN ENTER THE WORD AND COUNT THE OCCURENCE OF THAT WORD IN THE SENTENCE.
#include <stdio.h>
#define maxSize 100
int substring(char str[maxSize], char subStr[maxSize])
{
    int ind = 0;
    int count = 0;
    for (int i = 0; str[i] != 0; i++)
    {
        if (str[i] == subStr[ind])
        {
            ind++;
            if (subStr[ind] == 0)
            {
                count++;
                ind = 0;
            }
        }
        else
        {
            ind = 0;
        }
    }
    return count;
}
int main()
{
    char str[maxSize], subStr[maxSize];
    printf("Enter a string : ");
    gets(str);
    printf("Enter sub string to look for : ");
    gets(subStr);
    printf("%d", substring(str, subStr));
    return 0;
}