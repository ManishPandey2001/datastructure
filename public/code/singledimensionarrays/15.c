// 15. Enter an array from user and print all the palindrome numbers?
#include <stdio.h>
void palindrome(int arr[],int size){
    for(int i=0;i<size;i++){
        int palindrome = arr[i];
        int reverse = 0;
        while (palindrome!=0){
            int remainder=palindrome%10;
            reverse =reverse*10 + remainder;
            palindrome/=10;
        }
        if(arr[i]==reverse)
            printf("%d  ",arr[i]);
    }
}
int main(){
    int arr[10],size= 10;
    printf("Enter the size of array : ");
    scanf("%d",&size);
    printf("Enter the elements of array \n");
    for(int i = 0;i<=size-1; i++){
        printf("Element %d :",i);
        scanf("%d",&arr[i]);
    }
    printf("Palindrome numbers in the array : ");
    palindrome(arr,size);
return 0;
}