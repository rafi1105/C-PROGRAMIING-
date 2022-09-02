#include <stdio.h>
#include <string.h>
#include <stdlib.h>
char * test(char * text) {
  if (!text[0])
    return "No string found.";
    char *tt = text;
    while(*tt != '\0')
    {
        if (*tt >= 'a' && *tt  <= 'z')
        {
            *tt = *tt + 'A' - 'a';
        }
        tt++;
    }
    return text;
}
int main() {
 //char text[50] = "";    
 char text[50] = "Python";
  //char text[50] = "abcdcsd";
    printf("Original string: %s",text);
    printf("\nReplace each lowercase letter with the same uppercase in the said string:\n%s ",test(text));
    return 0;
} 