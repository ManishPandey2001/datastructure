#include <stdio.h>
void inputMatrix(int m[][3]){
    for(int i=0;i<3;i++){
        for(int j=0;j<3;j++){
            printf("[%d , %d] : ",i,j);
            scanf("%d",&m[i][j]);
        }
    }
}
void ScalerProduct(int m1[][3]){
    for(int i=0;i<3;i++){
        for(int j=0;j<3;j++){
            printf("%d ",3*m1[i][j]);
        }
        printf("\n");
    }        
}
int main(){
    int matrix1[3][3];
    printf("Enter the elements of Matrix 1 : \n");
    inputMatrix(matrix1);

    printf("Scaler product of matrix by 3 : \n");
    ScalerProduct(matrix1);
return 0;
}