#include <stdio.h>  
int main ()  
{  
    char str[100]; // declare the size of character array  
    int i;
      
    printf (" Enter the upper case string: ");  
    scanf ("%[^\n]", str); 
   for ( i = 0; str[i]; i++)  
    {  
         
        str[i] = str[i] - 32; 
    }
  
    printf (" \n The lowercase string is: %s", str);  
          
    return 0;  
  
}  