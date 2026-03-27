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
    if (val < root->val) root->left  = insert(root->left,  val);
    else if (val > root->val) root->right = insert(root->right, val);
    return root;
}

TreeNode* search(TreeNode* root, int val) {
    if (!root)             return NULL;   
    if (root->val == val)  return root;   

    if (val < root->val)
        return search(root->left,  val);  
    else
        return search(root->right, val);  
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

void printResult(TreeNode* result, int val) {
    if (result) {
        printf("  Search %2d → FOUND   | Subtree inorder: ", val);
        inorder(result);
        printf("\n");
    } else {
        printf("  Search %2d → NOT FOUND\n", val);
    }
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

    printf("Test 1 — BST: ");
    inorder(root1);
    printf("\n");
    printf("  Tree structure (rotated 90 clockwise):\n");
    printTree(root1, 0);
    printf("\n");

    printResult(search(root1, 2),  2);   
    printResult(search(root1, 5),  5);   
    printResult(search(root1, 1),  1);   
    printResult(search(root1, 4),  4);
    printResult(search(root1, 7),  7);   
    printf("\n");

    printf("Test 2 — build BST: 40 20 60 10 30 50 70 25\n");
    int values[] = {40, 20, 60, 10, 30, 50, 70, 25};
    int n = sizeof(values) / sizeof(values[0]);

    TreeNode* root2 = NULL;
    for (int i = 0; i < n; i++)
        root2 = insert(root2, values[i]);

    printf("  Inorder: ");
    inorder(root2);
    printf("\n");
    printf("  Tree structure (rotated 90 clockwise):\n");
    printTree(root2, 0);
    printf("\n");

    printResult(search(root2, 25),  25);  
    printResult(search(root2, 60),  60);  
    printResult(search(root2, 35),  35);  
    printResult(search(root2, 10),  10);  
    printResult(search(root2, 99),  99);  
    printf("\n");

    printf("Test 3 — single node BST (42):\n");
    TreeNode* root3 = newNode(42);
    printResult(search(root3, 42),  42);  
    printResult(search(root3,  1),   1);  
    printf("\n");

    printf("Test 4 — empty BST:\n");
    printResult(search(NULL, 10), 10);    
    printf("\n");

    freeTree(root1);
    freeTree(root2);
    freeTree(root3);

    return 0;
}