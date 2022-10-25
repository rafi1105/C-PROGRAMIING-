#include <stdio.h>
int main()
{
    int i,l=0;
    char ch[20];
    scanf("%[^\n]",ch);
  for (i=0;ch[i]!='\0';i++)
  {
    l++;
  }
    for (int j=l-1;j>=0;j--)
    {
        printf("%c",ch[j]);
    }
}