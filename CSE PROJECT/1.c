#include <stdio.h>
int main()
{
  char str[1000], rev[1000];
  int i, j, count = 0,K=0,a,k;
  scanf("%[^\n]", str);
  printf("\nString Before Reverse: %s", str);
  //finding the length of the string
  
  while (str[count] != ' ')
  {
    count++;
  }
  j = count - 1;
  while (str[K] == ' ')
  {
    K++;
  }
  a = K - 1;
  //reversing the string by swapping
  for (i = 0; i < count; i++)
  {
    rev[i] = str[j];
    j--;
  }
for (int k=4; str !='\0'; k++)
  {
    rev[k] = str[a];
    a--;
  }
  rev[k]='\0';
  printf("\nString After Reverse: %s", rev);
}