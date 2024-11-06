//17. CREATE STRICTLY BINARY TREE FROM THE GIVEN INPUT BY THE USER (DYNAMICALLY).
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

void createTree(struct Node** root) {
    int data;
    printf("Enter data for node (-1 to stop): ");
    scanf("%d", &data);

    if (data == -1) return;

    *root = newNode(data);
    
    printf("Creating left child of %d:\n", data);
    createTree(&((*root)->left));
    
    printf("Creating right child of %d:\n", data);
    createTree(&((*root)->right));
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

    printf("Create a strictly binary tree:\n");
    createTree(&root);

    printf("Inorder Traversal of the constructed tree: ");
    inorder(root);
    printf("\n");

    freeTree(root);
    return 0;
}


                        

