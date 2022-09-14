#include <stdio.h>
int main ()
{
  int i,j;
  char ch[20],ch1[20];
  scanf("%[^\n]", ch);
  // abc ghy kio
  for (i=0; ch[i]='\0'; i++)
  {
    if (i==0)
    {
    j=0;
    ch1[j]=ch[i+1];
    j++;
    }
  }
  ch1[j]='\0';
  printf("%s", ch1);
  
  
    return 0;
}
