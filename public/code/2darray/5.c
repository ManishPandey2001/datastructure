// 5. Enter a Matrix from user, copy it in another matrix of same size?
#include <stdio.h>
#define rows 100
#define cols 100
void getMat(int r, int c, int mat[rows][cols])
{
    for (int i = 0; i < r; i++)
    {
        for (int j = 0; j < c; j++)
        {
            printf("Enter array element [%d][%d] : ", i, j);
            scanf("%d", &mat[i][j]);
        }
    }
}
void printMat(int r, int c, int mat[rows][cols])
{
    for (int i = 0; i < r; i++)
    {
        for (int j = 0; j < c; j++)
        {
            printf("%d ", mat[i][j]);
        }
        printf("\n");
    }
}
void copyMat(int r, int c, int mat1[rows][cols], int mat2[rows][cols])
{
    for (int i = 0; i < r; i++)
    {
        for (int j = 0; j < c; j++)
        {
            mat2[i][j] = mat1[i][j];
        }
    }
}
int main()
{
    int mat1[rows][cols], mat2[rows][cols];
    int r, c;
    printf("ENTER DIMENSIONS OF MATRICES\n");
    printf("Enter number of rows : ");
    scanf("%d", &r);
    printf("Enter number of columns : ");
    scanf("%d", &c);
    printf("MATRIX 1 :\n");
    getMat(r, c, mat1);
    printf("MATRIX 1 :\n");
    printMat(r, c, mat1);
    copyMat(r, c, mat1, mat2);
    printf("COPY MATRIX :\n");
    printMat(r, c, mat2);
    return 0;
}