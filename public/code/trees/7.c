// 7. CREATE BINARY SEARCH TREE USING ARRAYS .
(INSERT, DELETE, SEARCH, PREORDER, INORDER, POSTORDER, MINIMUM ELEMENT)

#include< stdio.h >

struct BST {
    int data[100]; 
    int size;
};

void initBST(struct BST* bst) {
    bst->size = 0;
}

int insert(struct BST* bst, int value) {
    if (bst->size >= 100) {
        return 0; // Tree is full
    }
    bst->data[bst->size++] = value;
    return 1;
}

int delete(struct BST* bst, int value) {
    int idx = -1;
    for (int i = 0; i < bst->size; i++) {
        if (bst->data[i] == value) {
            idx = i;
            break;
        }
    }
    if (idx == -1) return 0;

    bst->data[idx] = bst->data[--bst->size]; 
    return 1;
}

int search(struct BST* bst, int value) {
    for (int i = 0; i < bst->size; i++) {
        if (bst->data[i] == value) return 1;
    }
    return 0;
}

void preorder(struct BST* bst, int index) {
    if (index >= bst->size) return;
    printf("%d ", bst->data[index]);
    preorder(bst, 2 * index + 1);
    preorder(bst, 2 * index + 2);
}

void inorder(struct BST* bst, int index) {
    if (index >= bst->size) return;
    inorder(bst, 2 * index + 1);
    printf("%d ", bst->data[index]);
    inorder(bst, 2 * index + 2);
}

void postorder(struct BST* bst, int index) {
    if (index >= bst->size) return;
    postorder(bst, 2 * index + 1);
    postorder(bst, 2 * index + 2);
    printf("%d ", bst->data[index]);
}

int minimum(struct BST* bst) {
    if (bst->size == 0) return -1; 
    return bst->data[0]; 
}

int main() {
    struct BST bst;
    initBST(&bst);

    int choice, value;

    while (1) {
        printf("\n1. Insert\n2. Delete\n3. Search\n4. Preorder Traversal\n5. Inorder Traversal\n6. Postorder Traversal\n7. Minimum Element\n8. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter value to insert: ");
                scanf("%d", &value);
                if (insert(&bst, value))
                    printf("%d inserted into the tree.\n", value);
                else
                    printf("Tree is full. Cannot insert %d.\n", value);
                break;
            case 2:
                printf("Enter value to delete: ");
                scanf("%d", &value);
                if (delete(&bst, value))
                    printf("%d deleted from the tree.\n", value);
                else
                    printf("%d not found in the tree.\n", value);
                break;
            case 3:
                printf("Enter value to search: ");
                scanf("%d", &value);
                printf("Searching for %d: %s\n", value, search(&bst, value) ? "Found" : "Not Found");
                break;
            case 4:
                printf("Preorder Traversal:\n");
                preorder(&bst, 0);
                printf("\n");
                break;
            case 5:
                printf("Inorder Traversal:\n");
                inorder(&bst, 0);
                printf("\n");
                break;
            case 6:
                printf("Postorder Traversal:\n");
                postorder(&bst, 0);
                printf("\n");
                break;
            case 7:
                printf("Minimum element: %d\n", minimum(&bst));
                break;
            case 8:
                return 0;
            default:
                printf("Invalid choice. Please try again.\n");
        }
    }

    return 0;
}

               
                    
