#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX 1000

// ─────────────────────────────────────────────
//  Min Heap Structure
// ─────────────────────────────────────────────
typedef struct {
    int data[MAX];
    int size;
} MinHeap;

// ─────────────────────────────────────────────
//  Initialize Heap
// ─────────────────────────────────────────────
void init(MinHeap* h) {
    h->size = 0;
}

// ─────────────────────────────────────────────
//  Swap Helper
// ─────────────────────────────────────────────
void swap(int* a, int* b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

// ─────────────────────────────────────────────
//  Heapify Up — after insert
// ─────────────────────────────────────────────
//
//  New element added at last index.
//  Compare with parent and bubble up
//  until heap property is restored.
//
//  Index relations:
//    parent(i) = (i - 1) / 2
//
void heapifyUp(MinHeap* h, int i) {
    while (i > 0) {
        int parent = (i - 1) / 2;
        if (h->data[parent] > h->data[i]) {
            swap(&h->data[parent], &h->data[i]);
            i = parent;
        } else {
            break;
        }
    }
}

// ─────────────────────────────────────────────
//  Heapify Down — after extractMin
// ─────────────────────────────────────────────
//
//  Root removed, last element placed at root.
//  Compare with children and push down
//  until heap property is restored.
//
//  Index relations:
//    left(i)  = 2*i + 1
//    right(i) = 2*i + 2
//
void heapifyDown(MinHeap* h, int i) {
    while (1) {
        int left     = 2 * i + 1;
        int right    = 2 * i + 2;
        int smallest = i;

        if (left  < h->size && h->data[left]  < h->data[smallest])
            smallest = left;

        if (right < h->size && h->data[right] < h->data[smallest])
            smallest = right;

        if (smallest != i) {
            swap(&h->data[i], &h->data[smallest]);
            i = smallest;
        } else {
            break;
        }
    }
}

// ─────────────────────────────────────────────
//  Insert
// ─────────────────────────────────────────────
void insert(MinHeap* h, int val) {
    if (h->size >= MAX) {
        printf("Heap is full\n");
        return;
    }
    h->data[h->size] = val;   // Place at end
    heapifyUp(h, h->size);    // Restore heap
    h->size++;
}

// ─────────────────────────────────────────────
//  Extract Min
// ─────────────────────────────────────────────
void extractMin(MinHeap* h) {
    if (h->size == 0) {
        printf("-1\n");
        return;
    }
    printf("%d\n", h->data[0]);            // Print root (min)
    h->data[0] = h->data[h->size - 1];    // Move last to root
    h->size--;
    if (h->size > 0)
        heapifyDown(h, 0);                 // Restore heap
}

// ─────────────────────────────────────────────
//  Peek — view min without removing
// ─────────────────────────────────────────────
void peek(MinHeap* h) {
    if (h->size == 0) {
        printf("-1\n");
        return;
    }
    printf("%d\n", h->data[0]);
}

// ─────────────────────────────────────────────
//  Display heap array (for debugging)
// ─────────────────────────────────────────────
void display(MinHeap* h) {
    if (h->size == 0) {
        printf("Heap is empty\n");
        return;
    }
    printf("Heap: ");
    for (int i = 0; i < h->size; i++) {
        printf("%d", h->data[i]);
        if (i < h->size - 1) printf(" ");
    }
    printf("\n");
}

// ─────────────────────────────────────────────
//  Main
// ─────────────────────────────────────────────
int main() {
    MinHeap h;
    init(&h);

    int n;
    scanf("%d", &n);
    getchar(); // consume leftover newline

    for (int i = 0; i < n; i++) {
        char line[50];
        fgets(line, sizeof(line), stdin);
        line[strcspn(line, "\n")] = '\0'; // strip newline

        if (strncmp(line, "insert", 6) == 0) {
            int val;
            sscanf(line + 7, "%d", &val);
            insert(&h, val);

        } else if (strcmp(line, "extractMin") == 0) {
            extractMin(&h);

        } else if (strcmp(line, "peek") == 0) {
            peek(&h);

        } else {
            printf("Unknown operation: %s\n", line);
        }
    }

    return 0;
}