#include <stdio.h>
int main ()
{
    int i;
    char ch[20];
    int vowel = 0,consonat=0;
    scanf("%[^\n]",ch);
    for (i=0;ch[i]!='\0';i++)
    {
if (ch[i] == 'a'||ch[i] == 'e'||ch[i] == 'i'||ch[i] == 'o'||ch[i] == 'u')
        {
                vowel++;
        }
        else 
        {
            consonat++;
        }
       
    }
     printf(" vowel is : %d\n",vowel);
        printf(" consonat is : %d\n",consonat);
}