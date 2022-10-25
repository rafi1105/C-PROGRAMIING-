#include<stdio.h>
int main()
{
    int i=0;
    char s[50];
    printf("Enter String : ");
   scanf("%[^\n]",s);
    while(s[i]!='\0')
    {
        if(s[i]==' ')
        {
            s[i]='*';
        }
        i++;
    }
    printf("%s",s);
    return 0;
}