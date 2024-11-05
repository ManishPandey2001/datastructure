//Enter a matrix of 4 rows and 2 columns from the user display it in matrix format
#include<stdio.h>
#include<conio.h>
void main()
{
int a[10][10],i,j,r,c;
clrscr();
printf("\nEnter number of rows and column of a matrix");
scanf("%d %d",&r,&c);
printf("\nEnter elements of %d rows and %d column\n",r,c);
for(i=0;i<r;i++)
for(j=0;j<c;j++)
scanf("%d",&a[i][j]);
for(i=0;i<r;i++)
{
for(j=0;j<c;j++)
printf("%d\t",a[i][j]);
printf("\n");//to print new line after row completion
}
getch();
}