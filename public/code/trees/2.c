// 2. BINARY TREE LEVEL ORDER TRAVERSAL
#include <stdio.h>
#include <stdlib.h>

// Structure for a binary tree node
struct Node
{
    int data;
    struct Node *left;
    struct Node *right;
};

// Function to create a new node
struct Node *newNode(int data)
{
    struct Node *node = (struct Node *)malloc(sizeof(struct Node));
    node->data = data;
    node->left = node->right = NULL;
    return node;
}

// Function to insert a new node in the binary tree
struct Node *insert(struct Node *root, int data)
{
    if (root == NULL)
    {
        return newNode(data);
    }

    if (data < root->data)
    {
        root->left = insert(root->left, data);
    }
    else
    {
        root->right = insert(root->right, data);
    }

    return root;
}

// Function to perform level order traversal
void levelOrderTraversal(struct Node *root)
{
    if (root == NULL)
    {
        printf("Tree is empty.\n");
        return;
    }

    struct Node *queue[100]; // Simple queue for level order traversal
    int front = 0, rear = 0;

    queue[rear++] = root;

    while (front < rear)
    {
        struct Node *current = queue[front++];
        printf("%d ", current->data);

        if (current->left != NULL)
        {
            queue[rear++] = current->left;
        }
        if (current->right != NULL)
        {
            queue[rear++] = current->right;
        }
    }
    printf("\n");
}

// Menu-driven program to interact with the user
int main()
{
    struct Node *root = NULL;
    int choice, value;

    while (1)
    {
        printf("\nMenu:\n");
        printf("1. Insert a node\n");
        printf("2. Level Order Traversal\n");
        printf("3. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice)
        {
        case 1:
            printf("Enter value to insert: ");
            scanf("%d", &value);
            root = insert(root, value);
            printf("Inserted %d into the binary tree.\n", value);
            break;
        case 2:
            printf("Level Order Traversal:\n");
            levelOrderTraversal(root);
            break;
        case 3:
            printf("Exiting...\n");
            exit(0);
        default:
            printf("Invalid choice! Please try again.\n");
        }
    }
    return 0;
}
