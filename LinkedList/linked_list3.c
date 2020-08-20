#include<stdio.h>
#include<stdlib.h>

struct node{
	int data;
	struct node* link;
};

struct node* add_node(struct node* ptr, int d)
{
	struct node* temp = (struct node*)malloc(sizeof(struct node));
	temp -> data = d;
	temp -> link = NULL;
	ptr -> link = temp;
	return temp;
}

int main()
{
	struct node* head = (struct node*)malloc(sizeof(struct node));
	head -> data = 20;
	head -> link = NULL;
	struct node* ptr = (struct node*)malloc(sizeof(struct node));
	ptr = add_node(ptr, 30);
	ptr = add_node(ptr, 40);
}


