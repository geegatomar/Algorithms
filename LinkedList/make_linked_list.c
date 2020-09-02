#include<stdio.h>
#include<stdlib.h>

struct node{
	int val;
	struct node* next;
};

struct node* make_list(int n)
{
	struct node *temp = (struct node*)malloc(sizeof(struct node)), *head = temp, *prev = NULL, *h = head;
	while(n--)
	{
		prev = temp;
		temp = (struct node*)malloc(sizeof(struct node));
		temp -> next = NULL;
		head = prev;
		head -> val = n;
		head -> next = temp;
	}
	head -> next = NULL;
	return h;

}

int count_nodes(struct node* head)
{
	if(head == NULL)
		return 0;
	return 1 + count_nodes(head -> next);
}

int main()
{
	struct node *head = make_list(5), *temp = head, *prev;
	while(temp != NULL)
	{
		printf("%d ", temp -> val);
		temp = temp -> next;
	}
	printf("\n");
	// to insert at beginning
	temp = (struct node *)malloc(sizeof(struct node));
	temp -> val = 5;
	temp -> next = head;
	head = temp;
	
	temp = head;
	while(temp != NULL)
        {
                printf("%d ", temp -> val);
                temp = temp -> next;
        }
	printf("\n");
	// inserting at random position (after 3)
	temp = head;
	prev = head;
	while(temp -> val != 3)
	{
		prev = temp;
		temp = temp -> next;
	}
	struct node *ptr = malloc(sizeof(struct node));
	ptr -> val = 30;
	prev -> next = ptr;
	ptr -> next = temp;

	temp = head;
        while(temp != NULL)
        {
                printf("%d ", temp -> val);
                temp = temp -> next;
        }

	printf("\n%d ", count_nodes(head));
}

