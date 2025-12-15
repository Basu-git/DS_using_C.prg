#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Employee
{
    char SSN[15];
    char name[50];
    char dept[30];
    char designation[30];
    float salary;
    char phone[15];
    struct Employee *prev, *next;
} Employee;

Employee* createNode();
void insertEnd(Employee** head, Employee** tail);
void insertFront(Employee** head, Employee** tail);
void deleteEnd(Employee** head, Employee** tail);
void deleteFront(Employee** head, Employee** tail);
void displayDLL(Employee* head);
int countNodes(Employee* head);
void menu();

int main()
{
    Employee *head = NULL, *tail = NULL;
    int choice;

    do
    {
        menu();
        printf("\nEnter your choice: ");
        scanf("%d", &choice);

        switch (choice)
        {
        case 1:
            insertEnd(&head, &tail);
            break;

        case 2:
            displayDLL(head);
            printf("Total nodes: %d\n", countNodes(head));
            break;

        case 3:
            insertEnd(&head, &tail);
            break;

        case 4:
            deleteEnd(&head, &tail);
            break;

        case 5:
            insertFront(&head, &tail);
            break;

        case 6:
            deleteFront(&head, &tail);
            break;

        case 7:
            printf("DLL is used as Double Ended Queue.\n");
            break;

        case 8:
            printf("Exiting program.\n");
            break;

        default:
            printf("Invalid choice.\n");
        }
    } while (choice != 8);

    return 0;
}

void menu()
{
    printf("\n----- MENU -----");
    printf("\n1. Create DLL (Insert at End)");
    printf("\n2. Display DLL and Count Nodes");
    printf("\n3. Insert at End");
    printf("\n4. Delete from End");
    printf("\n5. Insert at Front");
    printf("\n6. Delete from Front");
    printf("\n7. Demonstrate Deque");
    printf("\n8. Exit");
}

Employee* createNode()
{
    Employee* newNode = (Employee*)malloc(sizeof(Employee));

    if (newNode == NULL)
    {
        printf("Memory allocation failed.\n");
        exit(1);
    }

    printf("Enter SSN: ");
    scanf("%s", newNode->SSN);

    printf("Enter Name: ");
    scanf("%s", newNode->name);

    printf("Enter Department: ");
    scanf("%s", newNode->dept);

    printf("Enter Designation: ");
    scanf("%s", newNode->designation);

    printf("Enter Salary: ");
    scanf("%f", &newNode->salary);

    printf("Enter Phone: ");
    scanf("%s", newNode->phone);

    newNode->prev = NULL;
    newNode->next = NULL;

    return newNode;
}

void insertEnd(Employee** head, Employee** tail)
{
    Employee* newNode = createNode();

    if (*head == NULL)
    {
        *head = *tail = newNode;
    }
    else
    {
        (*tail)->next = newNode;
        newNode->prev = *tail;
        *tail = newNode;
    }

    printf("Inserted at end.\n");
}

void insertFront(Employee** head, Employee** tail)
{
    Employee* newNode = createNode();

    if (*head == NULL)
    {
        *head = *tail = newNode;
    }
    else
    {
        newNode->next = *head;
        (*head)->prev = newNode;
        *head = newNode;
    }

    printf("Inserted at front.\n");
}

void deleteEnd(Employee** head, Employee** tail)
{
    if (*tail == NULL)
    {
        printf("DLL is empty.\n");
        return;
    }

    Employee* temp = *tail;

    if (*head == *tail)
    {
        *head = *tail = NULL;
    }
    else
    {
        *tail = (*tail)->prev;
        (*tail)->next = NULL;
    }

    free(temp);
    printf("Deleted from end.\n");
}

void deleteFront(Employee** head, Employee** tail)
{
    if (*head == NULL)
    {
        printf("DLL is empty.\n");
        return;
    }

    Employee* temp = *head;

    if (*head == *tail)
    {
        *head = *tail = NULL;
    }
    else
    {
        *head = (*head)->next;
        (*head)->prev = NULL;
    }

    free(temp);
    printf("Deleted from front.\n");
}

void displayDLL(Employee* head)
{
    if (head == NULL)
    {
        printf("DLL is empty.\n");
        return;
    }

    Employee* temp = head;

    while (temp != NULL)
    {
        printf("SSN:%s Name:%s Dept:%s Desig:%s Salary:%.2f Phone:%s\n",
               temp->SSN, temp->name, temp->dept,
               temp->designation, temp->salary, temp->phone);
        temp = temp->next;
    }
}

int countNodes(Employee* head)
{
    int count = 0;
    Employee* temp = head;

    while (temp != NULL)
    {
        count++;
        temp = temp->next;
    }

    return count;
}
