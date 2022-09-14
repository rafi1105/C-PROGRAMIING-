#include <stdio.h>
#include <string.h>
void calling (int larger,int x)
{
	int i;
	for (i=0;i<larger-x;i++)
	printf(" ");
}
int main()
{
	
	char string[10][30]; 
	int i, n,larger,x,y,z,p;
	printf("Enter number of strings to input\n");
	scanf("%d", &n);
	printf("Enter Strings one by one: \n");
	for(i=0; i< n ; i++) {
		scanf("%s",string[i]);
	}
larger=0;
	for(i=0; i< n ; i++) 
	{
		
		if (larger<strlen(string[i]))
		{
			larger=strlen(string[i]);
		}
	}
	for(i=0; i< n ; i++) 
	{
		if (i==0)
		x=strlen(string[i]);
		else if (i==1)
		y=strlen(string[i]);
		else if (i==2)
		z=strlen(string[i]);
		else if (i==3)
		p=strlen(string[i]);
	}
	printf("right align is : \n");
 calling (larger,x);
printf("%s\n",string[0]);
 calling (larger,y);
printf("%s\n",string[1]);
 calling (larger,z);
printf("%s\n",string[2]);
 calling (larger,p);
printf("%s\n",string[3]);
}