//13. FIND KTH SMALLEST ELEMENT IN A BINARY SEARCH TREE THROUGH ARRAY.
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

int findKthSmallest(int* arr, int size, int k) {
    if (k > 0 && k <= size) {
        return arr[k - 1];
    }
    return -1; 
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
    int n, k;

    printf("Enter the number of nodes in the binary search tree: ");
    scanf("%d", &n);

    struct Node* nodes[n]; 

    buildBinaryTree(nodes, n);

    int arr[n];
    int index = 0;

    inorderTraversal(nodes[0], arr, &index);

    printf("Enter the value of k to find the k-th smallest element: ");
    scanf("%d", &k);

    int kthSmallest = findKthSmallest(arr, n, k);
    
    if (kthSmallest != -1) {
        printf("The %d-th smallest element is: %d\n", k, kthSmallest);
    } else {
        printf("Invalid value of k.\n");
    }

    return 0;
}

                        





                
 
 