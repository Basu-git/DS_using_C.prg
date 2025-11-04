#include <stdio.h>
#include <ctype.h>
#include <string.h>
#define MAX 3 // Small stack size to demonstrate overflow
char stack[MAX];
int top = -1;
// Push operation
void push(char c) {
if (top == MAX - 1) {
printf("Stack Overflow\n");
return;
}
stack[++top] = c;
}
// Pop operation
char pop() {
if (top == -1) {
printf("Stack Underflow\n");
return '\0';
}
return stack[top--];
}
// Operator precedence
int precedence(char c) {
switch (c) {
case '^': return 3;
case '*': case '/': case '%': return 2;
case '+': case '-': return 1;
default: return 0;
}
}
// Operator check
int isOperator(char c) {
return (c=='+' || c=='-' || c=='*' || c=='/' || c=='%' || c=='^');
}
// Main function
int main() {
char infix[100], postfix[100];
int i, j, choice;
printf("Enter your choice (1-5): ");
scanf("%d", &choice);
switch (choice) {
case 1:
printf("Case 1: Valid infix expression\n");
strcpy(infix, "a+b*(c/d^e-f)^(g+h/i)-j");
break;
case 2:
printf("Case 2: Invalid character\n");
strcpy(infix, "a+b@c/d");
break;
case 3:
printf("Case 3: Mismatched parentheses\n");
strcpy(infix, "a+(b*c/d");
break;
case 4:
printf("Case 4: Stack Overflow (stack size=3)\n");
strcpy(infix, "a+b*(c/d^e-f)^(g+h/i)-j");
break;
case 5:
printf("Case 5: Stack Underflow\n");
strcpy(infix, ")a+b/c(");
break;
default:
printf("Invalid choice\n");
return 0;
}
j = 0;
for (i = 0; i < strlen(infix); i++) {
char c = infix[i];
if (isalnum(c))
postfix[j++] = c;
else if (c == '(')
push(c);
else if (c == ')') {
while (top != -1 && stack[top] != '(')
postfix[j++] = pop();
if (top == -1) {
printf("Mismatched parentheses\n");
return 0;
}
pop();
}
else if (isOperator(c)) {
while (top != -1 && precedence(stack[top]) >= precedence(c))
postfix[j++] = pop();
push(c);
}
else {
printf("Invalid character in expression: %c\n", c);
return 0;
}
}
while (top != -1)
postfix[j++] = pop();
postfix[j] = '\0';
printf("Postfix Expression: %s\n", postfix);
return 0;
}