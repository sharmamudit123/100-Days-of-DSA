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

int height(TreeNode* root) {
    if (!root)              return -1;  
    if (!root->left && !root->right) return 0;

    int leftH  = height(root->left);
    int rightH = height(root->right);

    return 1 + (leftH > rightH ? leftH : rightH);
}
void freeTree(TreeNode* root) {
    if (!root) return;
    freeTree(root->left);
    freeTree(root->right);
    free(root);
}
int main() {
    TreeNode* root1 = newNode(1);
    root1->left          = newNode(2);
    root1->right         = newNode(3);
    root1->left->left    = newNode(4);
    root1->left->right   = newNode(5);
    printf("Tree 1 height : %d\n", height(root1));   
    TreeNode* root2        = newNode(1);
    root2->right           = newNode(2);
    root2->right->right    = newNode(3);
    root2->right->right->right = newNode(4);
    printf("Tree 2 height : %d\n", height(root2));   
    TreeNode* root3 = newNode(42);
    printf("Tree 3 height : %d\n", height(root3));
    printf("Tree 4 height : %d\n", height(NULL));    
    freeTree(root1);
    freeTree(root2);
    freeTree(root3);
    return 0;
}