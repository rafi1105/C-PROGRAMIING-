#include <stdio.h>
#include <string.h>
int main()
{
char s1[200];
   int i;
   FILE*read=fopen("e.txt","r");
   while(!feof(read)){
    fgets(s1,200,read);
   }
   fclose(read);
   for (i = 0; s1[i] != '\0'; i++)
   {
       s1[i] -= 7;
   }
   printf("Decoded Text: %s", s1);
   return 0;
}