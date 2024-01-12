//  3. Calculate the size of tree using recursion.
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

// Function to calculate the size of a binary tree using recursion
int calculateSize(struct TreeNode* root) {
    if (root == NULL) {
        return 0;
    } else {
        // Calculate size recursively by summing the sizes of left and right subtrees
        return 1 + calculateSize(root->left) + calculateSize(root->right);
    }
}

int main() {
    // Example tree
    struct TreeNode* root = createNode(1);
    root->left = createNode(2);
    root->right = createNode(3);
    root->left->left = createNode(4);
    root->left->right = createNode(5);
    root->right->left = createNode(10);
    root->right->right = createNode(12);

    // Calculate and print the size of the tree
    printf("Size of the tree: %d\n", calculateSize(root));

    // Free the allocated memory for the tree nodes (not necessary for calculating size)
    free(root->right->right);
    free(root->right->left);
    free(root->left->left);
    free(root->left->right);
    free(root->left);
    free(root->right);
    free(root);

    return 0;
}
