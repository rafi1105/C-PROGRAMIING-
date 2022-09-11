#include <stdio.h>
int main ()
{
    char ch1[20],ch2[20],ch3[20];
    int l1,l2,l3,i=0,j;
    l1=l2=l3=0;
    scanf("%s",ch1);
    scanf("%s",ch2);
    scanf("%s",ch3);
    // 1st 
    for (i=0;ch1[i]!='\0';i++)
    l1++;
    //2nd
    for (i=0;ch2[i]!='\0';i++)
    l2++;
    for (i=0;ch3[i]!='\0';i++)
    l3++;
    /* printf("%d\n",l1);
    printf("%d\n",l2);
    printf("%d\n",l3); */
 for (i=0;i<2;i++)
 {
    printf(" ");
 }
    for (j=l2-1;j>=0;j--)
    {
       ch2[j]=ch2[j+2];
       
    }


    
    printf("%s\n",ch2);
    

}