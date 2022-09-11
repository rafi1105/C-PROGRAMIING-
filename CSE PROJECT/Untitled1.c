
#include <stdio.h>
int main ()
{
    char ch[20],ch1[20];
    int j=0,i,k=0;
    scanf ("%s",ch);
 for (i=0;ch[i]!='\0';i++)
        j++;
    for (i=19;i>=0;i--)
    {
        if (i==15)
            ch[i]='  ';
       else  if (i==14)
            ch[i]='  ';
           if (i==13)
            ch[i]='  ';
       else  if (i==12)
            ch[i]='  ';
        ch[i]=ch[k];


        k++;
    }

        printf ("%s",ch);
}
