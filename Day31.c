#include <stdio.h>
#include <stdlib.h>

#define MAX 1000

int stack[MAX];
int top = -1;

void push(int value) {
    if (top >= MAX - 1) {
        printf("Stack Overflow\n");
        return;
    }
    stack[++top] = value;
}

void pop() {
    if (top < 0) {
        printf("Stack Underflow\n");
        return;
    }
    printf("%d\n", stack[top--]);
}

void display() {
    if (top < 0) {
        printf("Stack is Empty\n");
        return;
    }
    for (int i = top; i >= 0; i--) {
        if (i == 0)
            printf("%d\n", stack[i]);
        else
            printf("%d ", stack[i]);
    }
}

int main() {
    int n;
    scanf("%d", &n);

    for (int i = 0; i < n; i++) {
        int op;
        scanf("%d", &op);

        if (op == 1) {
            int value;
            scanf("%d", &value);
            push(value);
        } else if (op == 2) {
            pop();
        } else if (op == 3) {
            display();
        }
    }

    return 0;
}