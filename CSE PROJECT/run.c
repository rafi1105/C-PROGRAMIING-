#include <stdio.h>
#include <string.h> /* Header file to support string functions */

void main() {
  /* Declaration of variables used within this program. */
  char first[100], second[20];
  int i, j, fsl, ssl, temp, chk = 0;
  
  /* Take input from the user and save it to the first variable. */
  printf("Enter the String: ");
  gets(first);
  
  /* Take input from the user and save it to the second variable. */
  printf("Enter a Word: ");
  gets(second);
  
  /* Using the strlen function to calculate length of the given string. */
  fsl = strlen(first); //fsl =4
  ssl = strlen(second); // ssl=2

  /* Loop iteration to remove the second string from the first string. */
  for (i = 0; i < fsl; i++) {
    temp = i; // temp- 0
    for (j = 0; j < ssl; j++) 
    { // j<2 
      if (first[i] == second[j])
        i++;
    }
    chk = i - temp;
    if (chk == ssl) {
      i = temp;
      for (j = i; j < (fsl - ssl); j++)
        first[j] = first[j + ssl];
      fsl = fsl - ssl;
      first[j] = '\0';
    }
  }
  
  /*Finally, printing the result. */
  printf("\nNew String = %s", first);
}