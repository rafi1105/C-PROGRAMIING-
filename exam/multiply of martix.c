#include <stdio.h>
int main()
{
   int a[3][3],b[3][3],m[3][3],j,i,r,c;
   printf("enter the number row:");
   scanf("%d",&r);
   printf("enter the number column:");
   scanf("%d",&c);
   printf("enter the number first matrix:");
   for(i=0;i<r;i++)
   for(j=0;j<c;j++)
   {
      printf("enter the element of the matrix (%d,%d) :",i+1,j+1);
      scanf("%d", &a[i][j]);
   }
   printf("enter the number second matrix:");
   for(i=0;i<r;i++)
   for(j=0;j<c;j++)
   {
      printf("enter the element of the matrix (%d,%d) :",i+1,j+1);
      scanf("%d", &b[i][j]);
   }
    for(i=0;i<r;i++)
   for(j=0;j<c;j++)
   {
      m[i][j] =a[i][j]*b[i][j];
   }
    for(i=0;i<r;i++){
   for(j=0;j<c;j++)
   {
      printf("\t%d\t",m[i][j]);
   }
   printf("\n");
}


}