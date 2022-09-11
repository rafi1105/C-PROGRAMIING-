#include <stdio.h>

int abc(char ch[])
{
    if(ch[0]=='\0')
    {
        return 0;
    }
    return 1 + abc(ch + 1);
}
int main()
{
    char ch[20];

    printf("Enter The String: ");
    gets(ch);

    printf("Length of the string = %d",abc(ch));
    return 0;
}