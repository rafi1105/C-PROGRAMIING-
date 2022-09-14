#include <stdio.h>
int main ()
{
	char ch1[20],ch2[10];
	int from,to,i=0,j=0;
	scanf("%[^\n]",ch1);
	printf(" index  start from \n");
	scanf("%d",&from);
	printf(" index end To \n");
	scanf("%d",&to);
	while ( from<=to){
		ch2[j]=ch1[from-1];
		j++;
		from++;
	}
	ch2[j]='\0';
	printf(" the extract substring %s\n",ch2);
}