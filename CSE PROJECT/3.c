#include <stdio.h>
int main ()
{
    int n,i,j;
     char str [19][20];
    char ch1[20],ch2[20],ch0[20],ch4[20],ch5[20];
    scanf ("%d",&n);

    for (i=0;i<=n;i++)
    {

        scanf ("%s", str[i]);

    }
       for (i=0;i<=n;i++)
    {
          printf (" enter the string (%d) : ",str[i]);
    }

}
