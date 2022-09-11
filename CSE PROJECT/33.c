#include <stdio.h>
 
int main()
{
   int num;
   char words[50][50];
   printf("Enter number of words:");
   scanf("%d", &num);
   printf("Enter words:\n");
   int i;
   for (i = 0; i < num; i++)
   {
       scanf("%s", words[i]);
   }
   printf("\nOutput:\n");
   for (i = 0; i < num; i++)
   {
       printf("%10s\n", words[i]);
   }
   return 0;
}