#include <stdio.h>
#include <stdlib.h>
// Node structure
struct node {
    int data;
    struct node* next;
};
// Global pointers
struct node *first = NULL;
struct node *last = NULL;
int count = 0;
// Function prototypes
void create();
void display();
void insert();
void deleteNode();

int main() {
    int ch;
    while (1) {
        printf("\n1. Create\n2. Display\n3. Insert\n4. Delete\n5. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &ch);

        switch (ch) {
            case 1: create(); break;
            case 2: display(); break;
    		case 3: insert(); break;
            case 4: deleteNode(); break;
            case 5: exit(0);
            default: printf("Invalid choice! Try again.\n");
        }
    }
    return 0;
}

// Function to create a new node at the end
void create() {
    struct node* newnode = (struct node*)malloc(sizeof(struct node));
    if (newnode == NULL) {
        printf("Memory allocation failed!\n");
        return;
    }
    
    printf("Enter data: ");
    scanf("%d", &newnode->data);
    
    newnode->next = NULL;

    if (first == NULL) {
        first = last = newnode;
        last->next = first; // Making it circular
    } else {
        last->next = newnode;
        last = newnode;
        last->next = first; // Maintain circular link
    }
    count++;
}
// Function to display the circular linked list
void display() {
    if (first == NULL) {
        printf("List is empty!\n");
        return;
    }

    struct node* temp = first;
    printf("Circular Linked List: ");
    do {
        printf("%d -> ", temp->data);
        temp = temp->next;
    } while (temp != first);
    printf("(Back to %d)\n", first->data);
}

// Function to insert a node at a given position
void insert() {
    int pos, x;
    struct node* newnode = (struct node*)malloc(sizeof(struct node));
    if (newnode == NULL) {
        printf("Memory allocation failed!\n");
        return;
    }

    printf("Enter position to insert (1-%d): ", count + 1);
    scanf("%d", &pos);
    printf("Enter data: ");
    scanf("%d", &x);
	newnode->data = x;

    if (pos < 1 || pos > count + 1) {
        printf("Invalid position!\n");
        free(newnode);
        return;
    }

    if (pos == 1) {  // Insert at beginning
        newnode->next = first;
        first = newnode;
        last->next = first; // Update last node's next pointer
    } else {
        struct node* temp = first;
        int i;
        for ( i = 1; i < pos - 1; i++) {
            temp = temp->next;
        }
        newnode->next = temp->next;
        temp->next = newnode;

        if (pos == count + 1) {  // Insert at end
            last = newnode;
            last->next = first;
        }
    }
    count++;
}
// Function to delete a node at a given position
void deleteNode() 
{
    int pos;
    if (first == NULL) {
        printf("List is empty!\n");
        return;
    }

    printf("Enter position to delete (1-%d): ", count);
    scanf("%d", &pos);

    if (pos < 1 || pos > count) {
        printf("Invalid position!\n");
        return;
    }

    struct node* temp = first;
    int i;
    if (pos == 1) { // Delete first node
        if (first == last) { // Only one node
            free(first);
            first = last = NULL;
        } else {
            first = first->next;
            last->next = first;
            free(temp);
        }
    } 
	else 
	{
        struct node* prev = NULL;
        for ( i = 1; i < pos; i++) {
            prev = temp;
            temp = temp->next;
        }
		prev->next = temp->next;
        if (pos == count) { // If deleting last node
            last = prev;
            last->next = first;
        }
        free(temp);
    }
    count--;
}
