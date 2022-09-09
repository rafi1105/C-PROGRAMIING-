#include <stdio.h>
int main ()
{
  int last=0,i,first=0,middle=0;
  char ch[20],ch1[20];
  printf ("Enter the String : ");
  scanf("%[^\n]",ch);
  for (i=0;ch[i]!='\0';i++)
  {
    last++;
    if ( ch[i] == ' ')
    {
        first =i-1;
        middle=i+1;
    }
  }
    for (int j=0; ch1[j]<=last;j++)
    {
        if(i==first){
             ch[first]=ch1[0];
        }
        else if (i==0)
       {

           ch[0]=ch1[first];
       }
        else if (i==last)
        {
            ch[last]=ch1[middle];
        }
       else if (i==middle)
       {
            ch[middle]=ch1[last];
       }
       else {}
       ch[j]=ch1[j];
    }
    ch1[last+1]='\0';
    printf("the  string is : %s", ch1);

    return 0;
}
