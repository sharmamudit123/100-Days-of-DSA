#include <stdio.h>
#include <stdlib.h>
typedef struct Node {
    int data;
    struct Node* next;
    struct Node* prev;
} Node;

Node* createNode(int data) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    if (!newNode) {
        printf("Memory allocation failed\n");
        exit(1);
    }
    newNode->data = data;
    newNode->next = NULL;
    newNode->prev = NULL;
    return newNode;
}

Node* insertAtTail(Node* head, int data) {
    Node* newNode = createNode(data);
    if (head == NULL) return newNode;

    Node* curr = head;
    while (curr->next != NULL)
        curr = curr->next;

    curr->next = newNode;
    newNode->prev = curr;
    return head;
}

void traverseForward(Node* head) {
    Node* curr = head;
    while (curr != NULL) {
        if (curr->next == NULL)
            printf("%d", curr->data);       
        else
            printf("%d ", curr->data);
        curr = curr->next;
    }
    printf("\n");
}

void freeList(Node* head) {
    Node* curr = head;
    while (curr != NULL) {
        Node* temp = curr;
        curr = curr->next;
        free(temp);
    }
}

int main() {
    int n;
    scanf("%d", &n);

    Node* head = NULL;
    for (int i = 0; i < n; i++) {
        int val;
        scanf("%d", &val);
        head = insertAtTail(head, val);
    }

    traverseForward(head);

    freeList(head);
    return 0;
}