// 21. PRINT ALL THE PERMUTATION OF A STRING I.E. "ABCDE".
#include <stdio.h>
#define maxSize 100
void printPerms(char str[maxSize], int size, int locked)
{
    char perm[maxSize];
    int count = 0;
    if (locked < size)
    {
        for (int i = locked; i < size; i++)
        {
            for (int j = 0; j < size; j++)
            {
                if (j != locked)
                {
                    str[j] = str[(j + i) % size];
                }
            }
            printf("%s\n", str);
        }
    }
}
int main()
{
    char str[maxSize];
    printf("Enter string : ");
    gets(str);
    printPerms(str, 5, 0);
    return 0;
}