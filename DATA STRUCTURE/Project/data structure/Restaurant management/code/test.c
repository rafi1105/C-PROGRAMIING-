#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <conio.h>

void option ();
void insert (char n[], float p, int fin);
void display ();

void order ();
void Log();
int login();
void display_rd_hist();
struct items
{
    char name[50];
    float rating;
    float price;
    int food_Id_No;
    struct items*next;
    struct items*prev;
};
int cust_id =1,Today_customer=0;
struct items*head;
struct items*last;
float total_income=0;
void Log()
{
    printf("\n");
            int k=login();
         //   int e;
            if (k==1)
            {
                do{
                    printf("\n---------------------------------------------------------------------------------\n");
                    printf("1.          ADD NEW DISH\n");
                    printf("2.          TODAY'S TOTAL INCOME\n");
                    printf("3.          TODAY'S TOTAL NO OF CUSTOMER\n");
                    printf("4.          ORDER HISTORY\n");
                    printf("5.          LIST OF items\n");
                    printf("6.          MAIN MENU\n");
                    printf("\n---------------------------------------------------------------------------------\n");
                    int ch;
                    scanf("%d", &ch);
                    switch (ch)
                    {
                    case 1:
                    printf(" ");
                    float p;
                    int fin;
                    char n[50];

                    printf("Enter the name of items : ");
                    scanf("%s",n);
                     printf("Enter the price of items : ");
                    scanf("%f",&p);
                    printf("Enter the food_Id_No of items : ");
                    scanf("%d",&fin);
                    insert(n,p,fin);
                    printf("\n--------------------------------------------------------------------------------\n");
                    printf("                         NEW DISH IS ADDED SUCCESSFULLY........\n");
                    printf("\n--------------------------------------------------------------------------------\n");
                        break;
                    case 2:
                    printf("\n--------------------------------------------------------------------------------\n");
                    printf("                         TODAY;S TOTAL INCOME IS :- %f\n",total_income);
                    printf("\n--------------------------------------------------------------------------------\n");
                    break;
                    case 3: 
                    printf("\n--------------------------------------------------------------------------------\n");
                    printf("                         TODAY TOTAL NO OF CUSTOMER VISITED ID :-%d\n",Today_customer);
                    printf("\n--------------------------------------------------------------------------------\n");
                    break;
                    case 4:
                    printf("\n--------------------------------------------------------------------------------\n");
                    printf("                         ORDER SUMMARY........\n");
                    printf("\n--------------------------------------------------------------------------------\n");
                    display_rd_hist();
                    printf("\n");
                    break;
                    case 5: display();
                    break;
                    case 6: option();
                     break;
                    default: printf("\nwrong choice\n");
                        break;
                    }
                }while(1);
            }
            
        
}
 void option ()
 {
     head=last=NULL;
    insert ("Burger    ",70.00,1);
    insert ("Prizza    ",280.00,2);
    insert ("Hot Cake    ",750.00,3);
    insert ("Coffee    ",100.00,4);
    insert ("Ice-Cream  ",50.00,5);
    insert ("Sandwich    ",60.00,6);
    insert ("Grill    ",100.00,7);
    insert ("Nun    ",30.00,8);
    insert ("Cold Drink    ",20.00,9);

    int choice;
    do{
        printf ("\n MOMO IN Restuarent\n");
             printf ("\n Bogura 5* star Hotel\n");
        printf("\n________________________________________________________________\n");
        printf("\n1    CUSTOMER PANEL");
        printf("\n2    ADMIN PANEL");
        printf("\n3    EXIT");
        printf("\n________________________________________________________________\n");
        printf("Enter your choice : ");
        scanf("%d",&choice);
        switch(choice)
        {
            case 1:
            int ex;
            do{
                printf("\n");
                printf("1.     FOOD LIST \n");
                printf("2.     ODER\n3.     ADMIN PANEL\n");
              //  printf("3.    ADMIN PANEL\n");
                printf("4.     EXIT \n\n");
                int n;
                scanf ("%d", &n);
                switch (n)
                {
                case 1: display();
                    break;
                case 2: order();
                    break;
                case 3: Log();
                    break;
                case 4: exit(0);
                    break;
                default:
                printf("Wrong choice");
                    break;
                }
                printf("1. FOOD PART\n2. MAIN MENU\n");
                scanf("%d", &ex);
                if (ex==2){
                    option();
                    break;
                }
                
            }while(/*ex=*/1);
            break;
            case 2: 
            Log();
            break;
            default: {
                option();
            }
            }
    }while (1);
 }
struct order_hist
{
    int customer_ID;
    int items[10][2];
    float amount;
    char date[11];
    struct order_hist*next;
    struct order_hist*prev;
};

struct order_hist*head1;
struct order_hist*last1;

struct items*getnewNode(char a[], float p, int fin)
{
    struct items* temp=(struct items*)malloc(sizeof(struct items));
    temp-> food_Id_No=fin;
    strcpy(temp->name, a);
    temp->rating=4.0;
    temp->price =p;
    temp->next=NULL;
    temp->prev=NULL;
    return temp;
}

void insert (char n[], float p, int fin)
{
    struct items* temp1=getnewNode(n,p,fin);
    if (head==NULL)
    {
        head=temp1;
        last=temp1;
    }
    else{
        temp1->prev=last;
        last->next= temp1;
        last=temp1;
    }
}
struct order_hist*getnewNode_hist()
{
    struct order_hist*temp=(struct order_hist*)malloc(sizeof(struct order_hist));
    temp->next = temp->prev=NULL;
    return(temp);
}
void display()
{
    printf("\n***** MENU *****\n");
    printf("INDEX items NAME PRICE RATING \n");
    struct items* temp=head;
    if (head==NULL)
    {
        printf("Empty\n");
    }
    while (temp!= NULL)
    {
        printf("%d\t %s\t %f\t %f\n", temp->food_Id_No, temp->name,temp->price, temp->rating);
        temp=temp->next;
    }
    printf("\n-------------------------------------------------------------------------------------------------\n");
}

int login()
{
    char username[20];
    char userpwd[10];
    int i;
    printf("Enter your username : ");
    scanf ("%s", username);
    printf("\n");
    for (i=0;i<8;i++)
    {
        userpwd[i]=getch();
        printf("*");
    }
    userpwd[i]='\0';

    if (!strcmp(username,"Admin")&& !strcmp (userpwd, "rafi1105"))
    {
        printf ("\n \n Logged in Successfully\n");
        return 1;
    }
    else 
    {
        printf("\n \n Incorrect username or password\n");
        return 0;
    }
}
 void order ()
 {
    printf("\n");
    printf ("1. Burger            70.00\n");
    printf ("2.Prizza             280.00\n");
    printf ("3.Hot Cake           750.00\n");
    printf ("4.Coffee             100.00\n");
    printf ("5.Ice-Cream          50.00\n");
    printf ("6.Sandwich           60.00\n");
    printf ("7.Grill              100.00\n");
    printf ("8.Nun                30.00\n");
    printf ("9.Cold Drink         20.00\n\n");
    int a[10][2];
    int n,j=0,i=0;
    
    do {
        printf("Please enter the FOOD IF NUMBER OF items AND ITS QUENTITY:- ");
        for (i=0; i<2; i++)
        {
            scanf ("%d",&a[j][i]);
        }
        j++;
        printf("you want More items \n1. yes\n2.no\n");
        scanf ("%d",&n);
    }
    while (n==1);
    float total_amount=0.0;
    char name [25];
    char Date [10];
    printf("Enter your Name : ");
    scanf("%s", name);
    printf ("Enter Today's Date : ");
    scanf("%s", Date);
    int k=0;
    printf("\n ----------------------------------------------------------------------------------------------- \n");
        printf("\n                                   MOMO IN Restuarant                                     \n");
    printf("\n                                       BILL -> %s                                          \n",name);
    printf("\n ----------------------------------------------------------------------------------------------- \n");
    printf("Name :-%s\n",name);
    printf("Date:-%s\n",Date);
    for (k=0; k<j;k++)
    {
        struct items *temp=head;
        while (temp->food_Id_No !=a[k][0])
        {
            temp=temp->next;
        // total_amount = total_amount+ (a[k][1]*(temp->price));
        }
        printf("\n----------------------------------------------------------------------------------------------\n");
        printf("%d\t%s\t%d\t\t %f",temp->food_Id_No,temp->name,a[k][1],(a[k][1]*(temp->price)));
         total_amount = total_amount+ (a[k][1]*(temp->price));
    }
 
        printf("\n----------------------------------------------------------------------------------------------\n");
        printf("\nTotal Payble amount is :-\t\t%f\n",total_amount);
        printf("------------------------------------------------------------------------------------------------\n");
        

 struct order_hist* temp2=getnewNode_hist();
 temp2->amount=total_amount;
 temp2->customer_ID=cust_id++;

 int p,s;
 for (p=0;p<j; p++)
 {
    for (s=0; s<2; s++)
    {
        temp2->items[p][s]=a[p][s];
    }
 }
 if (head1== NULL)
 {
    {
        head1=last1=temp2;
    }
 }
 else
 {
    last1->next=temp2;
    temp2->prev = last1;
    last1=temp2;
 }
 strcpy(temp2->date,Date);
 Today_customer++;
 total_income+=total_amount;
 void option ();
 }

 void display_rd_hist()
 {
    printf("                                    -------------                                              \n");
    printf("                                    ORDER HISTORY                                              \n");
    printf("                                    -------------                                              \n");
    printf("SR_NO     DATE     TOTAL AMOUNT\n");
    struct order_hist *temp=head1;
    if (head1==NULL)
    {
        printf ("No history available");
    }
    else 
    {
        while (temp->next !=NULL){
            printf("%d\t%s\t%f\t\n",temp->customer_ID,temp->date,temp->amount);
        temp=temp->next;
        }
        
    }
 }
 int main()
 {
   option ();
 
 }