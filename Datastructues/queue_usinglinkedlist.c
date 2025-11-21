#include<stdio.h>
#include<stdlib.h>
void enq();
void deq();
void display();
struct node
{
	int data;
	struct node*next ;
};
struct node *newnode = NULL;
struct node *temp = NULL;
struct node *front = NULL;
struct node *rear  = NULL;
int ele;
int main()
{
	int ch;
	while(1)
	{
	printf("\n1.Enqueue\n2. Dequeue\n3. Display\n4. Exit\n");
	printf("Enter your choice:");
	scanf("%d",&ch);
	
	switch (ch) {
		case 1: enq(); break;
		case 2: deq(); break;
		case 3: display(); break;
		case 4: exit(0);
		default : printf("Invalid choice!\n");
	}
	}
	return 0;
}
void enq()
{
	newnode= (struct node*)malloc(sizeof(struct node));
	if(newnode==NULL){
		printf("Memory allocation failed\n");
		return ;
	}
	printf("Enter data:");
	scanf("%d",&ele);
	newnode->data=ele;
	newnode->next=NULL;
	
	if(rear==NULL)
	{
		front = rear= newnode;
	}
	else
	{
		rear->next = newnode;
		rear=newnode;
	}
	
}
void deq()
{
	if(front == NULL)
	{
		printf("Queue is empty\n");
	}
	else
	{
		temp= front ;
		ele = front ->data;
		printf("Deleted data is %d\n",ele);
		front = front ->next;
		free(temp);
		if(front == NULL)
		{
			rear = NULL;
		}
	}
}
void display()
{
	if(front == NULL)
	{
		printf("Queue is empty\n");
	}
	else
	{
		temp = front ;
		printf("\nNode Data\tNode Address\n");
		while(temp!=NULL)
		{
			printf("%4d\t\t%p\n", temp->data,temp);
			temp = temp->next;
		}
	}
}
