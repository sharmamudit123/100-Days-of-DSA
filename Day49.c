#include <stdio.h>
#include <stdlib.h>
typedef struct TreeNode {
    int val;
    struct TreeNode* left;
    struct TreeNode* right;
} TreeNode;

TreeNode* newNode(int val) {
    TreeNode* node = (TreeNode*)malloc(sizeof(TreeNode));
    node->val      = val;
    node->left     = NULL;
    node->right    = NULL;
    return node;
}

TreeNode* insert(TreeNode* root, int val) {
    if (!root) return newNode(val);         

    if (val < root->val)
        root->left  = insert(root->left,  val);   
    else if (val > root->val)
        root->right = insert(root->right, val);   
    return root;
}

void inorder(TreeNode* root) {
    if (!root) return;
    inorder(root->left);
    printf("%d ", root->val);
    inorder(root->right);
}

void printTree(TreeNode* root, int space) {
    if (!root) return;
    space += 5;
    printTree(root->right, space);
    printf("\n%*d\n", space, root->val);
    printTree(root->left, space);
}

void freeTree(TreeNode* root) {
    if (!root) return;
    freeTree(root->left);
    freeTree(root->right);
    free(root);
}

int main() {

    TreeNode* root1 = newNode(4);
    root1->left          = newNode(2);
    root1->right         = newNode(7);
    root1->left->left    = newNode(1);
    root1->left->right   = newNode(3);

    printf("Test 1:\n");
    printf("  Before insert | Inorder: ");
    inorder(root1);
    printf("\n");

    root1 = insert(root1, 5);

    printf("  After  insert | Inorder: ");
    inorder(root1);
    printf("\n");
    printf("  Tree structure (rotated 90 clockwise):\n");
    printTree(root1, 0);
    printf("\n");
    printf("Test 2 — build BST by inserting: 40 20 60 10 30 50 70 25\n");
    int values[] = {40, 20, 60, 10, 30, 50, 70, 25};
    int n = sizeof(values) / sizeof(values[0]);

    TreeNode* root2 = NULL;
    for (int i = 0; i < n; i++) {
        root2 = insert(root2, values[i]);
        printf("  Inserted %2d | Inorder: ", values[i]);
        inorder(root2);
        printf("\n");
    }
    printf("  Final tree structure (rotated 90 clockwise):\n");
    printTree(root2, 0);
    printf("\n");
    printf("Test 3 — single node then insert 5 and 15:\n");
    TreeNode* root3 = newNode(10);
    root3 = insert(root3, 5);
    root3 = insert(root3, 15);
    printf("  Inorder: ");
    inorder(root3);
    printf("\n");
    printf("  Tree structure (rotated 90 clockwise):\n");
    printTree(root3, 0);
    printf("\n");
    printf("Test 4 — insert duplicate value 4 into tree that already has 4:\n");
    TreeNode* root4 = newNode(4);
    root4 = insert(root4, 2);
    root4 = insert(root4, 6);
    printf("  Before: ");
    inorder(root4);
    root4 = insert(root4, 4);   
    printf("\n  After inserting duplicate 4: ");
    inorder(root4);
    printf("\n");
    freeTree(root1);
    freeTree(root2);
    freeTree(root3);
    freeTree(root4);
    return 0;
}