#include <stdio.h>
int main()
{
    int num,d;
    printf("enter the num\n");
    scanf("%d",&num);
    d=num/10;
    switch(d)
    {
        case 10:
        case 9:
        case 8 :
        {
            printf("A+");
        }
        break;
        case 7:
        {
            printf("A");
        }
        break;
        case 6:
        {
            printf("A-");
        }
        break;
        case 5 :
        {
            printf("B");
        }
        break;
        case 4 :
        {
            printf("C");
        }
        case 3 :
        {
                printf("F");
        }
        break;
    }

return 0;
}
