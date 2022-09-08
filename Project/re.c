#include<stdio.h>
#include<string.h>
int main()
{
	int b,z,i,a,s,g=0,bq,bill=0,arr[5],prr[5],value[5];
	int cgst=0,sgst=0;
	char ch='y',ok='y',order='y';
	const char *crr[50];
	printf("\t\tWelcome to Green Restaurant\n\n");
	printf("Choose your menu :\n\n");
	printf("1. Breakfast\n2. Lunch\n3. Dinner\n\n");
	scanf("%d",&a);
	printf("\n");
	if(a==1)
	{
		do
		{
			printf("\tChoose your order :\n\n\t");
			printf("1.Tost and Egg (50)/-\n\t");
			printf("2.Aloo Porota (60)/-\n\t");
			printf("3.Porota and egg (40)/-\n\t");
			printf("4.Sandwitch (80)/-\n\n\t");
		}while(ch=='n');
		do
		{
			do
			{
				printf("enter no.");
				scanf("%d",&b);
				value[g]=b; // g = no of items
				if(b==1||b==2||b==3||b==4)
				{
					printf("\n\tTell us the Quantity :");
					scanf("%d",&bq);
					arr[b]=bq;
					break;
				}
   				else
				{
					printf("\n\tInvalid Entry.. please try again\n\n\t");
					ok='n';
				}
			}while(ok=='n');
			printf("\n\tAdd more to your order : (Y or N) ?\n\t");
			printf("\n\t");
			g++;
			if(b==1)
			{
				crr[0]="Tost and Egg"; //name 
				prr[0]=50; //price
			}
			else if(b==2)
			{
				crr[1]="Aloo Porota";
				prr[1]=60;
			}
			else if(b==3)
			{
				crr[2]="Porota and egg";
				prr[2]=40;
			}
			else
			{
				crr[3]="Sandwitch";
				prr[3]=80;
			}
		}while(order=='y'||order=='Y');
	}
	else if(a==3)
	{
		do
		{
			printf("\tChoose your order :\n\n\t");
			printf("1.Tandoori Chicken (120)/-\n\t");
			printf("2.Beef Tandoori (140)/-\n\t");
			printf("3.Dal Rice (100)/-\n\t");
			printf("4.Salad/Curd (50)/-\n\n\t");
		}while(ch=='n');
		do
		{
			do{
				printf("enter no.");
				scanf("%d",&b);
				value[g]=b;
				if(b==1||b==2||b==3||b==4)
				{
					printf("\n\tTell us the Quantity :");
					scanf("%d",&bq);
					arr[b]=bq;
					break;
				}
				else
				{
					printf("\n\tInvalid Entry.. please try again\n\n\t");
					ok='n';
				}
			}while(ok=='n');
			printf("\n\tAdd more to your order : (Y or N) ?\n\t");
			printf("\n\t");
			g++;
			if(b==1)
			{
				crr[0]="Tandoori Chicken";
				prr[0]=120;
			}
			else if(b==2)
			{
				crr[1]="Beef Tandoori";
				prr[1]=140;
			}
			else if(b==3)
			{
				crr[2]="Dal Rice";
				prr[2]=100;
			}
			else
			{
				crr[3]="Salad/Curd";
				prr[3]=50;
			}
		}while(order=='y'||order=='Y');
	}
	else if(a==2)
	{
		do
		{
			printf("\tChoose your order :\n\n\t");
			printf("1.Veg Rice\t280/-\n\t");
			printf("2.Mini Rice\t1500/-\n\t");
			printf("3.Salad\t45/-\n\t");
			printf("4.Veg Biryani\t90/-\n\n\t");
		}while(ch=='n');
		do
		{
			do
			{
				printf("enter no.");
				scanf("%d",&b);
				value[g]=b;
				if(b==1||b==2||b==3||b==4)
				{
					printf("\n\tTell us the Quantity :");
					scanf("%d",&bq);
					arr[b]=bq;
					break;
				}
				else
				{
					printf("\n\tInvalid Entry.. please try again\n\n\t");
					ok='n';
				}
			}while(ok=='n');
			printf("\n\tAdd more to your order : (Y or N) ?\n\t");
			fflush(stdin);
			order=getch();
			printf("\n\t");
			g++;
			if(b==1)
			{
				crr[0]="Veg Rice";
				prr[0]=280;
			}
			else if(b==2)
			{
				crr[1]="Mini Rice";
				prr[1]=1500;
			}
			else if(b==3)
			{
				crr[2]="Salad";
				prr[2]=45;
			}
			else
			{
				crr[3]="Veg Biryani";
				prr[3]=90;
			}
		}while(order=='y'||order=='Y');
	}
	printf("\t\tGenerating your BILL....");
	
	printf("\n");
	for(z=1;z<=60;z++)
	{
		printf("_");
	}
	printf("\n\t\t BILL Generated\n\t\t");
	for(z=1;z<=g;z++)
	{
		s=(prr[value[z-1]-1])*(arr[value[z-1]]);
		bill=bill+s;
		printf("\n\t%d.%s\t\t%dx%d\t:%d/-",z,crr[value[z-1]-1],prr[value[z-1]-1],arr[value[z-1]],s);
	}
	printf("\n");
	for(z=1;z<=60;z++)
	{
		printf("_");
	}
	printf("\n\tSum total\t\t:%d/-",bill);
	sgst=((bill/100)*2);
	cgst=sgst;
	printf("\n\t\tCGST 2 prc\t\t:%d/-",cgst);
	printf("\n\t\tSGST 2 prc\t\t:%d/-",sgst);
	bill=bill+sgst+cgst;
	printf("\n\tTotal Bill\t\t:%d/-",bill);
	return 0;
}
