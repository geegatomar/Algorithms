#include<stdio.h>
#include<stdlib.h>

struct node{
	int data;
	struct node *link;
};

int main()
{
	struct node* head;
	head = (struct node*)malloc(sizeof(struct node));
	head -> data = 40;
	struct node *node2;
	node2 = (struct node*)malloc(sizeof(struct node));
	node2 -> data = 20;
	head -> link = node2;
	node2 -> link = NULL;

	printf("%d  %d\n", head -> data, node2 -> data); 
	printf("%d\n", (head->link)->data);
}

