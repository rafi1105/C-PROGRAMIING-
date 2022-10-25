#include <stdio.h>
int main()
{
    int i;
    char ch[20];
    scanf("%[^\n]",ch);
  for (i=0;ch[i]!='\0';i++)
  {
    if (i==0)
    {
        ch[i]=ch[i]-32;
      printf("%c", ch[i]);
    }
    else if (ch[i]==' ')
    {
          ch[i+1]=ch[i+1]-32;
      printf("%c", ch[i+1]);
    }
  }
return 0;
}
