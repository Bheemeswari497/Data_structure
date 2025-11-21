#include<stdio.h>
#include<stdlib.h>
# define size 5
void enq();
void deq();
void display();
int queue[size];
int front=-1,rear=-1,ele;
int main()
{
	int ch;
	while(1)
	{
		printf("\nQueue operation\n");
		printf("1.Enqueue\n2.dequeue\n3.display\n4.exit\n");
		printf("Enter your choice\n");
		scanf("%d",&ch);
		switch(ch)
		{
			case 1:enq();break;
			case 2:deq();break;
			case 3:display();break;
			case 4:exit(0);
			default:printf("invalid Choice\n");
		}
	}
	return 0;
}
void enq()
{
	if(rear == size-1)
	{
		printf("Queue is Full\n");
	}
	else
	{
		printf("Enter an element into the queue:\n");
		scanf("%d",&ele);
		if(front==-1)
		{
			front=0;
		}
		rear++;
		queue[rear]=ele;
	}
}

void deq()
{
	if(front=-1 ||  front>rear)
	{
		printf("Queue is empty\n");
	}
	else
	{
		ele=queue[front];
		front++;
		printf("Deleted element is %d\n",ele);
	}
}
void display()
{
	if(front ==-1 || front>rear)
	{
		printf("Queue is empty");
	}
	else
	{
		int i;
		printf("Queue elements are:");
		for(i=front;i<=rear;i++)
		{
			printf("%d ",queue[i]);
		}
		printf("\n");
	}
}


