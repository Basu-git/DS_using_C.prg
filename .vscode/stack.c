#include <stdio.h>
 #include <stdbool.h>
 #include <limits.h>
 #define MAX 5

 struct Stack
{
        int arr[MAX];
        int top;
        };
    void initializeStack(struct Stack *s);
    bool isFull(struct Stack *s);
    bool isEmpty(struct Stack *s);
    void push(struct Stack *s, int element);
    int pop(struct Stack *s);
   void displayStatus(struct Stack *s);
  void checkPalindrome(struct Stack *s);
   void menu();
    int main()
   {
       struct Stack stack;
       initializeStack(&stack);

       int choice, element;

      do
      {
          menu();
            printf("Enter your choice: ");
           scanf("%d", &choice);

           switch (choice)
           {
 case 1:
                    printf("Enter element to push: ");
                    scanf("%d", &element);
                    push(&stack, element);
                    break;

              case 2:
                   element = pop(&stack);
                    if (element != INT_MIN)
                    {
                       printf("Popped element: %d\n", element);
                   }
                   break;

               case 3:
                    checkPalindrome(&stack);
                   break;

               case 4:
                    displayStatus(&stack);
                    break;

              case 5:
                   printf("Exiting program.\n");
                    return 0;

               default:
                   printf("Invalid choice. Please try again.\n");
           }

       } while (choice != 5);

       return 0;
    }
         void initializeStack(struct Stack *s)
   {
        s->top = -1;
    }


    bool isFull(struct Stack *s)
   {
       return s->top == MAX - 1;
   }


    bool isEmpty(struct Stack *s)
   {
        return s->top == -1;
    }


   void push(struct Stack *s, int element)
   {
        if (isFull(s))
       {
            printf("Stack overflow! Cannot push element.\n");
        } else
        {
           s->arr[++s->top] = element;
            printf("Element %d pushed onto the stack.\n", element);
        }
    }


    int pop(struct Stack *s)
    {
        if (isEmpty(s))
        {
            printf("Stack underflow! Cannot pop element.\n");
            return INT_MIN;
        } else
       {
           return s->arr[s->top--];
        }
    }


    void displayStatus(struct Stack *s)
   {
        if (isEmpty(s))
      {
          printf("Stack is empty.\n");
        } else
        {
                printf("Stack elements: ");
                for (int i = 0; i <= s->top; ++i)
                {
                  printf("%d ", s->arr[i]);
                 }
           printf("\n");
            printf("Current top index: %d\n", s->top);
           if (isFull(s))
    {
               printf("Stack is full.\n");
             }
     }
   }

    void checkPalindrome(struct Stack *s)
  {
    if (isEmpty(s))
   {
    printf("Stack is empty. Cannot check palindrome.\n");
  return;
    }

   struct Stack tempStack;
    initializeStack(&tempStack);
   int originalTop = s->top;

    for (int i = 0; i <= originalTop; ++i)
   {
    push(&tempStack, s->arr[i]);
    }

   bool isPalindrome = true;


   for (int i = 0; i <= originalTop; ++i)
   {
    int popped = pop(&tempStack);
    if (popped == s->arr[i])
   {
    continue;
    } else {
   isPalindrome = false;
    break;
    }
    }

   if (isPalindrome)
   {
    printf("The stack is a palindrome.\n");
    } else {
    printf("The stack is not a palindrome.\n");
    }
    }


    void menu()
      {
        printf("\nMenu:\n");
        printf("1. Push an element onto stack\n");
        printf("2. Pop an element from stack\n");
        printf("3. Check for Palindrome\n");
        printf("4. Display stack status\n");
       printf("5. Exit\n");
     }