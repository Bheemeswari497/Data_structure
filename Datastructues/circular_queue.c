#include<stdio.h>
#include<stdlib.h>
#define SIZE 5
int cqueue[SIZE],f=0,r=0,count=0;
void enq();
void deq();
void display();
int main()
{
	int ch;
	while(1)
	{
	   printf("\n1.Enqueue\n2.Dequeue\n3.Display\n4.Exit\n");
	   printf("Enter your choice:\n");
	   scanf("%d",&ch);
	   switch(ch)
	   {
	   	case 1:enq();break;
	   	case 2:deq();break;
	   	case 3:display();break;
	   	case 4:exit(0);
	   	default:printf("Invalid choice\n");
	   }
	}
	return 0;
}
void enq()
{
	if(count==SIZE)
	{
		printf("Queue is Full\n");
	}
	else
	{
		int ele;
		printf("Enter an Element:\n");
		scanf("%d",&ele);
		cqueue[r]=ele;
		r++;
		if(r > 4)
		r=0;
		count++;
		
	}
}
void deq()
{
	if(count==0)
	{
		printf("Queue is empty\n");
	}
	else
	{
		int ele =cqueue[f];	
		f++;
		if(f>4)
		f=0;
		count--;
		printf("Deleted element is %d\n",ele);
	}
}
void display()
{
	if(count == 0)
	{
		printf("Queue if Empty\n");
	}
	else
	{
		printf("Queue elements: ");
		int i ,temp = f;
		for(i=0;i<count;i++)
		{
			printf("%d",cqueue[temp]);
			temp++;
			if(temp>4) temp=0;
		}
		printf("\n");
	}
}
