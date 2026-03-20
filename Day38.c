#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// ─────────────────────────────────────────────
//  Node & Deque structures  (doubly linked list)
// ─────────────────────────────────────────────
typedef struct Node {
    int data;
    struct Node* prev;
    struct Node* next;
} Node;

typedef struct {
    Node* front;
    Node* back;
    int   size;
} Deque;

// ─────────────────────────────────────────────
//  Helpers
// ─────────────────────────────────────────────
Node* newNode(int val) {
    Node* n = (Node*)malloc(sizeof(Node));
    if (!n) { fprintf(stderr, "malloc failed\n"); exit(1); }
    n->data = val;
    n->prev = n->next = NULL;
    return n;
}

void initDeque(Deque* dq) {
    dq->front = dq->back = NULL;
    dq->size = 0;
}

int isEmpty(Deque* dq) { return dq->size == 0; }

// ─────────────────────────────────────────────
//  Core O(1) operations
// ─────────────────────────────────────────────
void push_front(Deque* dq, int val) {
    Node* n = newNode(val);
    if (isEmpty(dq)) {
        dq->front = dq->back = n;
    } else {
        n->next        = dq->front;
        dq->front->prev = n;
        dq->front      = n;
    }
    dq->size++;
}

void push_back(Deque* dq, int val) {
    Node* n = newNode(val);
    if (isEmpty(dq)) {
        dq->front = dq->back = n;
    } else {
        n->prev        = dq->back;
        dq->back->next = n;
        dq->back       = n;
    }
    dq->size++;
}

void pop_front(Deque* dq) {
    if (isEmpty(dq)) { printf("Deque is empty\n"); return; }
    Node* temp = dq->front;
    dq->front  = dq->front->next;
    if (dq->front) dq->front->prev = NULL;
    else           dq->back = NULL;
    free(temp);
    dq->size--;
}

void pop_back(Deque* dq) {
    if (isEmpty(dq)) { printf("Deque is empty\n"); return; }
    Node* temp = dq->back;
    dq->back   = dq->back->prev;
    if (dq->back) dq->back->next = NULL;
    else          dq->front = NULL;
    free(temp);
    dq->size--;
}

void front(Deque* dq) {
    if (isEmpty(dq)) { printf("-1\n"); return; }
    printf("%d\n", dq->front->data);
}

void back(Deque* dq) {
    if (isEmpty(dq)) { printf("-1\n"); return; }
    printf("%d\n", dq->back->data);
}

void size_op(Deque* dq) { printf("%d\n", dq->size); }

void empty_op(Deque* dq) { printf(isEmpty(dq) ? "true\n" : "false\n"); }

// ─────────────────────────────────────────────
//  Additional operations
// ─────────────────────────────────────────────

// clear — remove all elements
void clear(Deque* dq) {
    while (!isEmpty(dq)) pop_front(dq);
}

// erase at 0-based index
void erase(Deque* dq, int idx) {
    if (idx < 0 || idx >= dq->size) { printf("Index out of range\n"); return; }
    Node* cur = dq->front;
    for (int i = 0; i < idx; i++) cur = cur->next;
    if (cur->prev) cur->prev->next = cur->next;
    else           dq->front       = cur->next;
    if (cur->next) cur->next->prev = cur->prev;
    else           dq->back        = cur->prev;
    free(cur);
    dq->size--;
}

// swap contents of two deques
void swap_deques(Deque* a, Deque* b) {
    Deque tmp = *a;
    *a = *b;
    *b = tmp;
}

// emplace_front / emplace_back (same as push for int)
void emplace_front(Deque* dq, int val) { push_front(dq, val); }
void emplace_back (Deque* dq, int val) { push_back (dq, val); }

// resize: grow with 0s or shrink from back
void resize_deque(Deque* dq, int newSize) {
    while (dq->size > newSize) pop_back(dq);
    while (dq->size < newSize) push_back(dq, 0);
}

// assign: replace all elements with `count` copies of `val`
void assign(Deque* dq, int count, int val) {
    clear(dq);
    for (int i = 0; i < count; i++) push_back(dq, val);
}

// reverse in-place by swapping data values
void reverse_deque(Deque* dq) {
    Node* lo = dq->front;
    Node* hi = dq->back;
    int   half = dq->size / 2;
    for (int i = 0; i < half; i++) {
        int tmp  = lo->data;
        lo->data = hi->data;
        hi->data = tmp;
        lo = lo->next;
        hi = hi->prev;
    }
}

// sort ascending (bubble sort on node data)
void sort_deque(Deque* dq) {
    if (dq->size < 2) return;
    for (int i = 0; i < dq->size - 1; i++) {
        Node* cur = dq->front;
        for (int j = 0; j < dq->size - 1 - i; j++) {
            if (cur->data > cur->next->data) {
                int tmp        = cur->data;
                cur->data      = cur->next->data;
                cur->next->data = tmp;
            }
            cur = cur->next;
        }
    }
}

// ─────────────────────────────────────────────
//  Display
// ─────────────────────────────────────────────
void display(Deque* dq) {
    if (isEmpty(dq)) { printf("Deque is empty\n"); return; }
    printf("Deque (front→back): ");
    Node* cur = dq->front;
    while (cur) {
        printf("%d", cur->data);
        if (cur->next) printf(" ");
        cur = cur->next;
    }
    printf("\n");
}

// ─────────────────────────────────────────────
//  Main – menu-driven driver
// ─────────────────────────────────────────────
int main() {
    Deque dq, dq2;
    initDeque(&dq);
    initDeque(&dq2);

    printf("========================================\n");
    printf("       DEQUE - All Operations Demo\n");
    printf("========================================\n\n");

    // ── Basic insertions ──
    printf("--- push_back: 10 20 30 ---\n");
    push_back(&dq, 10);
    push_back(&dq, 20);
    push_back(&dq, 30);
    display(&dq);

    printf("\n--- push_front: 5 ---\n");
    push_front(&dq, 5);
    display(&dq);

    printf("\n--- front() and back() ---\n");
    printf("front = "); front(&dq);
    printf("back  = "); back(&dq);

    printf("\n--- size() and empty() ---\n");
    printf("size  = "); size_op(&dq);
    printf("empty = "); empty_op(&dq);

    // ── Deletions ──
    printf("\n--- pop_front() ---\n");
    pop_front(&dq);
    display(&dq);

    printf("\n--- pop_back() ---\n");
    pop_back(&dq);
    display(&dq);

    // ── emplace ──
    printf("\n--- emplace_front(1), emplace_back(99) ---\n");
    emplace_front(&dq, 1);
    emplace_back (&dq, 99);
    display(&dq);

    // ── erase ──
    printf("\n--- erase(index 1) ---\n");
    erase(&dq, 1);
    display(&dq);

    // ── resize ──
    printf("\n--- resize(5) ---\n");
    resize_deque(&dq, 5);
    display(&dq);

    // ── assign ──
    printf("\n--- assign(4 copies of 7) ---\n");
    assign(&dq, 4, 7);
    display(&dq);

    // ── push varied data then sort ──
    printf("\n--- push_back: 3 1 4 1 5 9 2 6, then sort ---\n");
    clear(&dq);
    int vals[] = {3, 1, 4, 1, 5, 9, 2, 6};
    for (int i = 0; i < 8; i++) push_back(&dq, vals[i]);
    display(&dq);
    sort_deque(&dq);
    printf("After sort: ");
    display(&dq);

    // ── reverse ──
    printf("\n--- reverse ---\n");
    reverse_deque(&dq);
    display(&dq);

    // ── swap ──
    printf("\n--- swap with dq2 (dq2 has 100 200) ---\n");
    push_back(&dq2, 100);
    push_back(&dq2, 200);
    printf("dq  before swap: "); display(&dq);
    printf("dq2 before swap: "); display(&dq2);
    swap_deques(&dq, &dq2);
    printf("dq  after  swap: "); display(&dq);
    printf("dq2 after  swap: "); display(&dq2);

    // ── clear ──
    printf("\n--- clear dq ---\n");
    clear(&dq);
    printf("empty = "); empty_op(&dq);
    printf("size  = "); size_op(&dq);

    printf("\n--- pop_front on empty deque ---\n");
    pop_front(&dq);

    clear(&dq2);
    printf("\nAll operations completed successfully.\n");
    return 0;
}