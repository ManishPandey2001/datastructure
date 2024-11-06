//10. CHECK WHETHER BINARY SEARCH TREE CONTAINS DEAD END.
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

int isDeadEnd(struct Node* root, int min, int max) {
    if (root == NULL) return 0;
    if (min == max) return 1;
    return isDeadEnd(root->left, min, root->data - 1) || isDeadEnd(root->right, root->data + 1, max);
}

int checkDeadEnd(struct Node* root) {
    return isDeadEnd(root, 1, 1000);
}

int main() {
    struct Node* root = NULL;
    int choice, value;

    while (1) {
        printf("\n1. Insert\n2. Check for Dead End\n3. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter value to insert: ");
                scanf("%d", &value);
                root = insert(root, value);
                break;
            case 2:
                if (checkDeadEnd(root)) {
                    printf("The BST contains a dead end.\n");
                } else {
                    printf("The BST does not contain a dead end.\n");
                }
                break;
            case 3:
                exit(0);
            default:
                printf("Invalid choice. Please try again.\n");
    }
    }
      return 0; }



