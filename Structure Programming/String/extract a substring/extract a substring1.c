#include <stdio.h>
void main() 
{
   char str[100], sstr[100];
   int pos, l, c = 0;
   
       printf("\n\nExtract a substring from a given string:\n");
       printf("--------------------------------------------\n");  
 
       printf("Input the string : ");
       scanf ("%[^\n]", str);
 
   printf("Input the position to start extraction :");
   scanf("%d", &pos);
   
   printf("Input the length of substring :");
   scanf("%d", &l);
 
   while (pos <= l) 
   {
      sstr[c] = str[pos-1];
      pos++;
      c++;
   }
   sstr[c] = '\0';
 
   printf("The substring retrieve from the string is :  %s \n\n", sstr);
 
}