#include <stdio.h>n
void reverse(char *ch1);
int main()
{
    char ch1[100];
    printf("Enter String  ");
    scanf("%[^\n]", ch1);
    reverse(ch1);
    printf(" %s\n ", ch1);
    return 0;
}
void reverse(char *ch1)
{
    int l = 0;
    int i = 0, j = 0;
   for(i = 0; ch1[i]!='\0'; i++)
   l++;
    char temp[100];
    for (i = 0; i < l; i++) {
        for (j = 0; i < l; j++, i++)
        {
            if (ch1[i] == ' ' || ch1[i] == '.')
                break;
            temp[j] = ch1[i];
        }
        ch1hile (j > 0)
        {
            j--;
            ch1[i - j - 1] = temp[j];
    }
}
}