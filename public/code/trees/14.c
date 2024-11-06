//14. PRINT PREORDER TRAVERSAL TO POSTORDER TRAVERSAL OF BINARY SEARCH TREE.

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

void postorderTraversal(struct Node* root) {
    if (root == NULL) return;
    postorderTraversal(root->left);
    postorderTraversal(root->right);
    printf("%d ", root->data);
}

struct Node* buildBSTFromPreorder(int* preorder, int* index, int size) {
    if (*index >= size) return NULL;

    struct Node* root = createNode(preorder[*index]);
    (*index)++;

    while (*index < size && preorder[*index] < root->data) {
        root->left = buildBSTFromPreorder(preorder, index, size);
    }
    
    while (*index < size && preorder[*index] > root->data) {
        root->right = buildBSTFromPreorder(preorder, index, size);
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

    int index = 0;
    struct Node* root = buildBSTFromPreorder(preorder, &index, n);

    printf("Postorder Traversal: ");
    postorderTraversal(root);
    printf("\n");

    return 0;
}



                        
