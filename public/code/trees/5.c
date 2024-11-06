//5. CONSTRUCT BINARY TREE FROM POSTORDER AND INORDER TRAVERSAL.

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

int findIndex(int arr[], int start, int end, int value) {
    for (int i = start; i <= end; i++) {
        if (arr[i] == value) return i;
    }
    return -1;
}

struct Node* buildTree(int post[], int in[], int inStart, int inEnd, int* postIndex) {
    if (inStart > inEnd) return NULL;

    int rootValue = post[*postIndex];
    struct Node* root = makeNode(rootValue);
    (*postIndex)--;

    if (inStart == inEnd) return root;

    int inIndex = findIndex(in, inStart, inEnd, rootValue);
    
    root->right = buildTree(post, in, inIndex + 1, inEnd, postIndex);
    root->left = buildTree(post, in, inStart, inIndex - 1, postIndex);

    return root;
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

    int post[n], in[n];
    
    printf("Enter postorder traversal:\n");
    for (int i = 0; i < n; i++) {
        scanf("%d", &post[i]);
    }

    printf("Enter inorder traversal:\n");
    for (int i = 0; i < n; i++) {
        scanf("%d", &in[i]);
    }

    int postIndex = n - 1;
    struct Node* root = buildTree(post, in, 0, n - 1, &postIndex);

    printf("In-order traversal of the constructed tree:\n");
    printInOrder(root);
    printf("\n");

    return 0;
}


