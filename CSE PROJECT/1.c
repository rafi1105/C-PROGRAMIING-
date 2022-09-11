#include <stdio.h>
#include <string.h>
void reverse_words(char *w);
int main()
{
    char w[100];
    printf("Enter String  ");
    gets(w);
    reverse_words(w);
    printf(" %s\n ", w);
    return 0;
}
void reverse_words(char *w)
{
    int len = strlen(w);
    int i = 0, j = 0;
    char temp[100];
    for (i = 0; i < len; i++) {
        for (j = 0; i < len; j++, i++)
        {
            if (w[i] == ' ' || w[i] == '.')
                break;
            temp[j] = w[i];
        }
        while (j > 0)
        {
            j--;
            w[i - j - 1] = temp[j];
    }
}
}