#include <stdio.h>
#include <stdlib.h>

struct Node {
    int coeff;
    int exp;
    struct Node* next;
};

struct Node* createNode(int coeff, int exp) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->coeff = coeff;
    newNode->exp = exp;
    newNode->next = NULL;
    return newNode;
}

void append(struct Node** head, int coeff, int exp) {
    struct Node* newNode = createNode(coeff, exp);
    if (*head == NULL) {
        *head = newNode;
        return;
    }
    struct Node* temp = *head;
    while (temp->next != NULL)
        temp = temp->next;
    temp->next = newNode;
}

void printPolynomial(struct Node* head) {
    struct Node* temp = head;
    int isFirst = 1;

    while (temp != NULL) {
        int c = temp->coeff;
        int e = temp->exp;

        if (c == 0) {
            temp = temp->next;
            continue;
        }

        if (!isFirst) {
            if (c < 0)
                printf(" - ");
            else
                printf(" + ");
        } else {
            if (c < 0)
                printf("-");
        }

        int absC = c < 0 ? -c : c;

        if (e == 0) {
            printf("%d", absC);
        } else if (e == 1) {
            printf("%dx", absC);
        } else {
            printf("%dx^%d", absC, e);
        }

        isFirst = 0;
        temp = temp->next;
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
    int n;
    struct Node* head = NULL;

    scanf("%d", &n);

    for (int i = 0; i < n; i++) {
        int coeff, exp;
        scanf("%d %d", &coeff, &exp);
        append(&head, coeff, exp);
    }

    printPolynomial(head);
    freeList(head);

    return 0;
}