#include<stdio.h>
#include<string.h>
#include<stdlib.h>
                                                                //password 221002154
struct Credential
{
    char login[50];
    char pass[10];

} c[100];
int i=0;
void addCredential()
{
    printf("=====================================\n");

    printf("\tEnter Name : ");
    fflush(stdin);
    gets(c[i].login);
    fflush(stdin);

    printf("\tEnter pass  : ");
    gets(c[i].pass);
    i++;
    printf("=====================================\n");

}
void printCredential()
{
    int j;
    printf("=====================================\n");
    printf("\tName \t \t Password\n \n");
    for(j=0; j<=i-1; j++)
    {
        printf("\t%s \t \t %s\n",c[j].login,c[j].pass);
    }
    printf("=====================================\n");
    printf("\n");
}

void updateCredential()
{
    printf("=============================================\n");
    printf("\n Enter Name and Password you want to change \n");
    printf("=============================================\n");
    printf("\tEnter Name : ");
    fflush(stdin);
    char name[50];
    fflush(stdin);
    gets(name);
    printf("\tEnter pass  : ");
    char pass[10];
    gets(pass);
    //printf("=====================================\n");
    int j;
    int a=0;
    for(j=0; j<=i-1; j++)
    {
        int d;
        d=strcmp(pass,c[j].pass);

        int p;
        p=strcmp(name,c[j].login);
        if(d==0 && p==0)
        {
            printf("Enter New Name : ");

            gets(c[j].login);
            printf("Enter new passss :");
            gets(c[j].pass);

            a=1;
        }


    }
    if(a==1)
        printf("password and name update successfully\n");
    else printf("\nInvalid Information\n enter correct name and pass\n try again\n\n");
    printf("=====================================\n");
}

int main()
{

    char pass[]="221002154";
    printf("Enter Password : ");
    char login_pass[10];
    gets(login_pass);
    if(strcmp(pass,login_pass)==0)
    {
        printf("Password Match \n");
    }
    else
    {
        return 0;
    }









    printf("\n\tCredential Information \n \n");
    while(1)
    {
        printf("=====================================\n");
        printf("\t1.add information\n");
        printf("\t2.print information\n");
        printf("\t3.update information\n");
        printf("\t4.Exit\n");
        printf("=====================================\n");
        printf("Enter choice : ");
        int n;
        scanf("%d",&n);
        switch(n)
        {
        case 1:
            addCredential();
            system("cls");
            break;
        case 2:
            system("cls");
            printCredential();
            break;
        case 3:
            system("cls");
            updateCredential() ;
            break;
        case 4:
            system("cls");
            exit(0);

        }
    }

}