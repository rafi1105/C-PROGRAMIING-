#include <stdio.h>
int main ()
{
  int t[10][10],a[10][10],r,c,i,j;
  printf("enter the number of rows:");
  scanf("%d",&r);
  printf("enter the number of columns:");
  scanf("%d",&c);
  for(i=0;i<r;i++)
  for(j=0;j<c;j++)
  {
    printf("Enter the elements a%d%d :",i+1,j+1);
    scanf("%d",&a[i][j]);
  }
  printf("\n");
  printf("The matrix is :\n");
  for(i=0;i<r;i++)
  {
  for(j=0;j<c;j++)
  {
    printf("%10d",a[i][j]);
   
  }
    printf("\n");
}
  printf("The traspose martrix are :\n");
  for(j=0;j<c;j++)
  {
  for(i=0;i<r;i++)
  {
   
    printf(" %4d",a[i][j]);
  }
  printf("\n");
  }
    return 0;
}
