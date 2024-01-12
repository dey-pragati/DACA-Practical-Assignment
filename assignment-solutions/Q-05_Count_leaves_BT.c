//  5. Count number of leaves in a given binary tree.
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

// Function to count the number of leaf nodes in a binary tree
int countLeaves(struct TreeNode* root) {
    // If the tree is empty, there are no leaves
    if (root == NULL) {
        return 0;
    }

    // If the node is a leaf, return 1
    if (root->left == NULL && root->right == NULL) {
        return 1;
    }

    // Recursively count the leaves in the left and right subtrees
    return countLeaves(root->left) + countLeaves(root->right);
}

int main() {
    // Example tree
    struct TreeNode* root = createNode(1);
    root->left = createNode(2);
    root->right = createNode(3);
    root->left->left = createNode(4);
    root->left->right = createNode(5);
    root->right->left = createNode(6);
    root->right->right = createNode(7);

    // Count and print the number of leaves in the tree
    printf("Number of leaves in the tree: %d\n", countLeaves(root));

    // Free the allocated memory for the tree nodes
    free(root->left->left);
    free(root->left->right);
    free(root->left);
    free(root->right->left);
    free(root->right->right);
    free(root->right);
    free(root);

    return 0;
}
