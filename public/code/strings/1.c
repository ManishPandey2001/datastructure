#include <stdio.h>

void uppercase(char str[]){
    int i = 0;
    while(str[i] != '\0'){
        if(str[i] >= 'a' && str[i] <= 'z')
            str[i] -= 32;
        else
            i++;
    }
}
int main() {
    char str[30];
    printf("Enter a string to convert to uppercase : ");
    gets(str);
    uppercase(str);

    printf("Uppercase string: %s\n", str);
    return 0;
}