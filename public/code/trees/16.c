 //16. CONSTRUCT BINARY SEARCH TREE FROM GIVEN POSTORDER TRAVERSAL THROUGH ARRAYS

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

struct Node* constructBSTFromPostorder(int* postorder, int* index, int min, int max) {
    if (index[0] < 0) return NULL;

    int value = postorder[index[0]];
    if (value < min || value > max) return NULL;

    index[0]--; 

    struct Node* root = createNode(value);
    
    root->right = constructBSTFromPostorder(postorder, index, value, max);
    root->left = constructBSTFromPostorder(postorder, index, min, value);

    return root;
}

void postorderTraversal(struct Node* root) {
    if (root == NULL) return;
    postorderTraversal(root->left);
    postorderTraversal(root->right);
    printf("%d ", root->data);
}

int main() {
    int n;

    printf("Enter the number of nodes in the binary search tree: ");
    scanf("%d", &n);

    int postorder[n];
    printf("Enter the postorder traversal: ");
    for (int i = 0; i < n; i++) {
        scanf("%d", &postorder[i]);
    }

    int index = n - 1; 
    struct Node* root = constructBSTFromPostorder(postorder, &index, INT_MIN, INT_MAX);

    printf("Constructed Binary Search Tree (Postorder Traversal): ");
    postorderTraversal(root);
    printf("\n");

    return 0;
}



                         


