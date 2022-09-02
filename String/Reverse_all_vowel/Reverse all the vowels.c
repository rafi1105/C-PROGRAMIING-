#include <stdio.h>
#include <string.h>


char* test(char* text, int l) {
    int i=0;
    int arr[120]={0};
    arr['a']=1;arr['e']=1;arr['i']=1;arr['o']=1;arr['u']=1;
    arr['A']=1;arr['E']=1;arr['I']=1;arr['O']=1;arr['U']=1;
    while(i<l)
    {
        if(arr[text[i]]==1&&arr[text[l]]==1)
        {
            text[i]=text[i]^text[l];
            text[l]=text[i]^text[l];
            text[i]=text[i]^text[l];
            i++;
            l--;
        }
        while(arr[text[i]]!=1&&i<l)
        {i++;}
        while(arr[text[l]]!=1&&i<l)
        {l--;}
    }
    return text;
}
int main() {
  char string1[80];
  int n, i, x, l;
  printf("Input a string: ");
  scanf("%s", string1);
  l = strlen(string1);
  if(l-1>=1)
  printf("Check bracket in the said string is valid or not? %s", test(string1, l));
}
