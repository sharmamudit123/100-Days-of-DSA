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

int countOccurrences(Node* head, int key) {
    int count = 0;
    Node* temp = head;

    while (temp != NULL) {
        if (temp->data == key)
            count++;
        temp = temp->next;
    }

    return count;
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
            printf(" → ");
        temp = temp->next;
    }
    printf(" → NULL\n");
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

    printf("Enter key to count: ");
    scanf("%d", &key);

    printf("\nLinked List : ");
    traverseList(head);

    int result = countOccurrences(head, key);

    printf("Key         : %d\n", key);
    printf("Occurrences : %d\n", result);

    freeList(head);
    return 0;
}