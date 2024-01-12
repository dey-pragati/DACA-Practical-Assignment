//  4. Determine if two given tree are identical or not.
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

// Function to check if two trees are identical
int areIdentical(struct TreeNode* root1, struct TreeNode* root2) {
    // If both trees are empty, they are identical
    if (root1 == NULL && root2 == NULL) {
        return 1;
    }

    // If one of the trees is empty and the other is not, they are not identical
    if (root1 == NULL || root2 == NULL) {
        return 0;
    }

    // Check if the current nodes are equal and recursively check left and right subtrees
    return (root1->data == root2->data) &&
           areIdentical(root1->left, root2->left) &&
           areIdentical(root1->right, root2->right);
}

int main() {
    // Example trees
    struct TreeNode* root1 = createNode(1);
    root1->left = createNode(2);
    root1->right = createNode(3);

    struct TreeNode* root2 = createNode(1);
    root2->left = createNode(2);
    root2->right = createNode(3);

    // Check if the trees are identical
    if(areIdentical(root1, root2)) {
        printf("The trees are identical.\n");
    } else {
        printf("The trees are not identical.\n");
    }

    // Free the allocated memory for the tree nodes
    free(root1->left);
    free(root1->right);
    free(root1);

    free(root2->left);
    free(root2->right);
    free(root2);

    return 0;
}
