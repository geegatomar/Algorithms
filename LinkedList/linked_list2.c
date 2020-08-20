#include<stdio.h>
#include<stdlib.h>

struct node{
	int data;
	struct node* link;
};

int main()
{
	int arr[] = {1, 2, 3, 4, 5, 6};
	int i, j, n = sizeof(arr)/sizeof(arr[0]);
	struct node* head = (struct node*)malloc(sizeof(struct node));
	head -> data = 0;
	head -> link = NULL;
	struct node* curr = head;
	for(i = 0; i < n; i++)
	{
		struct node* new = (struct node*)malloc(sizeof(struct node));
		new -> data = arr[i];
		new -> link = NULL;
		curr -> link = new;
		curr = new;
	}
	struct node* ptr = head;
	while(ptr -> link != NULL)
	{
		printf("%d\n", ptr -> data);
		ptr = ptr -> link;
	}
}

