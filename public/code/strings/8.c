// 8. ENTER TWO STRINGS FROM USER AND CONCATENATE THOSE STRINGS IN ANOTHER STRING AND DISPLAY THE ANSWER?
#include <stdio.h>
#define size 100
void concatenate(char *str1, char *str2)
{
    char str3[100];
    int i, j;
    for (i = 0; str1[i] != 0; i++)
    {
        str3[i] = str1[i];
    }
    for (j = 0; str2[j] != 0; j++)
    {
        str3[i + j] = str2[j];
    }
    str3[i + j] = 0;
    puts(str3);
}
int main()
{
    char string1[size], string2[size];
    printf("Enter a string1 : ");
    gets(string1);
    printf("Enter a string2 : ");
    gets(string2);
    concatenate(string1, string2);
    return 0;
}