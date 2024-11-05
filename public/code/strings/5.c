// 5. ENTER THE STRING FROM USER AND CONVERT INTO TOGGLE CASE ?
#include <stdio.h>
void titleCase(char *arr)
{
    for (int i = 0; arr[i] != 0; i++)
    {
        if ((arr[i] >= 'a') && (arr[i] <= 'z'))
        {
            arr[i] = arr[i] - 32;
        }
        else if ((arr[i] >= 'A') && (arr[i] <= 'Z'))
        {
            arr[i] = arr[i] + 32;
        }
    }
}
int main()
{
    char string[100];
    printf("Enter a string : ");
    gets(string);
    titleCase(string);
    puts(string);
    return 0;
}