#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

#define MAX 100

int stack[MAX];
int top = -1;

// Push operation
void push(int value) {
    if (top == MAX - 1) {
        printf("Stack overflow\n");
        exit(1);
    }
    stack[++top] = value;
}

// Pop operation
int pop() {
    if (top == -1) {
        printf("Stack underflow\n");
        exit(1);
    }
    return stack[top--];
}

// Function to evaluate postfix expression
int evaluatePostfix(char* exp)
 {
    int i;
    for (i = 0; exp[i] != '\0'; i++) 
	{
        char ch = exp[i];

        if (isdigit(ch)) {
            // Convert character to integer and push
            push(ch - '0');
        } else {
            // Operator encountered
            int val2 = pop();
            int val1 = pop();

            switch (ch) {
                case '+': push(val1 + val2); break;
                case '-': push(val1 - val2); break;
                case '*': push(val1 * val2); break;
                case '/': push(val1 / val2); break;
                default:
                    printf("Invalid operator: %c\n", ch);
                    exit(1);
            }
        }
    }

    return pop(); // Final result
}

int main() {
    char postfix[MAX];

    printf("Enter a postfix expression (e.g., 231*+9-): ");
    scanf("%s", postfix);

    int result = evaluatePostfix(postfix);
    printf("Result = %d\n", result);

    return 0;
}

