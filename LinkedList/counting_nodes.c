#include<stdio.h>
#include<stdlib.h>

struct node{
	int data;
	struct node *link;
};

int count_no_nodes(struct node* ptr)
{
	int cnt = 0;
	while(ptr != NULL)
	{
		cnt++;
		printf("%d\n", ptr -> data); 
		ptr = ptr -> link;
	}
	return cnt;
}

int main()
{
	struct node* head = (struct node*)malloc(sizeof(struct node));
	head -> data = 10;
	head -> link = NULL;
	
	struct node* current = (struct node*)malloc(sizeof(struct node));
	current -> data = 20;
	current -> link = NULL;
	head -> link = current;

	current = (struct node*)malloc(sizeof(struct node));
	current -> data = 30;
	current -> link = NULL;
	head -> link -> link = current;

	printf("%d\n", count_no_nodes(head));
}
