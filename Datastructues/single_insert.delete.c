#include<stdio.h>
#include<stdlib.h>
struct node {
	int data;
	struct node *next;
};
struct node *first=NULL,*last=NULL,*temp=NULL;
int count=0;
void create();
void display();
void insert();
void deleteNode();
void search();
int main()
{
	int ch;
    while(1)
    {
    	printf("\n1.Create\n2.Display\n.3 insert\n4.delete\n5.search\n6.exit\n");
    	printf("Enter your choice: ");
    	scanf("%d",&ch);
    	switch(ch) {
    		case 1: create();
    		       break;
    	    case 2: display();
    	           break;
    	    case 3: exit(0);
    	          break;
    	    case 4: insert();
    	         break;
    	    case 5: deleteNode();
    	          break;
    	    case 6: search();
    	    break;
    	    
    	    default:printf("Invalid choice\n");
		}
	}
	return 0;	
}
void create()
{
	int d;
	struct node* newnode=(struct node*)malloc(sizeof(struct node));
	printf("Enter date: ");
	scanf("%d",&d);
	newnode->data=d;
	newnode->next=NULL;
	if(first==NULL)
	    first=last=newnode;
	    else
	    {
	    	last->next=newnode;
	    	last=newnode;
		}
}
void display()
{
	temp=first;
	printf("Linked list: ");
	while(temp!=NULL)
	{
		printf("%d-> ",temp->data);
		temp=temp->next;
	}
	printf("NULL\n");
}
void insert() {
	int pos,x;
	struct node* newnode=(struct node*)malloc(sizeof(struct node));
	printf("Enter position to insert (1-%d): ",count+1);
	scanf("%d",&pos);
	printf("Enter data: ");
	scanf("%d",&x);
	newnode->data=x;
	newnode->next=NULL;
	if(pos<1||pos>count+1) {
		printf("Invalid position!\n");
		free(newnode);
		return;
	}
	if(pos==1)
	{
		newnode->next=first;
		first=newnode;
	} else {
		struct node* temp=first;
		int i;
		for(i=1;i<pos-1;i++)
		{
			temp=temp->next;
		}
		newnode->next=temp->next;
		temp->next=newnode;
		if(pos==count+1) {
			last=newnode;
		}
	}
	count++;
	
}

void deleteNode() {
 	int pos,i;
 	if(first==NULL) {
 		printf("List is empty!\n");
 		return;
	 }
	 printf("Enter position to delete(1-%d): ",count);
	 scanf("%d",&pos);
	 if(pos<1||pos>count)
	 {
	 	printf("Invalid position!\n");
	 	return;
	 }
	 struct node*temp=first;
	 if(pos==1) {
	 	first=first->next;
	 	free(temp);
	 } else {
	 	struct node* prev=NULL;
	 	for(i=1;i<pos;i++)
	 	{
	 		prev=temp;
	 		temp=temp->next;
		 }
		 prev->next=temp->next;
		 if(pos==count)
		 {
		 	last=prev;
		 }
		 free(temp);
	 }
	 count--;
}
void search() {
	int key,found=0;
	if(first==NULL) {
		printf("List is empty!\n");
		return;
	}
	printf("Enter value to search: ");
	scanf("%d",&key);
	struct node* temp=first;
	int i=1;
	while(temp!=NULL) {
		if(temp->data==key) {
			printf("Value %d found at position %d\n",key,i);
			found=1;
		}
		temp=temp->next;
		i++;
	}
}
