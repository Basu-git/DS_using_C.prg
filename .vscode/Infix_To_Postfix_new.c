/*Infix to Postfix Conversion Program */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX 100

// ----------------------- Stack Declaration -----------------------
char stack[MAX];
int top = -1;

// ----------------------- Function Declarations -----------------------
void push(char c);
char pop();
char peek();
int isOperator(char c);
int precedence(char c);
void infixToPostfix(char infix[], char postfix[]);

// ----------------------- Main Program -----------------------
int main()
{
    char infix[MAX], postfix[MAX];
    int choice;

    printf("---- INFIX TO POSTFIX CONVERSION ----\n");
    printf("\nChoose a test case:\n");
    printf("1. Valid infix expression\n");
    printf("2. Invalid character\n");
    printf("3. Mismatched parentheses\n");
    printf("4. Wrong operator sequence\n");
    printf("Enter your choice: ");
    scanf("%d", &choice);

    switch (choice)
    {
    case 1:
        strcpy(infix, "a+b*c^d/e-f"); // Valid Infix Expression
        break;
    case 2:
        strcpy(infix, "a+b@c"); // invalid character '@'
        break;
    case 3:
        strcpy(infix, "(a+b*(c-d)"); // missing ')'
        break;
    case 4:
        strcpy(infix, "a++b*c"); // invalid operator sequence
        break;
    default:
        printf("Invalid choice!\n");
        return 0;
    }

    printf("\nGiven Infix Expression: %s\n", infix);

    infixToPostfix(infix, postfix);

    printf("\nPostfix Expression: %s\n", postfix);

    return 0;
}

// ----------------------- Stack Functions -----------------------
void push(char c)
{
    stack[++top] = c;
}

char pop()
{
    return stack[top--];
}

char peek()
{
    return (top == -1) ? '\0' : stack[top];
}

// ----------------------- Helper Functions -----------------------
int isOperator(char c)
{
    return (c == '+' || c == '-' || c == '*' ||
            c == '/' || c == '%' || c == '^');
}

int precedence(char c)
{
    switch (c)
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

// ----------------------- Conversion Logic -----------------------
void infixToPostfix(char infix[], char postfix[])
{
    int i = 0, j = 0;
    char symbol;

    while ((symbol = infix[i++]) != '\0')
    {
        if (isalnum(symbol))
        { // Operand
            postfix[j++] = symbol;
        }
        else if (symbol == '(')
        {
            push(symbol);
        }
        else if (symbol == ')')
        { // Right parenthesis
            while (top != -1 && peek() != '(')
                postfix[j++] = pop();
            if (top == -1)
            { // Mismatched parentheses
                printf("\nError: Mismatched parentheses!\n");
                exit(EXIT_FAILURE);
            }
            pop(); // remove '('
        }
        else if (isOperator(symbol))
        { // Operator
            if (i == 1 || isOperator(infix[i - 2]))
            { // Two operators in a row
                printf("\nError: Invalid operator sequence near '%c'\n", symbol);
                exit(EXIT_FAILURE);
            }
            while (top != -1 && precedence(peek()) >= precedence(symbol))
            {
                // Handle right-associativity for ^
                if (symbol == '^' && peek() == '^')
                    break;
                postfix[j++] = pop();
            }
            push(symbol);
        }
        else
        { // Invalid character
            printf("\nError: Invalid character '%c' in expression!\n", symbol);
            exit(EXIT_FAILURE);
        }
    }

    // Pop remaining operators
    while (top != -1)
    {
        if (peek() == '(')
        {
            printf("\nError: Mismatched parentheses!\n");
            exit(EXIT_FAILURE);
        }
        postfix[j++] = pop();
    }

    postfix[j] = '\0';
}
