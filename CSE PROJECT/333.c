#include <stdio.h>
int main ()
{
  int j,i,l=0;
  char ch[10],ch1[10],temp;
  gets(ch);
  for (i=0;ch[i]!='\0';i++)
  l++;
  printf("%d",l);
  for (i=l-1;i>=0;i--) 
  {
    ch[i]=temp;
    temp=ch[i+2];

  }
ch[l+2]='\0';
printf("%s",ch);


  
    return 0;
}
