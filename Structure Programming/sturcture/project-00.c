#include <stdio.h>
#include <string.h>
struct {
    char name[20];
    int id ;
    char dept [20];
    float cgpa;
} st;
add_info(st);
delete_info(st);
search_info(st);

int main ()
{
   while(1)
   {
    printf("1.Add information \n
            2.Search information \n
            3.Delete information \n\n");
   
   printf ("choice your option : ");
   int n;
   scanf("%d", &n);
   switch(n)
  {
    case 1:{
        void add_info(st);
        break;
    }
    case 2 : 
    {
        void search_info(st);
        break;
    }
    case 3 :
    {
        void delete_info(st);
        break;
    }
  } 
   }
}
void add_info(st)
{
    int i;
    
}