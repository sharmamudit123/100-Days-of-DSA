#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX 1000

// Priority Queue structure (min-heap using array)
typedef struct {
    int data[MAX];
    int size;
} PriorityQueue;

// Initialize the priority queue
void init(PriorityQueue* pq) {
    pq->size = 0;
}

// Swap two integers
void swap(int* a, int* b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

// Heapify up (after insertion)
void heapifyUp(PriorityQueue* pq, int index) {
    while (index > 0) {
        int parent = (index - 1) / 2;
        if (pq->data[parent] > pq->data[index]) {
            swap(&pq->data[parent], &pq->data[index]);
            index = parent;
        } else {
            break;
        }
    }
}

// Heapify down (after deletion)
void heapifyDown(PriorityQueue* pq, int index) {
    while (1) {
        int left     = 2 * index + 1;
        int right    = 2 * index + 2;
        int smallest = index;

        if (left < pq->size && pq->data[left] < pq->data[smallest])
            smallest = left;

        if (right < pq->size && pq->data[right] < pq->data[smallest])
            smallest = right;

        if (smallest != index) {
            swap(&pq->data[index], &pq->data[smallest]);
            index = smallest;
        } else {
            break;
        }
    }
}

// Insert element
void insert(PriorityQueue* pq, int value) {
    if (pq->size >= MAX) {
        printf("Queue is full\n");
        return;
    }
    pq->data[pq->size] = value;
    heapifyUp(pq, pq->size);
    pq->size++;
}

// Delete element with highest priority (smallest value)
void delete(PriorityQueue* pq) {
    if (pq->size == 0) {
        printf("-1\n");
        return;
    }
    printf("%d\n", pq->data[0]);

    // Replace root with last element and heapify down
    pq->data[0] = pq->data[pq->size - 1];
    pq->size--;
    if (pq->size > 0)
        heapifyDown(pq, 0);
}

// Peek at highest priority element (smallest value)
void peek(PriorityQueue* pq) {
    if (pq->size == 0) {
        printf("-1\n");
        return;
    }
    printf("%d\n", pq->data[0]);
}

int main() {
    PriorityQueue pq;
    init(&pq);

    int n;
    scanf("%d", &n);

    // Consume leftover newline
    getchar();

    for (int i = 0; i < n; i++) {
        char line[50];
        fgets(line, sizeof(line), stdin);

        line[strcspn(line, "\n")] = '\0';

        if (strncmp(line, "insert", 6) == 0) {
            int val;
            sscanf(line + 7, "%d", &val);
            insert(&pq, val);
        } else if (strcmp(line, "delete") == 0) {
            delete(&pq);
        } else if (strcmp(line, "peek") == 0) {
            peek(&pq);
        } else {
            printf("Unknown operation: %s\n", line);
        }
    }

    return 0;
}