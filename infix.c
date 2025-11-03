#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>   // For isalnum() and isdigit()
#include <string.h>  // For strlen()

// ---------------------------
// Function Prototypes
// ---------------------------
void infixToPostfix(char infix[], char postfix[]);
int precedence(char operator);
int isOperator(char symbol);
void push(char stack[], int *top, char symbol);
char pop(char stack[], int *top);
char peek(char stack[], int top);

// ---------------------------
// Main Function
// ---------------------------
int main()
{
	char infix[100], postfix[100];

	printf("Enter a valid infix expression (single-digit operands only): ");
	scanf("%s", infix);   // Input from keyboard

	infixToPostfix(infix, postfix);

	printf("\nPostfix Expression: %s\n", postfix);
	return 0;
}

// ---------------------------
// Function: infixToPostfix()
// Converts infix to postfix
// ---------------------------
void infixToPostfix(char infix[], char postfix[])
{
	char stack[100];
	int top = -1;
	int i = 0, j = 0;

	while (infix[i] != '\0')
	{
		// Case 1: Operand (AbZ, abz, or 0b9)
		if (isalnum(infix[i]))
		{
			postfix[j++] = infix[i];
		}
		// Case 2: Left Parenthesis '('
		else if (infix[i] == '(')
		{
			push(stack, &top, infix[i]);
		}
		// Case 3: Right Parenthesis ')'
		else if (infix[i] == ')')
		{
			while (top != -1 && peek(stack, top) != '(')
			{
				postfix[j++] = pop(stack, &top);
			}
			if (top == -1)
			{
				printf("\nError: Mismatched parentheses!\n");
				exit(EXIT_FAILURE);
			}
			pop(stack, &top); // Discard '('
		}
		// Case 4: Operator
		else if (isOperator(infix[i]))
		{
			while (top != -1 && precedence(peek(stack, top)) >= precedence(infix[i]))
			{
				// Handle right-associative '^'
				if (infix[i] == '^' && peek(stack, top) == '^')
					break;
				postfix[j++] = pop(stack, &top);
			}
			push(stack, &top, infix[i]);
		}
		// Case 5: Invalid Character
		else
		{
			printf("\nError: Invalid character '%c' in expression!\n", infix[i]);
			exit(EXIT_FAILURE);
		}

		i++;
	}

	// Pop all remaining operators from stack
	while (top != -1)
	{
		if (peek(stack, top) == '(')
		{
			printf("\nError: Mismatched parentheses!\n");
			exit(EXIT_FAILURE);
		}
		postfix[j++] = pop(stack, &top);
	}

	postfix[j] = '\0'; // Null terminate the postfix expression
}

// ---------------------------
// Function: isOperator()
// Checks if symbol is operator
// ---------------------------
int isOperator(char symbol)
{
	return (symbol == '+' || symbol == '-' ||
	        symbol == '*' || symbol == '/' ||
	        symbol == '%' || symbol == '^');
}

// ---------------------------
// Function: precedence()
// Returns precedence of operator
// ---------------------------
int precedence(char operator)
{
	switch (operator)
	{
	case '^':
		return 3;
	case '*':
	case '/':
	case '%':
		return 2;
	case '+':
	case '-':
		return 1;
	default:
		return 0;
	}
}

// ---------------------------
// Stack Operations
// ---------------------------
void push(char stack[], int *top, char symbol)
{
	if (*top == 99)
	{
		printf("\nError: Stack overflow!\n");
		exit(EXIT_FAILURE);
	}
	stack[++(*top)] = symbol;
}

char pop(char stack[], int *top)
{
	if (*top == -1)
	{
		printf("\nError: Stack underflow!\n");
		exit(EXIT_FAILURE);
	}
	return stack[(*top)--];
}

char peek(char stack[], int top)
{
	if (top == -1)
		return '\0';
	return stack[top];
}