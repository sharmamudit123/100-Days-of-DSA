#include <stdio.h>
#include <stdlib.h>
struct Node {
    int data;
    struct Node* next;
};

struct Node* createNode(int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    if (!newNode) {
        printf("Memory allocation failed\n");
        exit(1);
    }
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}

struct Node* insertAtTail(struct Node* head, int data) {
    struct Node* newNode = createNode(data);

    if (head == NULL) {
        newNode->next = newNode; 
        return newNode;
    }

    struct Node* tail = head;
    while (tail->next != head)
        tail = tail->next;

    tail->next = newNode;
    newNode->next = head;   
    return head;
}

void traverseCircular(struct Node* head) {
    if (head == NULL) {
        printf("List is empty\n");
        return;
    }

    struct Node* curr = head;

    do {
        if (curr->next == head)
            printf("%d", curr->data);       
        else
            printf("%d ", curr->data);
        curr = curr->next;
    } while (curr != head);            

    printf("\n");
}

void freeList(struct Node* head) {
    if (head == NULL) return;

    struct Node* curr = head->next;
    while (curr != head) {
        struct Node* temp = curr;
        curr = curr->next;
        free(temp);
    }
    free(head);  
}

void displayCircular(struct Node* head) {
    if (head == NULL) return;

    struct Node* curr = head;
    do {
        printf("%d -> ", curr->data);
        curr = curr->next;
    } while (curr != head);
    printf("(back to head: %d)\n", head->data);
}

int main() {
    int n;
    struct Node* head = NULL;

    printf("Enter number of elements: ");
    scanf("%d", &n);

    printf("Enter %d elements: ", n);
    for (int i = 0; i < n; i++) {
        int val;
        scanf("%d", &val);
        head = insertAtTail(head, val);
    }

    printf("\nOutput: ");
    traverseCircular(head);

    printf("\nCircular Structure: ");
    displayCircular(head);

    freeList(head);

    return 0;
}