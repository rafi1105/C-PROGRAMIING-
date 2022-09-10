#include <stdio.h>
int main ()
{
  int last,i=0,first,middle,j=0,l=0,temp;
  char ch[20];
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

   for(i=0;i<(last-1)/2;i++)
   {
      ch[i]=temp;
      ch[first]=ch[i];
      ch[first--]=temp;
    }
  ch[i]='\0';
  
    printf ("%d\n",first);
    printf ("%d\n",middle);
    printf ("%d\n",last);
    printf("the  string is : %s", ch);
   
    return 0;
}
