#include<stdio.h>
#include<stdlib.h>
struct node
{
	int data;
	struct node *next;
};
struct node *first = NULL;
struct node *last =NULL;
int count =0;
void create();
void display();
void reverse(struct node *temp);
int main()
{
	int ch;
	while(1)
	{
		printf("\n1.create\n2.display\n3.reverse\n4.Exit\n");
		printf("enter your choice:");
		scanf("%d",&ch);
		switch(ch)
		{
			case 1: create(); break;
			case 2: display(); break;
			case 3: 
			      printf("Reversed List:");
			      reverse(first);
			      printf("NULL\n");
			      break;
			case 4: exit(0);
			default:
			printf("Invalid choice. please try again.\n");
		}
	}
	return 0;
}
void create()
{
	int d;
	struct node*newnode =(struct node *)malloc(sizeof(struct node));
	if(newnode == NULL)
	{
		printf("Memory allocation failed.\n");
		return;
	}
	printf("Enter data: ");
	scanf("%d",&d);
	newnode->data =d;
	newnode->next=NULL;
	if (first==NULL)
	{
		first = last =newnode;
	}
	else
	{
		last->next=newnode;
		last=newnode;
	}
	count++;
	printf("Node Added successfully\n");
	void display()
	{
		if(first == NULL)
		printf("List is Empty");
		return;
	}
	struct node *temp= first;
	printf("Linked List:");
	while(temp!=NULL)
	{
		printf("%d->",temp->data);
		temp=temp->next;
	}
	printf("NULL\n");
}
void reverse(struct node *temp)
{
	if(temp== NULL)
	return;
	else
    {
        reverse(temp->next);
        printf("%d->",temp->data);
	}
}
