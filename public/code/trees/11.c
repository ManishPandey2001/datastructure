//11. CREATE BINARY TREE TO BINARY SEARCH TREE THROUGH ARRAY.
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

void inorderTraversal(struct Node* root, int* arr, int* index) {
    if (root == NULL) return;
    inorderTraversal(root->left, arr, index);
    arr[(*index)++] = root->data;
    inorderTraversal(root->right, arr, index);
}

int compare(const void* a, const void* b) {
    return ((int)a - (int)b);
}

void sortedArrayToBST(int* arr, struct Node** root, int start, int end) {
    if (start > end) return;
    int mid = (start + end) / 2;
    *root = createNode(arr[mid]);
    sortedArrayToBST(arr, &(*root)->left, start, mid - 1);
    sortedArrayToBST(arr, &(*root)->right, mid + 1, end);
}

struct Node* convertToBST(struct Node* root) {
    int* arr = (int*)malloc(100 * sizeof(int)); 
    int index = 0;

    inorderTraversal(root, arr, &index);
    qsort(arr, index, sizeof(int), compare);
    
    struct Node* newRoot = NULL;
    sortedArrayToBST(arr, &newRoot, 0, index - 1);
    
    free(arr);
    return newRoot;
}

void printInorder(struct Node* root) {
    if (root == NULL) return;
    printInorder(root->left);
    printf("%d ", root->data);
    printInorder(root->right);
}

void buildBinaryTree(struct Node* nodes[], int size) {
    for (int i = 0; i < size; i++) {
        int data;
        printf("Enter value for node %d: ", i + 1);
        scanf("%d", &data);
        nodes[i] = createNode(data);
    }
    
    for (int i = 0; i < size; i++) {
        if (2 * i + 1 < size) nodes[i]->left = nodes[2 * i + 1];
        if (2 * i + 2 < size) nodes[i]->right = nodes[2 * i + 2];
    }
}

int main() {
    int n;

    printf("Enter the number of nodes in the binary tree: ");
    scanf("%d", &n);

    struct Node* nodes[n]; 

    buildBinaryTree(nodes, n);

    printf("Original Binary Tree (Inorder): ");
    printInorder(nodes[0]);
    
    struct Node* bstRoot = convertToBST(nodes[0]);
    
    printf("\nConverted Binary Search Tree (Inorder): ");
    printInorder(bstRoot);
    
    return 0;
}




            

