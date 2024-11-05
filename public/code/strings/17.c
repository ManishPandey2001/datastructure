// 17. ENTER THE STRING FROM THE USER, AND COUNT THE NUMBER OF VOWELS.
#include <stdio.h>
#define maxSize 100
int countVowel(char str[maxSize])
{
    int count = 0;
    for (int i = 0; str[i] != 0; i++)
    {
        if (str[i] == 'a' || str[i] == 'e' || str[i] == 'i' || str[i] == 'o' || str[i] == 'u' || str[i] == 'A' || str[i] == 'E' || str[i] == 'I' || str[i] == 'O' || str[i] == 'U')
        {
            count++;
        }
    }
    return count;
}
int main()
{
    char str[maxSize];
    printf("Enter string : ");
    gets(str);
    printf("Number of vowels in given string : %d", countVowel(str));
    return 0;
}