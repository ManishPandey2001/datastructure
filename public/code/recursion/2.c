//2.CALCULATE FIBONACCI OF A NUMBER USING RECURSION.

#include <stdio.h>

int fibonacci(int n) 
{
    if (n <= 1) 
    {
        return n;
    }
    return fibonacci(n - 1) + fibonacci(n - 2);
}

int main() 
{
    int n;
    printf("Enter a non-negative integer: ");
    scanf("%d", &n);
    
    if (n < 0) 
    {
        printf("Fibonacci is undefined for negative numbers.\n");
    } 
    else 
    {
        printf("Fibonacci sequence up to %d:\n", n);
        for (int i = 0; i <= n; i++) 
        {
            printf("%d ", fibonacci(i));
        }
        printf("\n");
    }
    
    return 0;
}
           