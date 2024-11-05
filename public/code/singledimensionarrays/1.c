// 1. Enter an array from user and display all the value ?
#include <stdio.h>
void display(int arr[],int size){
    for(int i = 0; i<=size-1;i++)
        printf("%d ",arr[i]);
}
int main(){
    int arr[10],size = 10;
    printf("Enter size of array : ");
    scanf("%d",&size);
    printf("Enter the elements of array \n");
    for(int i=0;i<=size-1;i++){
        printf("Element %d : ",i);
        scanf("%d",&arr[i]);
    }
    printf("Elements of given array : ");
    display(arr,size);
return 0;
}