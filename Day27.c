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
    if (head == NULL) return newNode;

    struct Node* curr = head;
    while (curr->next != NULL)
        curr = curr->next;
    curr->next = newNode;
    return head;
}

int getLength(struct Node* head) {
    int len = 0;
    while (head != NULL) {
        len++;
        head = head->next;
    }
    return len;
}

struct Node* findIntersection(struct Node* head1, struct Node* head2) {
    int len1 = getLength(head1);
    int len2 = getLength(head2);

    while (len1 > len2) {
        head1 = head1->next;
        len1--;
    }
    while (len2 > len1) {
        head2 = head2->next;
        len2--;
    }

    while (head1 != NULL && head2 != NULL) {
        if (head1 == head2)          
            return head1;
        head1 = head1->next;
        head2 = head2->next;
    }

    return NULL;  
}

void printList(struct Node* head) {
    while (head != NULL) {
        printf("%d", head->data);
        if (head->next != NULL) printf(" -> ");
        head = head->next;
    }
    printf("\n");
}

void freeList(struct Node* head) {
    while (head != NULL) {
        struct Node* temp = head;
        head = head->next;
        free(temp);
    }
}

int main() {
    int n, m;
    struct Node* head1 = NULL;
    struct Node* head2 = NULL;

    printf("Enter size of first list: ");
    scanf("%d", &n);
    printf("Enter %d elements: ", n);
    for (int i = 0; i < n; i++) {
        int val;
        scanf("%d", &val);
        head1 = insertAtTail(head1, val);
    }

    printf("Enter size of second list: ");
    scanf("%d", &m);
    printf("Enter %d elements: ", m);

    struct Node* temp2 = NULL;
    int val;

    int arr2[1000];
    for (int i = 0; i < m; i++)
        scanf("%d", &arr2[i]);

    struct Node* intersectNode = NULL;
    struct Node* curr1 = head1;

    for (int i = 0; i < m; i++) {
        curr1 = head1;
        while (curr1 != NULL) {
            if (curr1->data == arr2[i]) {
                struct Node* temp = curr1;
                int match = 1;
                for (int j = i; j < m; j++) {
                    if (temp == NULL || temp->data != arr2[j]) {
                        match = 0;
                        break;
                    }
                    temp = temp->next;
                }
                if (match) {
                    intersectNode = curr1;
                    break;
                }
            }
            curr1 = curr1->next;
        }
        if (intersectNode) break;
    }

    for (int i = 0; i < m; i++) {
        if (intersectNode && arr2[i] == intersectNode->data) {
            if (head2 == NULL)
                head2 = intersectNode;
            else {
                struct Node* tail = head2;
                while (tail->next != NULL) tail = tail->next;
                tail->next = intersectNode;
            }
            break;
        }
        head2 = insertAtTail(head2, arr2[i]);
    }

    printf("\nList 1: ");
    printList(head1);
    printf("List 2: ");
    printList(head2);

    struct Node* result = findIntersection(head1, head2);
    if (result != NULL)
        printf("\nIntersection Point: %d\n", result->data);
    else
        printf("\nNo Intersection\n");

    if (intersectNode != NULL) {
        struct Node* prev = head2;
        if (prev == intersectNode) {
            head2 = NULL;
        } else {
            while (prev != NULL && prev->next != intersectNode)
                prev = prev->next;
            if (prev) prev->next = NULL;
        }
    }

    freeList(head1);
    freeList(head2);

    return 0;
}