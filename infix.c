#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX 100

char stack[MAX];
int top = -1;

void push(char c);
char pop();
char peek();
int isOperator(char c);
int precedence(char c);
void infixToPostfix(char infix[], char postfix[]);

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
            strcpy(infix, "a+b*c^d/e-f");
            break;
        case 2:
            strcpy(infix, "a+b@c");
            break;
        case 3:
            strcpy(infix, "(a+b*(c-d)");
            break;
        case 4:
            strcpy(infix, "a++b*c");
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

int isOperator(char c) 
{
    return (c == '+' || c == '-' || c == '*' ||
            c == '/' || c == '%' || c == '^');
}

int precedence(char c) 
{
    switch (c) 
    {
        case '^': return 3;
        case '*':
        case '/':
        case '%': return 2;
        case '+':
        case '-': return 1;
        default: return 0;
    }
}

void infixToPostfix(char infix[], char postfix[]) 
{
    int i = 0, j = 0;
    char symbol;

    while ((symbol = infix[i++]) != '\0') 
    {
        if (isalnum(symbol)) 
        {
            postfix[j++] = symbol;
        }
        else if (symbol == '(') 
        {
            push(symbol);
        }
        else if (symbol == ')') 
        {
            while (top != -1 && peek() != '(')
                postfix[j++] = pop();
            if (top == -1) 
            {
                printf("\nError: Mismatched parentheses!\n");
                exit(EXIT_FAILURE);
            }
            pop();
        }
        else if (isOperator(symbol)) 
        {
            if (i == 1 || isOperator(infix[i - 2])) 
            {
                printf("\nError: Invalid operator sequence near '%c'\n", symbol);
                exit(EXIT_FAILURE);
            }
            while (top != -1 && precedence(peek()) >= precedence(symbol)) 
            {
                if (symbol == '^' && peek() == '^') break;
                postfix[j++] = pop();
            }
            push(symbol);
        }
        else 
        {
            printf("\nError: Invalid character '%c' in expression!\n", symbol);
            exit(EXIT_FAILURE);
        }
    }

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
