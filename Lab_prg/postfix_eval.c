#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <math.h>

struct Stack {
    int top;
    int arr[100];
};

void initStack(struct Stack *stack);
void push(struct Stack *stack, int val);
int pop(struct Stack *stack);
int evaluatePostfix(char *exp);
void removeNewline(char str[]);

int main() {
    char exp[100];

    printf("Enter postfix expression (single-digit operands only): ");
    fgets(exp, sizeof(exp), stdin);

    removeNewline(exp);

    printf("\nPostfix Expression: %s\n", exp);

    int result = evaluatePostfix(exp);
    printf("\nFinal Result: %d\n", result);

    return 0;
}

void removeNewline(char str[]) {
    int i = 0;
    while (str[i] != '\0') {
        if (str[i] == '\n') {
            str[i] = '\0';
            break;
        }
        i++;
    }
}

void initStack(struct Stack *stack) {
    stack->top = -1;
}

void push(struct Stack *stack, int val) {
    stack->arr[++stack->top] = val;
}

int pop(struct Stack *stack) {
    return stack->arr[stack->top--];
}

int evaluatePostfix(char *exp) {
    struct Stack stack;
    initStack(&stack);

    int i = 0;
    while (exp[i] != '\0') {
        if (isdigit(exp[i])) {
            push(&stack, exp[i] - '0');
        }
        else if (exp[i] == ' ') {
            i++;
            continue;
        }
        else {
            int operand2 = pop(&stack);
            int operand1 = pop(&stack);
            int result;

            switch (exp[i]) {
            case '+': result = operand1 + operand2; break;
            case '-': result = operand1 - operand2; break;
            case '*': result = operand1 * operand2; break;
            case '/': result = operand1 / operand2; break;
            case '%': result = operand1 % operand2; break;
            case '^': result = pow(operand1, operand2); break;
            default:
                printf("Invalid operator: %c\n", exp[i]);
                exit(1);
            }
            push(&stack, result);
        }
        i++;
    }
    return pop(&stack);
}
