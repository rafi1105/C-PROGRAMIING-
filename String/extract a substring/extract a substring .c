#include <stdio.h>

/*Function declaration*/
int getSubString(char *source, char *target,int from, int to);

int main()
{
	char text [100]={0};
	char text1[50] ={0};
	int from,to;
	
	printf("Enter a string: ");
	fgets(text,100,stdin);
	
	printf("Enter from index: ");
	scanf("%d",&from);
	printf("Enter to index: ");
	scanf("%d",&to);	
	
	printf("String is: %s\n",text);
	
	if(getSubString(text,text1,from,to)==0)
	    printf("Substring is: %s\n",text1);
    else
        printf("Function execution failed!!!\n");
	
	return 0;
}

/*Function definition*/
int  getSubString(char *source, char *target,int from, int to)
{
	int length=0;
	int i=0,j=0;
	
	//get length
	while(source[i++]!='\0')
		length++;
	
	if(from<0 || from>length){
		printf("Invalid \'from\' index\n");
		return 1;
	}
	if(to>length){
		printf("Invalid \'to\' index\n");
		return 1;
	}	
	
	for(i=from,j=0;i<=to;i++,j++){
		target[j]=source[i];
	}
	
	//assign NULL at the end of string
	target[j]='\0'; 
	
	return 0;	
}
