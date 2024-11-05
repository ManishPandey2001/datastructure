// 24. ENTER A SENTENCE FROM USER AND THEN ENTER THE WORD AND REPLACE THAT WORD BY ANOTHER WORD.
#include <stdio.h>
#define maxSize 100
void replace(char str[maxSize], char word[maxSize], char replacement[maxSize])
{
    char temp[maxSize];
    int ind = 0;
    int j;
    int i;
    for (i = 0; str[i] != 0; i++)
    {
        while ((str[i + ind] == word[ind]) && (word[ind + 1] != 0))
        {
            ind++;
        }
        if (word[ind + 1] == 0)
        {
            for (j = i + ind + 1; str[j] != 0; j++)
            {
                temp[j - i - ind - 1] = str[j];
            }
            temp[j - i - ind - 1] = 0;
            break;
        }
        ind = 0;
    }
    for (int k = 0; replacement[k] != 0; k++)
    {
        str[i++] = replacement[k];
    }
    for (int k = 0; temp[k] != 0; k++)
    {
        str[i++] = temp[k];
    }
    str[i] = 0;
}
int main()
{
    char str[maxSize], find[maxSize], replacement[maxSize];
    printf("Enter a string : ");
    gets(str);
    printf("Enter a sub string to replace : ");
    gets(find);
    printf("Enter replacement string : ");
    gets(replacement);
    replace(str, find, replacement);
    printf("String after replacement : %s", str);
    return 0;
}