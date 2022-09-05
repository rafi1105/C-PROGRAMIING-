#include<stdio.h>
#include<stdlib.h>
int again;
int total=0;
float gst,cgst,sgst;
int cookies[7][2]={  {0,30},
                    {1,35},
                    {2,40},
                    {3,20},
                    {4,15},
                    {5,20},
                    {6,30}
                };
int vagetable_and_meat[7][2]={{0,80},
                {1,120},
                {2,20},
                {3,120},
                {4,150},
                {5,160},
                {6,30}};
int drinks[7][2]={{0,65},
                {1,50},
                {2,70},
                {3,80},
                {4,65},
                {5,110},
                {6,50}};
int purchased[][3]={{0,0},
                        {0,0},
                        {0,0},
                        {0,0},
                        {0,0},
                        {0,0},
                        {0,0}
                        };
int temp[][3]={{0,0},
                        {0,0},
                        {0,0},
                        {0,0},
                        {0,0},
                        {0,0},
                        {0,0}
                        };
void cookies(char cookiesitem[][100]);
void vegetable_and_meat( char vegetable_and_meatitem[][100]);
void drinks(char drinksitem[][100]);
void main_item();
void display();
void vegetable_and_meat_itemcard();
void drinks_item();
void display_cookies_bill(char cookiesitem[][100]);
void display_vegetable_and_meat_bill(char vegetable_and_meatitem[][100]);
void display_drinks_bill(char drinksitem[][100]);
void display_cookiesitem();
void repeatcookies(char cookiesitem[][100]);
void repeatvegetable_and_meat(char vegetable_and_meatitem[][100]);
void repeatdrinks(char drinksitem[][100]);
void display_total_words();
void main()
{
    char cookiesitem[][100]={"toast","Idli-wada","Dosa","Upma","milk","tea","coffee"};
    char vegetable_and_meatitem[][100]={"Veg Biryani","Special meal","Roti","Dal","Paneer Tikka","Veg mix","Icecream"};
    char drinksitem[][100]={"Fried rice","Spegatti","Burger"};
    char choice;
    do
    {
        enter:
        display();
        printf("Enter your choice here : ");
        scanf("%c", &choice);
        getchar();
        switch(choice)
        {
            case 'A':
            case 'a':printf("\nCOOKIES\n");
                    cookies(cookiesitem);
                    break;
            case 'B':
             case 'b':printf("\nvegetable_and_meat\n");
                    vegetable_and_meat(vegetable_and_meatitem);
                    break;
             case 'C':
            case 'c':printf("\ndrinks\n");
                    drinks(drinksitem);
                    break;
           default:printf("\nWrong choice entered Please enter the valid choice!!\n");
                    goto enter;
        }
    }while(choice!='d');
}
void display()
{
    printf("                Welcome to abc Restaurant.          \n ");
    printf("             +============================+          \n\n");
    printf("  && Please select the meal that you would like to purchase. && \n\n");
    printf("\t\t      [A] Breakfast\n");
    printf("\t\t      [B] vegetable_and_meat\n");
    printf("\t\t      [C] drinks\n");
}
void display_cookiesitem()
{
    printf("                Welcome to abc Restaurant.          \n ");
    printf("             +============================+          \n\n");
    printf("                  $  Breakfast item  $ \n\n");
    printf("  && Please select the food that you would like to purchase. && \n\n");
    printf("\t\t   [0] Toast - Rs 30.00\n");
    printf("\t\t   [1] Idli-Vada - Rs 35.00\n");
    printf("\t\t   [2] Dosa - Rs 40.00\n");
    printf("\t\t   [3] UPMA Rs 20.00\n");
    printf("\t\t   [4] Milk- Rs 15.00\n");
    printf("\t\t   [5] Tea - Rs 20.00\n");
    printf("\t\t   [6] Coffee - Rs 30.00\n");
}
void cookies(char cookiesitem[][100]) //Breakfast item Screen
{
    int choice = 0; //local variables
    int quantity = 0;
    int again = 0,amt=0;
    int code,i;
    display_cookiesitem();
    printf("\nEnter the code:: ");
    scanf("%d", &code);
    getchar();
    printf("Total is %d\n\n",total);
    if(code>=0&&code<=6)
    {
        printf("\nEnter the quantity::");
        scanf("%d",&quantity);
        purchased[code][1]= quantity*cookiesrate[code][1]; /*purchased[code][1]+ (quantity*cookiesrate[code][1]);*/
        total+=purchased[code][ 1];
        printf("Total is %d\n\n",total);
        gst=total*0.12;
        cgst=gst/2;
        sgst=cgst;
    }
    else
    {
        printf("\nInvalid code entered, Please enter the code again!!!!\n\n");
        cookies(cookiesitem);
    }
    repeatcookies(cookiesitem);
}
void repeatcookies(char cookiesitem[][100])
{
    printf("\nWould you like to buy anything else?\n[1] Yes , [2] No : "); // Allows user to choose whether to check-out or buy anything else.
    scanf("%d",&again);
    if (again == 1)
            cookies(cookiesitem);
    else if (again == 2 )
    {
        display_cookies_bill(cookiesitem);
        exit(0);
    }
    else
    {
        printf("\n\n\t\tSorry Invalid Decision Entered\n");
        repeatcookies(cookiesitem);
    }
}
void display_cookies_bill(char cookiesitem[][100])
{
    int i;
    printf("  +~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~+          \n\n");
    printf("                      abc RESTAURANT                   \n");
    printf("                    BILLING INFORMATION                \n");
    printf("\t\t ITEMS\t\tPrice(in Rs.)\n");
    for(i=0;i<7;i++)
    {
        if(purchased[i][1]!=0)
        {
            printf("\t\t%s\t\t",cookiesitem[i]);
            printf("%d\n",purchased[i][1]); /*purchased[i][1]);*/
        }
    }
    printf("\t\tGST=Rs.%0.2f\n",gst);
    printf("\t\tC-GST=Rs.%0.2f\n",cgst);
    printf("\t\tS-GST=Rs.%0.2f\n",sgst);
    printf("\t\tTotal=Rs.%d\n",total);
    display_total_words();
    printf("\n\n  +~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~+          \n\n");

}
void display_vegetable_and_meat_bill(char vegetable_and_meatitem[][100])
{
    int i;
    printf("  +~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~+          \n\n");
    printf("                      abc RESTAURANT                   \n");
    printf("                    BILLING INFORMATION                \n");
    printf("\t\t ITEMS\t\t\tPrice(in Rs.)\n");
    for(i=0;i<7;i++)
    {
        if(purchased[i][1]!=0)
        {
            printf("\t\t %s \t\t",vegetable_and_meatitem[i]);
            printf("%d\n",purchased[i][1]);
        }
    }
    printf("\t\tGST=Rs.%0.2f\n",gst);
    printf("\t\tC-GST=Rs.%0.2f\n",cgst);
    printf("\t\tS-GST=Rs.%0.2f\n",sgst);
    printf("\t\tTotal=Rs.%d\n",total);
    display_total_words();
    printf("\n\n  +~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~+          \n\n");
}
void display_drinks_bill(char drinksitem[][100])
{
    int i;
    printf("  +~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~+          \n\n");
    printf("                      abc RESTAURANT                   \n");
    printf("                    BILLING INFORMATION                \n");
    printf("\t\t ITEMS\t\t\tPrice(in Rs.)\n");
    for(i=0;i<7;i++)
    {
        if(purchased[i][1]!=0)
        {
            printf("\t\t %s \t\t",drinksitem[i]);
            printf("%d\n",purchased[i][1]);
        }

    }
    printf("\t\tGST=Rs.%0.2f\n",gst);
    printf("\t\tC-GST=Rs.%0.2f\n",cgst);
    printf("\t\tS-GST=Rs.%0.2f\n",sgst);
    printf("\t\tTotal=Rs.%d\n\n",total);
    display_total_words();
    printf("\n\n  +~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~+          \n\n");
}
void vegetable_and_meat(char vegetable_and_meatitem[][100]) // vegetable_and_meat Screen item
{
    int choice = 0; //local variables
    int quantity = 0;
    int again = 0,amt=0;
    int code,i;
    vegetable_and_meat_itemcard();
    printf("\nEnter the code:: ");
    scanf("%d", &code);
    getchar();
    if(code>=0&&code<=6)
    {
        printf("\nEnter the quantity::");
        scanf("%d",&quantity);
       // purchased[code][1]= purchased[code][1]+(quantity*vegetable_and_meatrate[code][1]);
        purchased[code][1]= quantity*vegetable_and_meatrate[code][1];
         total+=purchased[code][ 1];
        gst=total*0.12;
        cgst=gst/2;
        sgst=cgst;
    }
    else
    {
        printf("\nInvalid code entered, Please enter the code again!!!!\n\n");
         vegetable_and_meat(vegetable_and_meatitem);
    }
    repeatvegetable_and_meat(vegetable_and_meatitem);
}
void drinks(char drinksitem[][100]) // drinks item Screen
{
    int choice = 0; //local variables
    int quantity = 0;
    int again = 0,amt=0;
    int code,i;
    drinks_item();

    printf("\nEnter the code:: ");
    scanf("%d", &code);
    getchar();
    if(code>=0&&code<=6)
    {
        printf("\nEnter the quantity::");
        scanf("%d",&quantity);
       // purchased[code][1]= purchased[code][1]+(quantity*drinks_rate[code][1]);
        purchased[code][1]= quantity*drinks_rate[code][1];
        total+=purchased[code][1];
        gst=total*0.12;
        cgst=gst/2;
        sgst=cgst;
    }
    else
    {
        printf("\nInvalid code entered, Please enter the code again!!!!\n\n");
        drinks(drinksitem);
    }
    repeatdrinks(drinksitem);
}
void vegetable_and_meat_itemcard()
{
    printf("                Welcome to abc Restaurant.          \n ");
    printf("             +============================+          \n\n");
    printf("                   $  vegetable_and_meat item  $ \n\n");
    printf("  && Please select the food that you would like to purchase. && \n\n");
    printf("\t\t   [0] Veg Biryani - Rs 80.00\n");
    printf("\t\t   [1] Special Meal- Rs 120.00\n");
    printf("\t\t   [2] Roti - Rs 20.00\n");
    printf("\t\t   [3] Dal tadka - Rs 120.00\n");
    printf("\t\t   [4] Paneer Tikka - Rs 150.00\n");
    printf("\t\t   [5] Veg Mix - Rs 160.00\n");
    printf("\t\t   [6] Ice cream - Rs 30.00\n");
    printf("Enter your choice here : ");
}
void drinks_item()
{
    printf("                Welcome to abc Restaurant.          \n ");
    printf("             +============================+          \n\n");
    printf("                    $  drinks item  $ \n\n");
    printf("  && Please select the food that you would like to purchase. && \n\n");
    printf("\t\t   [0] Fried Rice - Rs 65.00\n");
    printf("\t\t   [1] Spagetti- Rs50\n");
    printf("\t\t   [2] Burger - Rs 70.00\n");
    printf("\t\t   [3] Pasta - Rs 80.00\n");
    printf("\t\t   [4] Noodles - Rs 65.00\n");
    printf("\t\t   [5] Paratha - Rs 110.00\n");
    printf("\t\t   [6] Fruit Salad - Rs 50.00\n");
}
void repeatvegetable_and_meat(char vegetable_and_meatitem[][100])
{
    printf("\nWould you like to buy anything else?\n[1] Yes , [2] No : "); // Allows user to choose whether to check-out or buy anything else.
    scanf("%d",&again);
    if (again == 1)
            vegetable_and_meat(vegetable_and_meatitem);
    else if (again == 2 )
    {
        display_vegetable_and_meat_bill(vegetable_and_meatitem);
        exit(0);
    }
    else
    {
        printf("\n\n\t\tSorry Invalid Decision Entered\n");
        repeatvegetable_and_meat(vegetable_and_meatitem);
    }
}
void repeatdrinks(char drinksitem[][100])
{

    printf("\nWould you like to buy anything else?\n[1] Yes , [2] No : "); // Allows user to choose whether to check-out or buy anything else.
    scanf("%d",&again);
    if (again == 1)
    {
        drinks(drinksitem);
    }
    else if (again == 2 )
    {
        display_drinks_bill(drinksitem);
        exit(0);
    }
    else
    {
        printf("\n\n\t\tSorry Invalid Decision Entered\n");
        repeatdrinks(drinksitem);
    }
}
void display_total_words()
{
    int num=0,digits=0,temp=0;
    while(total != 0)
    {
        num=(num * 10)+(total % 10);
        total/= 10;
        digits++;
    }
    printf("\nNo of digits::%d\n",digits);
    while(num!= 0)
    {
        temp++;
        switch(num%10)
        {
            case 0:
                printf("Zero ");
                break;
            case 1:
                printf("One ");
                break;
            case 2:
                printf("Two ");
                break;
            case 3:
                printf("Three ");
                break;
            case 4:
                printf("Four ");
                break;
            case 5:
                printf("Five ");
                break;
            case 6:
                printf("Six ");
                break;
            case 7:
                printf("Seven ");
                break;
            case 8:
                printf("Eight ");
                break;
            case 9:
                printf("Nine ");
                break;
        }
        num = num / 10;
    }
    if(num==0&&digits!=temp)
        printf(" Zero ");
    return;
}

