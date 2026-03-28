#include <stdio.h>
#include <stdlib.h>

#define SIZE 5

int queue[SIZE];
int front = -1;
int rear = -1;

int isFull() {
    // Full if rear has wrapped around and caught up to front
    if ((front == 0 && rear == SIZE - 1) || (rear == (front - 1) % (SIZE - 1))) {
        return 1;
    }
    return 0;
}

int isEmpty() {
    // Empty when front is -1 (queue never used or was reset)
    if (front == -1) {
        return 1;
    }
    return 0;
}

void enqueue(int value) {
    if (isFull()) {
        printf("Queue Overflow");
    } else {
        if (front == -1) {
            front = rear = 0;        // First element — initialise both pointers
        } else if (rear == SIZE - 1 && front != 0) {
            rear = 0;                // rear hit the end — wrap around to index 0
        } else {
            rear++;                  // Normal case — just move rear forward
        }
        queue[rear] = value;
        printf("Inserted %d", value);
    }
}

void dequeue() {
    if (isEmpty()) {
        printf("Queue Underflow");
    } else {
        int data = queue[front];
        printf("Deleted element: %d", data);

        if (front == rear) {
            front = rear = -1;       // Last element removed — reset queue
        } else if (front == SIZE - 1) {
            front = 0;               // front hit the end — wrap around to index 0
        } else {
            front++;                 // Normal case — just move front forward
        }
    }
}

void peek() {
    if (isEmpty()) {
        printf("Queue is empty.");
    } else {
        printf("Front element is: %d", queue[front]); // Show without removing
    }
}

void display() {
    if (isEmpty()) {
        printf("Queue is empty.");
        return;
    }
    printf("Elements in Circular Queue: ");
    if (rear >= front) {
        // Normal case — no wrap, print front to rear directly
        for (int i = front; i <= rear; i++)
            printf("%d ", queue[i]);
    } else {
        // Wrapped case — print front to end, then 0 to rear
        for (int i = front; i < SIZE; i++)
            printf("%d ", queue[i]);
        for (int i = 0; i <= rear; i++)
            printf("%d ", queue[i]);
    }
    printf("\n");
}

int main() {
    int choice, val;

    while (1) {
        printf("\n\n--- Circular Queue Menu ---");
        printf("\n1. Enqueue");
        printf("\n2. Dequeue");
        printf("\n3. Peek");
        printf("\n4. Display");
        printf("\n5. Exit");
        printf("\nEnter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter value to insert: ");
                scanf("%d", &val);
                enqueue(val);
                break;
            case 2:
                dequeue();
                break;
            case 3:
                peek();
                break;
            case 4:
                display();
                break;
            case 5:
                exit(0);
            default:
                printf("Invalid choice! Please try again.");
        }
    }
    return 0;
}