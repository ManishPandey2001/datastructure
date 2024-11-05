//7.ENTER THE NUMBER FROM THE USER AND ADD ALL DIGITS OF THE NUMBER USING RECURSION.

#include <stdio.h>

int sumOfDigits(int n) 
{
    if (n == 0) 
    {
        return 0;
    }
    return (n % 10) + sumOfDigits(n / 10);
}

int main() 
{
    int number;
    printf("Enter a number: ");
    scanf("%d", &number);
    
    int sum = sumOfDigits(number);
    printf("The sum of the digits is: %d\n", sum);
    
    return 0;
}

