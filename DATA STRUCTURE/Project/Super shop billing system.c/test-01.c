#include <stdio.h>
int main()
{
int a[5],n,i,bill[10],j=0;
float x;
 printf("\20*******************  WELCOME TO RK SUPER SHOP **************************\20\n");
printf("\t\t    PLEASE CHOICE YOUR PRODUCT :\20\n");
printf("\t\t  \20>-------------------------------<\20\n");
printf (" 1. COOKIES \n 2. CHIPS \n 3. DRINKS \n 4. Meat\n ");
   
        scanf("%d",&i);

if (i==1)
{
   cookies:
            printf (" 1. Potato 20 Tk..\n 2. Energy 15 Tk..\n 3. Boom 20 Tk..\n 4. Orio 50 Tk..\n ");
            scanf("%d",&n);
            switch(n)
            {
                case 1:
                    {
                        j++;
                     bill[j]=20;
                    }
                    break;
                case 2:
                    {
                        j++;
                     bill[j]=15;
                    }
                    break;
    goto cookies;
            }
}

    return 0;
}
