// Iterative C program to find length or count
// of nodes in a linked list
#include<stdio.h>
#include<stdlib.h>

// Link list node
struct Node
{
	int data;
	struct Node* next;
};

/* Given a reference (pointer to pointer) to
the head of a list and an int, push a new
node on the front of the list. */
void push(struct Node** head_ref,
		int new_data)
{
	// Allocate node
	struct Node* new_node =
		(struct Node*) malloc(sizeof(struct Node));

	// Put in the data
	new_node->data = new_data;

	// Link the old list off the new node
	new_node->next = (*head_ref);

	// Move the head to point to the new node
	(*head_ref) = new_node;
}

// Counts no. of nodes in linked list
int getCount(struct Node* head)
{
	// Initialize count
	int count = 0;

	// Initialize current
	struct Node* current = head;
	while (current != NULL)
	{
		count++;
		current = current->next;
	}
	return count;
}

// Driver code
int main()
{
	// Start with the empty list
	struct Node* head = NULL;

	// Use push() to construct list
	// 1->2->1->3->1
	push(&head, 1);
	push(&head, 3);
	push(&head, 1);
	push(&head, 2);
	push(&head, 1);

	// Check the count function
	printf("count of nodes is %d",
			getCount(head));
	return 0;
}
