#include<stdio.h>
#include<stdlib.h>
struct node
{
	int data;
	struct node *next;
};
struct node *first, *last, *temp=NULL;
void create();
void display();
int main()
{
    int ch;
    while(1)
    {
    	printf("\n1.Create\n2.display\n3.Exit\n");
    	printf("Enter your choice: ");
    	scanf("%d",&ch);
    	switch(ch)
    	{
    		case 1:
			    create();
			    break;
			case 2:
				display();
				break;
		    case 3:
		    	exit(0);
		    	default:printf("Invalid Choice\n");
		    	
		}
	}
	return 0;
}
void create()
{
	int d;
	struct node *newnode=(struct node*)malloc(sizeof(struct node));
	printf("Enter Data: ");
	scanf("%d",&d);
	newnode->data=d;
	newnode->next =NULL;
	if(first == NULL)
	first = last= newnode;
	else
	{
		last->next=newnode;       //fixed linking issue
		last = newnode;
	}
}
void display()
{
	temp =first;
	printf("Linked List: ");
	while(temp!=NULL)
	{
		printf("%d ->",temp->data);
		temp =temp->next;
	}
	printf("NULL\n");
}

