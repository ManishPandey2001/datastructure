//15. CONSTRUCT BINARY SEARCH TREE FROM GIVEN PREORDER TRAVERSAL THROUGH ARRAYS.

#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* left;
    struct Node* right;
};

struct Node* createNode(int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->left = newNode->right = NULL;
    return newNode;
}

struct Node* insert(struct Node* root, int value) {
    if (root == NULL) {
        return createNode(value);
    }
    if (value < root->data) {
        root->left = insert(root->left, value);
    } else {
        root->right = insert(root->right, value);
    }
    return root;
}

void preorderTraversal(struct Node* root) {
    if (root == NULL) return;
    printf("%d ", root->data);
    preorderTraversal(root->left);
    preorderTraversal(root->right);
}

struct Node* constructBSTFromPreorder(int* preorder, int size) {
    struct Node* root = NULL;
    for (int i = 0; i < size; i++) {
        root = insert(root, preorder[i]);
    }
    return root;
}

int main() {
    int n;

    printf("Enter the number of nodes in the binary search tree: ");
    scanf("%d", &n);

    int preorder[n];
    printf("Enter the preorder traversal: ");
    for (int i = 0; i < n; i++) {
        scanf("%d", &preorder[i]);
    }

    struct Node* root = constructBSTFromPreorder(preorder, n);

    printf("Constructed Binary Search Tree (Preorder Traversal): ");
    preorderTraversal(root);
    printf("\n");

    return 0;
}



 
