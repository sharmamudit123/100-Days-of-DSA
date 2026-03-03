#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* next;
};

struct Node* createNode(int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}

void append(struct Node** head, int data) {
    struct Node* newNode = createNode(data);
    if (*head == NULL) {
        *head = newNode;
        return;
    }
    struct Node* temp = *head;
    while (temp->next != NULL)
        temp = temp->next;
    temp->next = newNode;
}

struct Node* rotateRight(struct Node* head, int k, int n) {
    if (!head || k == 0 || k % n == 0)
        return head;

    k = k % n;

    struct Node* tail = head;
    while (tail->next != NULL)
        tail = tail->next;
    tail->next = head;

    int stepsToNewTail = n - k;
    struct Node* newTail = head;
    for (int i = 1; i < stepsToNewTail; i++)
        newTail = newTail->next;

    struct Node* newHead = newTail->next;
    newTail->next = NULL;

    return newHead;
}

void printList(struct Node* head) {
    while (head != NULL) {
        printf("%d", head->data);
        if (head->next != NULL)
            printf(" ");
        head = head->next;
    }
    printf("\n");
}

void freeList(struct Node* head) {
    struct Node* temp;
    while (head != NULL) {
        temp = head;
        head = head->next;
        free(temp);
    }
}

int main() {
    int n, k;
    struct Node* head = NULL;

    scanf("%d", &n);

    for (int i = 0; i < n; i++) {
        int val;
        scanf("%d", &val);
        append(&head, val);
    }

    scanf("%d", &k);

    head = rotateRight(head, k, n);
    printList(head);
    freeList(head);

    return 0;
}