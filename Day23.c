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

Node* mergeSortedLists(Node* l1, Node* l2) {
    Node dummy;
    dummy.next = NULL;
    Node* tail = &dummy;

    while (l1 != NULL && l2 != NULL) {
        if (l1->data <= l2->data) {
            tail->next = l1;       
            l1 = l1->next;
        } else {
            tail->next = l2;       
            l2 = l2->next;
        }
        tail = tail->next;         
    }

    if (l1 != NULL) tail->next = l1;
    if (l2 != NULL) tail->next = l2;

    return dummy.next;             
}

void traverseList(Node* head) {
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
    int n, m;
    Node* list1 = NULL;
    Node* list2 = NULL;

    printf("Enter number of elements in list 1: ");
    scanf("%d", &n);
    printf("Enter %d elements (sorted): ", n);
    for (int i = 0; i < n; i++) {
        int val;
        scanf("%d", &val);
        list1 = insertAtEnd(list1, val);
    }

    printf("Enter number of elements in list 2: ");
    scanf("%d", &m);
    printf("Enter %d elements (sorted): ", m);
    for (int i = 0; i < m; i++) {
        int val;
        scanf("%d", &val);
        list2 = insertAtEnd(list2, val);
    }

    printf("\nList 1        : ");
    traverseList(list1);
    printf("List 2        : ");
    traverseList(list2);

    Node* merged = mergeSortedLists(list1, list2);
    printf("Merged List   : ");
    traverseList(merged);

    freeList(merged);
    return 0;
}