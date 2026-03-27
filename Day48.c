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
int countLeaves(TreeNode* root) {
    if (!root)                           return 0;  
    if (!root->left && !root->right)     return 1;  

    return countLeaves(root->left) + countLeaves(root->right);
}
void freeTree(TreeNode* root) {
    if (!root) return;
    freeTree(root->left);
    freeTree(root->right);
    free(root);
}
int main() {
    TreeNode* root1 = newNode(1);
    root1->left             = newNode(2);
    root1->right            = newNode(3);
    root1->left->left       = newNode(4);
    root1->left->right      = newNode(5);
    printf("Tree 1 leaf count : %d\n", countLeaves(root1));  // 3
    TreeNode* root2 = newNode(1);
    root2->left              = newNode(2);
    root2->right             = newNode(3);
    root2->left->left        = newNode(4);
    root2->left->right       = newNode(5);
    root2->right->left       = newNode(6);
    root2->right->right      = newNode(7);
    printf("Tree 2 leaf count : %d\n", countLeaves(root2));  
    TreeNode* root3                    = newNode(1);
    root3->right                       = newNode(2);
    root3->right->right                = newNode(3);
    root3->right->right->right         = newNode(4);
    printf("Tree 3 leaf count : %d\n", countLeaves(root3));  
    TreeNode* root4 = newNode(42);
    printf("Tree 4 leaf count : %d\n", countLeaves(root4));  
    printf("Tree 5 leaf count : %d\n", countLeaves(NULL));   
    freeTree(root1);
    freeTree(root2);
    freeTree(root3);
    freeTree(root4);

    return 0;
}