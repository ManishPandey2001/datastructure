//3. PRINT LEFT VIEW OF BINARY TREE         

#include< stdio.h >
#include< stdlib.h >

struct Node {
    int data;
    struct Node* left;
    struct Node* right;
};

struct Node* createNode(int data) {
    struct Node* node = (struct Node*)malloc(sizeof(struct Node));
    node->data = data;
    node->left = node->right = NULL;
    return node;
}

void printLeftViewUtil(struct Node* root, int level, int* maxLevel) {
    if (root == NULL) return;

    if (*maxLevel < level) {
        printf("%d ", root->data);
        *maxLevel = level;
    }

    printLeftViewUtil(root->left, level + 1, maxLevel);
    printLeftViewUtil(root->right, level + 1, maxLevel);
}

void printLeftView(struct Node* root) {
    int maxLevel = 0;
    printLeftViewUtil(root, 1, &maxLevel);
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
        struct Node* node = createNode(data);
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
                    temp = temp->right;}
               }
               }
            }
    printf("Left view of the binary tree:\n");
    printLeftView(root);
    printf("\n");

    return 0;
}





 
