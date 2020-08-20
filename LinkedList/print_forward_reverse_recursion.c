#include<stdio.h>
#include<stdlib.h>

struct node{
	int data;
	struct node* next;
};

void printForward(struct node* ptr)
{
	if(!ptr)
		return;
	printf("%d ", ptr -> data);
	printForward(ptr -> next);

}

void printReverse(struct node* ptr)
{
	if(!ptr)
		return;
	printReverse(ptr -> next);
	printf("%d ", ptr -> data); 
}

int main()
{
	struct node* head = (struct node*)malloc(sizeof(struct node));
	head -> data = 10;
	head -> next = NULL;
	struct node* ptr = (struct node*)malloc(sizeof(struct node));
	head -> next = ptr;
	ptr -> data = 20;
	ptr -> next = NULL;
	ptr = (struct node*)malloc(sizeof(struct node));
	ptr -> data = 30;
	ptr -> next = NULL;
	head -> next -> next = ptr;
	//printf("%d %d %d ", head->data, head->next->data, head->next->next->data);
	printForward(head); printf("\n");
	printReverse(head); printf("\n");
}

