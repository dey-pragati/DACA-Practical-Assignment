//  6. Check if given binary tree is BST or not.

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <limits.h>

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

// Function to check if a binary tree is a BST
bool isBSTUtil(struct TreeNode* root, int minValue, int maxValue) {
    // Base case: an empty tree is a BST
    if (root == NULL) {
        return true;
    }

    // Check if the current node's value is within the valid range
    if (root->data < minValue || root->data > maxValue) {
        return false;
    }

    // Recursively check the left and right subtrees with updated range
    return isBSTUtil(root->left, minValue, root->data - 1) &&
           isBSTUtil(root->right, root->data + 1, maxValue);
}

// Function to check if a binary tree is a BST (wrapper function)
bool isBST(struct TreeNode* root) {
    return isBSTUtil(root, INT_MIN, INT_MAX);
}

int main() {
    // Example BST
    struct TreeNode* root = createNode(2);
    root->left = createNode(1);
    root->right = createNode(3);

    // Check if the tree is a BST
    if (isBST(root)) {
        printf("The tree is a Binary Search Tree (BST).\n");
    } else {
        printf("The tree is not a Binary Search Tree (BST).\n");
    }

    // Free the allocated memory for the tree nodes
    free(root->left);
    free(root->right);
    free(root);

    return 0;
}
