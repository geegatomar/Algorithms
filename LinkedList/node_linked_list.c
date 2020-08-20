#include<stdio.h>
#include<stdlib.h>

struct node{
	int data;
	struct node *link;
};

int main()
{
	struct node *head = NULL;
	// head is a pointer of type struct node, which is now pointing to NULL, but we will later make it point to an object of struct node type after we allocate memory for it. This memory allocation is done by malloc
	head = (struct node *)malloc(sizeof(struct node));
	head->data = 40;
	head->link = NULL;
	printf("%d", head->data);

	// imp to understand that there is only one way to access the node which is using the pointer head here.
}

