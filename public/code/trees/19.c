//19. CREATE COMPLETE BINARY TREE FROM THE GIVEN INPUT BY THE USER (DYNAMICALLY)
#include< stdio.h >
#include< stdlib.h >

struct Node {
    int data;
    struct Node* left;
    struct Node* right;
};

struct Node* newNode(int data) {
    struct Node* node = (struct Node*)malloc(sizeof(struct Node));
    node->data = data;
    node->left = node->right = NULL;
    return node;
}

void createTree(struct Node** root, int index, int totalNodes) {
    if (index >= totalNodes) return;

    int data;
    printf("Enter data for node %d: ", index + 1);
    scanf("%d", &data);

    *root = newNode(data);
    
    printf("Creating left child of %d...\n", data);
    createTree(&((*root)->left), 2 * index + 1, totalNodes);
    
    printf("Creating right child of %d...\n", data);
    createTree(&((*root)->right), 2 * index + 2, totalNodes);
}

void inorder(struct Node* root) {
    if (root == NULL) return;
    inorder(root->left);
    printf("%d ", root->data);
    inorder(root->right);
}

void freeTree(struct Node* root) {
    if (root != NULL) {
        freeTree(root->left);
        freeTree(root->right);
        free(root);
    }
}

int main() {
    struct Node* root = NULL;
    int totalNodes;

    printf("Enter the total number of nodes: ");
    scanf("%d", &totalNodes);

    createTree(&root, 0, totalNodes);

    printf("\nInorder Traversal: ");
    inorder(root);
    printf("\n");

    freeTree(root);
    return 0;
}


