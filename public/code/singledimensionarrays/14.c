// 14. Enter an array from user and print all possible combinations of the elements?
#include <stdio.h>
void compbinations(int arr[],int size){
    for(int i=0;i<size;i++){
        for(int j=0;j<size;j++){
            printf("(%d,%d)\t",arr[i],arr[j]);
        }
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
    printf("All combinations of array elements: ");
    compbinations(arr,size);
return 0;
}