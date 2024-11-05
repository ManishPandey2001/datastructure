// 29. ENTER THE STRING FROM USER AND CONVERT CHARACTERS INTO THEIR ASCII VALUES IN THE INTEGER ARRAY. [FOR EXAMPLE TAKE 10 CHARACTERS]
#include <stdio.h>
#define maxSize 100
int convertToAscii(char str[maxSize], int arr[maxSize])
{
    int i;
    for (i = 0; str[i] != 0; i++)
    {
        arr[i] = str[i];
    }
    return i;
}
int main()
{
    char str[maxSize];
    int arr[maxSize];
    int size;
    printf("Enter string : ");
    gets(str);
    size = convertToAscii(str, arr);
    for (int i = 0; i < size; i++)
    {
        printf("%d ", arr[i]);
    }
    return 0;
}