//9. FIND INORDER PREDECESSOR AND INORDER SUCCESSOR OF BINARY SEARCH TREE (DYNAMICALLY REPRESENTED)

#include< stdio.h >
#include< stdlib.h >

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

struct Node* findPredecessor(struct Node* root) {
    if (root == NULL) return NULL;
    struct Node* current = root->left;
    while (current && current->right) {
        current = current->right;
    }
    return current;
}

struct Node* findSuccessor(struct Node* root) {
    if (root == NULL) return NULL;
    struct Node* current = root->right;
    while (current && current->left) {
        current = current->left;
    }
    return current;
}

struct Node* search(struct Node* root, int value) {
    if (root == NULL || root->data == value) return root;
    if (value < root->data) return search(root->left, value);
    return search(root->right, value);
}

int main() {
    struct Node* root = NULL;
    int choice, value;

    while (1) {
        printf("\n1. Insert\n2. Find Inorder Predecessor\n3. Find Inorder Successor\n4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter value to insert: ");
                scanf("%d", &value);
                root = insert(root, value);
                break;
            case 2:
                printf("Enter value to find its predecessor: ");
                scanf("%d", &value);
                struct Node* node = search(root, value);
                if (node) {
                    struct Node* predecessor = findPredecessor(node);
                    if (predecessor) {
                        printf("Inorder Predecessor of %d: %d\n", value, predecessor->data);
                    } else {
                        printf("%d has no predecessor.\n", value);
                    }
                } else {
                    printf("Value %d not found in the tree.\n", value);
                }
                break;
            case 3:
                printf("Enter value to find its successor: ");
                scanf("%d", &value);
                node = search(root, value);
                if (node) {
                    struct Node* successor = findSuccessor(node);
                    if (successor) {
                        printf("Inorder Successor of %d: %d\n", value, successor->data);
                    } else {
                        printf("%d has no successor.\n", value);
                    }
                } else {
                    printf("Value %d not found in the tree.\n", value);
                }
                break;
            case 4:
                exit(0);
            default:
                printf("Invalid choice. Please try again.\n");
        }
    }

    return 0;
}


