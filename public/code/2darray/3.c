#include <stdio.h>
void inputMatrix(int m[][3]){
    for(int i=0;i<3;i++){
        for(int j=0;j<3;j++){
            printf("[%d , %d] : ",i,j);
            scanf("%d",&m[i][j]);
        }
    }
}
void matrixSubtract(int m1[][3],int m2[][3]){
    for(int i=0;i<3;i++){
        for(int j=0;j<3;j++){
            printf("%d ",m1[i][j]-m2[i][j]);
        }
        printf("\n");
    }        
}
int main(){
    int matrix1[3][3],matrix2[3][3];
    printf("Enter the elements of Matrix 1 : ");
    inputMatrix(matrix1);

    printf("\nEnter the elements of Matrix 2 : ");
    inputMatrix(matrix2);

    printf("difference of both matrices : \n");
    matrixSubtract(matrix1,matrix2);
return 0;
}