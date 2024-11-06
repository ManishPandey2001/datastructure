//6. FIND THE MAXIMUM DEPTH OF BINARY TREE.

#include< stdio.h >
#include< stdlib.h >

struct Node {
    int data;
    struct Node* left;
    struct Node* right;
};

struct Node* makeNode(int data) {
    struct Node* node = (struct Node*)malloc(sizeof(struct Node));
    node->data = data;
    node->left = node->right = NULL;
    return node;
}

int maxDepth(struct Node* root) {
    if (root == NULL) return 0;
    int leftDepth = maxDepth(root->left);
    int rightDepth = maxDepth(root->right);
    return (leftDepth > rightDepth ? leftDepth : rightDepth) + 1;
}

void printInOrder(struct Node* node) {
    if (node == NULL) return;
    printInOrder(node->left);
    printf("%d ", node->data);
    printInOrder(node->right);
}

int main() {
    int n;
    printf("Enter the number of nodes: ");
    scanf("%d", &n);

    struct Node* root = NULL;
    for (int i = 0; i < n; i++) {
        int data;
        printf("Enter node value: ");
        scanf("%d", &data);
        struct Node* node = makeNode(data);
        if (i == 0) {
            root = node;
        } else {
            struct Node* temp = root;
            while (1) {
                if (data < temp->data) {
                    if (temp->left == NULL) {
                        temp->left = node;
                        break;
                    }
                    temp = temp->left;
                } else {
                    if (temp->right == NULL) {
                        temp->right = node;
                        break;
                    }
                    temp = temp->right;  }
            }
            }
            }
    int depth = maxDepth(root);
    printf("Maximum depth of the binary tree: %d\n", depth);
    return 0;
}


                         
              

                  
           
    
