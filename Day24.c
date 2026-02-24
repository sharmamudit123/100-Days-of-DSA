#include <stdio.h>
#include <stdlib.h>
typedef struct Node {
    int data;
    struct Node* next;
} Node;

Node* createNode(int data) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}

Node* insertAtEnd(Node* head, int data) {
    Node* newNode = createNode(data);
    if (head == NULL)
        return newNode;

    Node* temp = head;
    while (temp->next != NULL)
        temp = temp->next;

    temp->next = newNode;
    return head;
}

Node* deleteFirstOccurrence(Node* head, int key) {
    if (head == NULL) {
        printf("List is empty!\n");
        return NULL;
    }

    if (head->data == key) {
        Node* toDelete = head;
        head = head->next;
        free(toDelete);
        printf("Deleted %d from head.\n", key);
        return head;
    }
    Node* prev = head;
    Node* curr = head->next;

    while (curr != NULL) {
        if (curr->data == key) {
            prev->next = curr->next;   
            free(curr);                
            printf("Deleted %d from list.\n", key);
            return head;
        }
        prev = curr;
        curr = curr->next;
    }

    printf("Key %d not found in list!\n", key);
    return head;
}

void traverseList(Node* head) {
    if (head == NULL) {
        printf("List is empty!\n");
        return;
    }
    Node* temp = head;
    while (temp != NULL) {
        printf("%d", temp->data);
        if (temp->next != NULL)
            printf(" ");
        temp = temp->next;
    }
    printf("\n");
}

void freeList(Node* head) {
    Node* temp;
    while (head != NULL) {
        temp = head;
        head = head->next;
        free(temp);
    }
}

int main() {
    int n, key;
    Node* head = NULL;

    printf("Enter number of elements: ");
    scanf("%d", &n);

    printf("Enter %d elements: ", n);
    for (int i = 0; i < n; i++) {
        int val;
        scanf("%d", &val);
        head = insertAtEnd(head, val);
    }

    printf("Enter key to delete: ");
    scanf("%d", &key);

    printf("\nOriginal List : ");
    traverseList(head);

    head = deleteFirstOccurrence(head, key);

    printf("Updated List  : ");
    traverseList(head);

    freeList(head);
    return 0;
}