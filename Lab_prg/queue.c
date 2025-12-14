#include <stdio.h>
#include <stdlib.h>

#define MAX 5

char queue[MAX];
int front = -1, rear = -1;

int isFull();
int isEmpty();
void insert(char element);
void deleteElement();
void display();

int main() {
    int choice;
    char element;

    do {
        printf("\n--- Circular Queue Operations ---\n");
        printf("1. Insert an Element\n");
        printf("2. Delete an Element\n");
        printf("3. Display Queue\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        getchar();

        switch (choice) {
        case 1:
            printf("Enter a character to insert: ");
            scanf("%c", &element);
            insert(element);
            break;

        case 2:
            deleteElement();
            break;

        case 3:
            display();
            break;

        case 4:
            printf("Exiting program...\n");
            break;

        default:
            printf("Invalid choice! Please try again.\n");
        }
    } while (choice != 4);

    return 0;
}

int isFull() {
    return (front == (rear + 1) % MAX);
}

int isEmpty() {
    return (front == -1);
}

void insert(char element) {
    if (isFull()) {
        printf("Queue Overflow! Cannot insert '%c'.\n", element);
        return;
    }

    if (isEmpty()) {
        front = rear = 0;
    } else {
        rear = (rear + 1) % MAX;
    }

    queue[rear] = element;
    printf("Inserted '%c' into the queue.\n", element);
}

void deleteElement() {
    if (isEmpty()) {
        printf("Queue Underflow! Nothing to delete.\n");
        return;
    }

    printf("Deleted '%c' from the queue.\n", queue[front]);

    if (front == rear) {
        front = rear = -1;
    } else {
        front = (front + 1) % MAX;
    }
}

void display() {
    if (isEmpty()) {
        printf("Queue is empty!\n");
        return;
    }

    printf("Queue elements: ");
    int i = front;
    do {
        printf("%c ", queue[i]);
        i = (i + 1) % MAX;
    } while (i != (rear + 1) % MAX);
    printf("\n");
}
