#include <stdio.h>
#include <stdlib.h>
int main ()
{
	int a[]={3,5,6,5};
	int *h=a;
	h=(int*)malloc (sizeof(int));
	printf ("\n %d\n", *h);
}