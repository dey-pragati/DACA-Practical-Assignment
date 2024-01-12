//  7. Convert a binary tree into a mirror tree (invert binary tree).
#include <stdio.h>
#include <stdlib.h>

// Define a binary tree node structure
struct TreeNode {
    int data;
    struct TreeNode* left;
    struct TreeNode* right;
};

// Function to create a new tree node
struct TreeNode* createNode(int data) {
    struct TreeNode* newNode = (struct TreeNode*)malloc(sizeof(struct TreeNode));
    newNode->data = data;
    newNode->left = newNode->right = NULL;
    return newNode;
}

// Function to print the inorder traversal of a binary tree
void inorderTraversal(struct TreeNode* root) {
    if (root != NULL) {
        inorderTraversal(root->left);
        printf("%d ", root->data);
        inorderTraversal(root->right);
    }
}

// Function to convert a binary tree into a mirror tree (invert binary tree)
struct TreeNode* mirrorTree(struct TreeNode* root) {
    if (root == NULL) {
        return NULL;
    }

    // Swap the left and right subtrees
    struct TreeNode* temp = root->left;
    root->left = root->right;
    root->right = temp;

    // Recursively invert the left and right subtrees
    mirrorTree(root->left);
    mirrorTree(root->right);

    return root;
}

int main() {
    // Example tree
    struct TreeNode* root = createNode(1);
    root->left = createNode(2);
    root->right = createNode(3);
    root->left->left = createNode(4);
    root->left->right = createNode(5);

    // Print the original tree
    printf("Original tree (inorder traversal): ");
    inorderTraversal(root);
    printf("\n");

    // Convert the tree into a mirror tree
    root = mirrorTree(root);

    // Print the mirror tree
    printf("Mirror tree (inorder traversal): ");
    inorderTraversal(root);
    printf("\n");

    // Free the allocated memory for the tree nodes
    free(root->left->left);
    free(root->left->right);
    free(root->left);
    free(root->right);
    free(root);

    return 0;
}
