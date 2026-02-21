#include <stdio.h>
#include <stdlib.h>
typedef struct Node {
    int key;        
    int count;      
    struct Node* next;
} Node;

#define TABLE_SIZE 10007

Node* hashTable[TABLE_SIZE];

int hash(int key) {
    int h = key % TABLE_SIZE;
    if (h < 0) h += TABLE_SIZE;
    return h;
}

void insertOrUpdate(int key) {
    int h = hash(key);
    Node* curr = hashTable[h];
    while (curr) {
        if (curr->key == key) {
            curr->count++;
            return;
        }
        curr = curr->next;
    }
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->key   = key;
    newNode->count = 1;
    newNode->next  = hashTable[h];
    hashTable[h]   = newNode;
}

int getCount(int key) {
    int h = hash(key);
    Node* curr = hashTable[h];
    while (curr) {
        if (curr->key == key)
            return curr->count;
        curr = curr->next;
    }
    return 0;
}

void freeTable() {
    for (int i = 0; i < TABLE_SIZE; i++) {
        Node* curr = hashTable[i];
        while (curr) {
            Node* temp = curr;
            curr = curr->next;
            free(temp);
        }
        hashTable[i] = NULL;
    }
}

int main() {
    int n;
    printf("Enter number of elements: ");
    scanf("%d", &n);

    int arr[n];
    printf("Enter %d elements: ", n);
    for (int i = 0; i < n; i++)
        scanf("%d", &arr[i]);

    long long count = 0;
    int prefixSum = 0;

    insertOrUpdate(0);

    for (int i = 0; i < n; i++) {
        prefixSum += arr[i];

        count += getCount(prefixSum);

        insertOrUpdate(prefixSum);
    }

    printf("\nCount of subarrays with sum zero: %lld\n", count);

    freeTable();
    return 0;
}