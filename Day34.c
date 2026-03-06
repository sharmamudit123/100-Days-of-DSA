#include <stdio.h>
#include <stdlib.h>
#include <string.h>
typedef struct Node {
    int data;
    struct Node *next;
} Node;

Node *top = NULL;

void push(int value) {
    Node *newNode = (Node*)malloc(sizeof(Node));
    if (!newNode) {
        printf("Memory allocation failed\n");
        exit(1);
    }
    newNode->data = value;
    newNode->next = top;
    top = newNode;
}

int pop() {
    if (top == NULL) {
        printf("Stack Underflow\n");
        exit(1);
    }
    Node *temp = top;
    int value = temp->data;
    top = top->next;
    free(temp);           
    return value;
}

int peek() {
    if (top == NULL) {
        printf("Stack is Empty\n");
        exit(1);
    }
    return top->data;
}

int isEmpty() {
    return top == NULL;
}

int isOperator(char *token) {
    return (strcmp(token, "+") == 0 || strcmp(token, "-") == 0 ||
            strcmp(token, "*") == 0 || strcmp(token, "/") == 0);
}

int evaluate(char *token, int a, int b) {
    if (strcmp(token, "+") == 0) return a + b;
    if (strcmp(token, "-") == 0) return a - b;
    if (strcmp(token, "*") == 0) return a * b;
    if (strcmp(token, "/") == 0) return a / b;
    return 0;
}

int main() {
    char line[1000];

    fgets(line, sizeof(line), stdin);

    char *token = strtok(line, " \n");

    while (token != NULL) {
        if (isOperator(token)) {
            int b = pop();   
            int a = pop();   
            int result = evaluate(token, a, b);
            push(result);
        } else {
            push(atoi(token));
        }
        token = strtok(NULL, " \n");
    }

    printf("%d\n", pop());  
    return 0;
}