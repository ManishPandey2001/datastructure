//3.CALCULATE THE SUM OF NATURAL NUMBERS TILL 10 USING RECURSION.

#include <stdio.h>

int sumNatural(int n) 
{
    if (n <= 0) 
    {
        return 0;
    }
    return n + sumNatural(n - 1);
}

int main() 
{
    int result = sumNatural(10);
    printf("The sum of natural numbers up to 10 is: %d\n", result);
    return 0;
}