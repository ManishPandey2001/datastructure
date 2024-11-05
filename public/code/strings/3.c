#include <stdio.h>
void sentance_case(char str[]){
    int i, j;
    int length = 0;
    while(str[length]!= '\0'){
        if(str[0] >= 'a' && str[0] <= 'z')
            str[0] = str[0] - 32;
            
        for(i = 1; str[i]!= '\0'; i++){
            if(str[i] >= 'A' && str[i] <= 'Z')
                str[i] = str[i] + 32;
        }
        length++;
    }
}
int main(){
    char str[10];
    printf("Enter a string : ");
    gets(str);

    printf("\nRaw string : %s", str);
    sentance_case(str);
    printf("\nAfter Sentence case applied : %s", str);
return 0;
}