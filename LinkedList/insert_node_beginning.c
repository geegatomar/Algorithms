#include<stdio.h>
#include<stdlib.h>

struct node{
	int data;
	struct node* link;
};

int main()
{
	struct node* head = (struct node*)malloc(sizeof(struct node));
	head -> data = 1;
	head -> link = NULL;
	struct node* ptr = (struct node*)malloc(sizeof(struct node));
	ptr -> data = 2;
	head -> link = ptr;
	ptr -> link = NULL;

	// add 3 at the beginning
	
	ptr = (struct node*)malloc(sizeof(struct node));
	ptr -> data = 3;
	ptr -> link = head;
	head = ptr;

	ptr = head;
	while(ptr != NULL)
	{
		printf("%d\n", ptr -> data);
	        ptr = ptr -> link;	
	}
}

