#include <stdio.h>
#include <stdlib.h>
// Node structure for doubly linked list
struct node {
    int data;
    struct node* next;
    struct node* prev;
};
// Global pointers
struct node *first = NULL;
struct node *last = NULL;
int count = 0,i;
// Function prototypes
void create();
void displayForward();
void displayBackward();
void insert();
void deleteNode();
int main() {
    int ch;
    while (1) {
        printf("\n1. Create\n2. Display Forward\n3. Display Backward\n4. Insert\n5. Delete\n6. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &ch);
        switch (ch) {
            case 1: create(); break;
            case 2: displayForward(); break;
            case 3: displayBackward(); break;
            case 4: insert(); break;
            case 5: deleteNode(); break;
            case 6: exit(0);
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
    newnode->prev = NULL;
    if (first == NULL) {
        first = last = newnode;
    } else {
        last->next = newnode;
        newnode->prev = last;
        last = newnode;
    }
    count++;
}
// Function to display the linked list in forward direction
void displayForward() {
    if (first == NULL) {
        printf("List is empty!\n");
        return;
    }
    struct node* temp = first;
    printf("Forward Linked List: ");
    while (temp != NULL) {
        printf("%d <-> ", temp->data);
        temp = temp->next;
    }
    printf("NULL\n");
}
// Function to display the linked list in backward direction
void displayBackward() {
    if (last == NULL) {
        printf("List is empty!\n");
        return;
    }
    struct node* temp = last;
    printf("Backward Linked List: ");
    while (temp != NULL) {
        printf("%d -> ", temp->data);
        temp = temp->prev;
    }
    printf("NULL\n");
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
    newnode->next = NULL;
    newnode->prev = NULL;

    if (pos < 1 || pos > count + 1) {
        printf("Invalid position!\n");
        free(newnode);
        return;
    }

    if (pos == 1) { // Insert at the beginning
        newnode->next = first;
        if (first != NULL) 
		first->prev = newnode;
        first = newnode;
        if (last == NULL) 
		last = newnode; // If list was empty
    } else {
        struct node* temp = first;
        for ( i = 1; i < pos - 1; i++) {
            temp = temp->next;
        }
        newnode->next = temp->next;
        newnode->prev = temp;
        if (temp->next != NULL) 
		temp->next->prev = newnode;
        temp->next = newnode;
        if (pos == count + 1) 
		last = newnode;
    }
    count++;
}
// Function to delete a node at a given position
void deleteNode() {
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
    if (pos == 1) { // Delete first node
        first = first->next;
        if (first != NULL) 
		first->prev = NULL;
        else last = NULL; // List becomes empty
        free(temp);
    } else {
        for ( i = 1; i < pos; i++) {
            temp = temp->next;
        }
        temp->prev->next = temp->next;
        if (temp->next != NULL) 
		temp->next->prev = temp->prev;
        else 
		last = temp->prev; // If last node is deleted
        free(temp);
    }
    count--;
}
