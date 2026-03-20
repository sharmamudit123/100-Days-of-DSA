#include <stdio.h>
#include <stdlib.h>

// Node structure for linked list
typedef struct Node {
    int data;
    struct Node* next;
} Node;

// Circular Queue structure
typedef struct {
    Node* front;
    Node* rear;
    int size;
} CircularQueue;

// Initialize the queue
void initQueue(CircularQueue* q) {
    q->front = NULL;
    q->rear = NULL;
    q->size = 0;
}

// Enqueue operation
void enqueue(CircularQueue* q, int value) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    if (!newNode) {
        printf("Memory allocation failed\n");
        return;
    }
    newNode->data = value;
    newNode->next = NULL;

    if (q->rear == NULL) {
        // Queue is empty
        q->front = newNode;
        q->rear = newNode;
        newNode->next = newNode; // Circular link
    } else {
        q->rear->next = newNode;
        q->rear = newNode;
        q->rear->next = q->front; // Maintain circular link
    }
    q->size++;
}

// Dequeue operation
int dequeue(CircularQueue* q) {
    if (q->front == NULL) {
        printf("Queue is empty\n");
        return -1;
    }

    int value = q->front->data;
    Node* temp = q->front;

    if (q->front == q->rear) {
        // Only one element
        q->front = NULL;
        q->rear = NULL;
    } else {
        q->front = q->front->next;
        q->rear->next = q->front; // Maintain circular link
    }

    free(temp);
    q->size--;
    return value;
}

// Display queue from front to rear
void displayQueue(CircularQueue* q) {
    if (q->front == NULL) {
        printf("Queue is empty\n");
        return;
    }

    Node* current = q->front;
    for (int i = 0; i < q->size; i++) {
        if (i == q->size - 1)
            printf("%d", current->data);    // No trailing space
        else
            printf("%d ", current->data);
        current = current->next;
    }
    printf("\n");
}

// Free all memory
void freeQueue(CircularQueue* q) {
    if (q->front == NULL) return;

    // Break circular link first
    q->rear->next = NULL;

    Node* current = q->front;
    while (current != NULL) {
        Node* temp = current;
        current = current->next;
        free(temp);
    }
    q->front = NULL;
    q->rear = NULL;
}

int main() {
    CircularQueue q;
    initQueue(&q);

    int n;
    scanf("%d", &n);

    // Enqueue n elements
    for (int i = 0; i < n; i++) {
        int val;
        scanf("%d", &val);
        enqueue(&q, val);
    }

    int m;
    scanf("%d", &m);

    // Dequeue m elements
    for (int i = 0; i < m; i++) {
        dequeue(&q);
    }

    // Display remaining elements
    displayQueue(&q);

    // Free memory
    freeQueue(&q);

    return 0;
}