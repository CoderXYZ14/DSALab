#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

// Define a structure for a node in the linked list
struct Node {
    char data;
    struct Node* next;
};

// Function to push a character onto the linked list stack
void push(struct Node** top, char data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->next = *top;
    *top = newNode;
}

// Function to pop a character from the linked list stack
char pop(struct Node** top) {
    if (*top == NULL) {
        printf("Stack underflow\n");
        exit(1);
    }
    struct Node* temp = *top;
    char data = temp->data;
    *top = temp->next;
    free(temp);
    return data;
}

// Function to return precedence of operators
int precedence(char operator) {
    switch (operator) {
    case '+':
    case '-':
        return 1;
    case '*':
    case '/':
        return 2;
    case '^':
        return 3;
    default:
        return -1;
    }
}

// Function to check if the scanned character is an operator
int isOperator(char ch) {
    return (ch == '+' || ch == '-' || ch == '*' || ch == '/' || ch == '^');
}

// Main function to convert infix expression to postfix expression
char* infixToPostfix(char* infix) {
    int z=0;
    int i, j;
    int len = strlen(infix);
    char* postfix = (char*)malloc(sizeof(char) * (len + 2));
    struct Node* stack = NULL;     //empty stack created
	printf("Input\tStack");
	for(int y=0;y<7;y++)
	printf(" ");
	printf("Result\n");
    for (i = 0, j = 0; i < len; i++) {
        printf("%c",infix[i]);
        printf("\t");
        // If the scanned character is an operand, add it to the postfix expression
        if (isalnum(infix[i])) {
            postfix[j++] = infix[i];
            struct Node* temp = stack;
    		while (temp != NULL) {
        		printf("%c ", temp->data);
        		temp = temp->next;
        		z++;
    		}
        }

        // If the scanned character is '(', push it onto the stack
        else if (infix[i] == '(') {
    		push(&stack, infix[i]);
    		struct Node* temp = stack;
    		while (temp != NULL) {
        		printf("%c ", temp->data);
        		temp = temp->next;
        		z++;
    		}
	}


        // If the scanned character is ')', pop the stack and add to output until '(' is found
        else if (infix[i] == ')') {
            while (stack != NULL && stack->data != '(') {
                postfix[j++] = pop(&stack);
            }
            if (stack == NULL || stack->data != '(') {
                return "Invalid Expression";
            } else {
                pop(&stack); // Pop '('
                struct Node* temp = stack;
    		while (temp != NULL) {
        		printf("%c ", temp->data);
        		temp = temp->next;
        		z++;
    		}
            }
        }

        // If the scanned character is an operator, push it onto the stack
        else if (isOperator(infix[i])) {
        	
            while (stack != NULL && precedence(stack->data) >= precedence(infix[i])) {
                postfix[j++] = pop(&stack);
                
            }
            
            push(&stack,infix[i]);
             struct Node* temp = stack;
    		while (temp != NULL) {
        		printf("%c ", temp->data);
        		temp = temp->next;
        		z++;
    		}
        }
        for(int k=0;k<(15-2*z);k++)
        printf(" ");
        z=0;
        for(int k=0;k<j;k++)
        printf("%c",postfix[k]);
        printf("\n");
    }

    // Pop all remaining elements from the stack
    while (stack != NULL) {
        if (stack->data == '(') {
            return "Invalid Expression";
        }
       postfix[j++] = pop(&stack);
    }

    postfix[j] = '\0';
    return postfix;
}

// Driver code
int main() {
    char infix[100]; // Define a character array to store the input infix expression
    printf("Enter the infix expression: ");
    fgets(infix, sizeof(infix), stdin);

    // Remove the newline character from the input
    size_t len = strlen(infix);
    if (len > 0 && infix[len - 1] == '\n') {
        infix[len - 1] = '\0';
    }

    // Function call
    char* postfix = infixToPostfix(infix);
    printf("Final Result:");
    printf("%s\n", postfix);
    free(postfix);
    return 0;
}


