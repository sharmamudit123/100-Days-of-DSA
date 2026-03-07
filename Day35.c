#include <stdio.h>
#include <stdlib.h>
typedef struct Node {
    int data;
    struct Node *next;
} Node;

typedef struct {
    Node *front;
    Node *rear;
    int size;
} Queue;

Queue* createQueue() {
    Queue *q = (Queue*)malloc(sizeof(Queue));
    q->front = NULL;
    q->rear  = NULL;
    q->size  = 0;
    return q;
}

void enqueue(Queue *q, int value) {
    Node *newNode = (Node*)malloc(sizeof(Node));
    if (!newNode) {
        printf("Memory allocation failed\n");
        exit(1);
    }
    newNode->data = value;
    newNode->next = NULL;

    if (q->rear == NULL) {
        q->front = newNode;
        q->rear  = newNode;
    } else {
        q->rear->next = newNode;
        q->rear       = newNode;
    }
    q->size++;
}

int dequeue(Queue *q) {
    if (q->front == NULL) {
        printf("Queue Underflow\n");
        exit(1);
    }
    Node *temp  = q->front;
    int value   = temp->data;
    q->front    = q->front->next;

    if (q->front == NULL) {
        q->rear = NULL;   
    }

    free(temp);
    q->size--;
    return value;
}

void display(Queue *q) {
    if (q->front == NULL) {
        printf("Queue is Empty\n");
        return;
    }
    Node *curr = q->front;
    while (curr != NULL) {
        if (curr->next == NULL)
            printf("%d\n", curr->data);     
        else
            printf("%d ", curr->data);
        curr = curr->next;
    }
}

void freeQueue(Queue *q) {
    while (q->front != NULL) {
        Node *temp = q->front;
        q->front   = q->front->next;
        free(temp);
    }
    free(q);
}

int main() {
    int n;
    scanf("%d", &n);

    Queue *q = createQueue();

    for (int i = 0; i < n; i++) {
        int val;
        scanf("%d", &val);
        enqueue(q, val);
    }

    display(q);
    freeQueue(q);
    return 0;
}