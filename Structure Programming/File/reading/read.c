#include <stdio.h>
#include <stdlib.h>

int main()
{
   int num,i;
   FILE *fptr;

   if ((fptr = fopen("program.txt","r")) == NULL){
       printf("Error! opening file");

       // Program exits if the file pointer returns NULL.
       exit(1);
   }

   fscanf(fptr,"%d %d", &num,&i);

   printf("Value of n=%d\n %d", num,i);
   fclose(fptr); 
  
   return 0;
}