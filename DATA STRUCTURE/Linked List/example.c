#include <stdio.h>
#include <stdlib.h>
struct Node 
{
	int data;
	struct Node*next;
}*head;
void creatnode(int n)
{
	struct Node *new_node,*temp;
	int data,i;
	head= (struct Node*) malloc(sizeof(struct Node));
	if ( head==NULL )
	{
		printf (" memory not allocated\n");
	}
	else 
	{
		printf (" Enter the  node 1 : ");
		scanf("%d",& head->data);
		head -> next =NULL;
		temp=head;
		for ( i =2 ; i <=n ; i++ )
		{
			
				new_node = (struct Node*) malloc (sizeof(struct Node));
				if ( new_node ==NULL)
			{
				printf ( "memory not allocated");
			}
			else 
			{
				printf ("enter the node %d : ",i);
				scanf("%d", &new_node->data);
				new_node -> next = NULL;
				temp->next = new_node;
				temp = temp -> next;
			}
		}
	}

}
void firstdeltetion()
{
	struct Node *del;
	del=head;
	head =head -> next;
	printf (" data deleting is : %d \n", del -> data);
	free(del);
}
void displaytheNode ()
{
	struct Node *temp;
	if (head==NULL)
	printf("list is Empty");
	else {
		temp =head;
	while ( temp !=NULL )
	{
	  printf ( " the value of node is :%d \n", temp -> data);
	  temp = temp -> next;
	}
	}
	
}
int main ()
{
	int n;
	printf(" linked list : display the list of nodes : \n ");
	printf("enter the number of nodes : ");
	scanf("%d", &n);
	creatnode(n);
	
	printf ("after deleting node is : \n");
	printf ("-----------------------------------\n");
	firstdeltetion();
	printf(" The node display is :\n ");
	printf("--------------------------------\n");
	displaytheNode();
}