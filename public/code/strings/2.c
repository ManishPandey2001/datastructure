#include <stdio.h>
void lowercase(char str[]){
    for(int i = 0; str[i] != '\0'; i++){
        if(str[i] >= 'A' && str[i] <= 'Z'){
            str[i] = str[i] + 32;
        }
    }
}
int main()
{
    char str[10];
    printf("Enter a string to convert to lowercase : ");
    gets(str);

    lowercase(str);
    printf("\nLowercase string : %s", str);

    return 0;
}