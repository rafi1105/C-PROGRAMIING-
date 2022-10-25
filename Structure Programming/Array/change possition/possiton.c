#include <stdio.h>
int main ()
{
int change_p,pos, j, i, n;
int a[10],temp;
scanf("%d",&n);
for(i=0;i<n;i++)
    scanf("%d",&a[i]);
printf("enter the possition :\n");
scanf("%d",&pos);
printf("which possition you want to change : \n");
scanf("%d",&change_p);

temp=a[pos-1];
a[pos-1]=a[change_p-1];
a[change_p-1]=temp;
for (i=0;i<n;i++)
    printf("  %d\n",a[i]);
}
