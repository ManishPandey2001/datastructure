// 1. CALCULATE FACTORIAL OF A NUMBER USING RECURSION
#include <stdio.h>
int factorial(int i)
{
    if (i > 1)
    {
        return i * factorial(i - 1);
    }
    return 1;
}
int main()
{
    int num;
    printf("ENTER A NUMBER : ");
    scanf("%d", &num);
    printf("FACTORIAL OF %d : %d", num, factorial(num));
    return 0;
}