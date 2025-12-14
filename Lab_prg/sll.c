#include <stdio.h>
#include <stdlib.h>

typedef struct Student {
    char usn[20];
    char name[30];
    char programme[20];
    int sem;
    long long phNo;
    struct Student *next;
} STUD;

STUD* insertFront(STUD *head);
STUD* insertEnd(STUD *head);
STUD* deleteFront(STUD *head);
STUD* deleteEnd(STUD *head);
void display(STUD *head);
int countNodes(STUD *head);

int main() {
    STUD *head = NULL;
    int choice, n, i;

    while (1) {
        printf("\n--- MENU ---\n");
        printf("1. Create SLL using Front Insertion\n");
        printf("2. Display SLL and Count Nodes\n");
        printf("3. Insert at End\n");
        printf("4. Delete at End\n");
        printf("5. Insert at Front (STACK PUSH)\n");
        printf("6. Delete at Front (STACK POP)\n");
        printf("7. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
        case 1:
            printf("Enter number of students: ");
            scanf("%d", &n);
            for (i = 0; i < n; i++)
                head = insertFront(head);
            break;

        case 2:
            display(head);
            printf("Total nodes = %d\n", countNodes(head));
            break;

        case 3:
            head = insertEnd(head);
            break;

        case 4:
            head = deleteEnd(head);
            break;

        case 5:
            head = insertFront(head);
            break;

        case 6:
            head = deleteFront(head);
            break;

        case 7:
            printf("Exiting...\n");
            return 0;

        default:
            printf("Invalid choice. Try again.\n");
        }
    }
}

STUD* insertFront(STUD *head) {
    STUD *temp = (STUD*)malloc(sizeof(STUD));
    printf("Enter USN Name Programme Sem Phone: ");
    scanf("%s %s %s %d %lld",
          temp->usn, temp->name, temp->programme, &temp->sem, &temp->phNo);
    temp->next = head;
    return temp;
}

STUD* insertEnd(STUD *head) {
    STUD *temp = (STUD*)malloc(sizeof(STUD));
    printf("Enter USN Name Programme Sem Phone: ");
    scanf("%s %s %s %d %lld",
          temp->usn, temp->name, temp->programme, &temp->sem, &temp->phNo);
    temp->next = NULL;

    if (head == NULL)
        return temp;

    STUD *ptr = head;
    while (ptr->next != NULL)
        ptr = ptr->next;

    ptr->next = temp;
    return head;
}

STUD* deleteFront(STUD *head) {
    if (head == NULL) {
        printf("List is empty.\n");
        return NULL;
    }
    STUD *temp = head;
    head = head->next;
    printf("Deleted: %s\n", temp->usn);
    free(temp);
    return head;
}

STUD* deleteEnd(STUD *head) {
    if (head == NULL) {
        printf("List empty.\n");
        return NULL;
    }

    if (head->next == NULL) {
        printf("Deleted: %s\n", head->usn);
        free(head);
        return NULL;
    }

    STUD *ptr = head;
    STUD *preptr = NULL;

    while (ptr->next != NULL) {
        preptr = ptr;
        ptr = ptr->next;
    }

    printf("Deleted: %s\n", ptr->usn);
    free(ptr);
    preptr->next = NULL;
    return head;
}

void display(STUD *head) {
    if (head == NULL) {
        printf("SLL is empty.\n");
        return;
    }

    printf("\nSLL Contents:\n");
    while (head != NULL) {
        printf("%s %s %s %d %lld\n",
               head->usn, head->name, head->programme, head->sem, head->phNo);
        head = head->next;
    }
}

int countNodes(STUD *head) {
    int count = 0;
    while (head != NULL) {
        count++;
        head = head->next;
    }
    return count;
}
