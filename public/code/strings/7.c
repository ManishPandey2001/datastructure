// 7. ENTER TWO STRINGS FROM USER AND COMPARE THOSE STRINGS THAT THEY ARE EQUAL OR NOT?
#include <stdio.h>
int compare(char *str1, char *str2)
{
    int diff = 0;
    int i = 0;
    int temp = 0;
    for (i = 0; (str1[i] != 0) && (str2[i] != 0); i++)
    {
        temp = str1[i] - str2[i];
        diff += (temp < 0) ? (temp * (-1)) : temp;
    }
    if ((diff != 0) || (str1[i] != 0) || (str2[i] != 0))
    {
        return 0;
    }
    return 1;
}
int main()
{
    char string1[100], string2[100];
    printf("Enter a string1 : ");
    gets(string1);
    printf("Enter a string2 : ");
    gets(string2);
    printf((compare(string1, string2) == 1) ? "Equal strings" : "Unequal strings");
    return 0;
}