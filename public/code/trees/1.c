// 1. CONSTRUCT BINARY TREE FROM PREORDER AND INORDER TRAVERSAL
#include <stdio.h>
#include <stdlib.h>
#define maxSize 100
struct node
{
    int data;
    struct node *left;
    struct node *right;
};
int getRootIndex(int root, int inOrder[maxSize], int size)
{
    for (int i = 0; i < size; i++)
    {
        if (inOrder[i] == root)
        {
            return i;
        }
    }
    return -1;
}
int makeBt(struct node *start, int preorder[maxSize], int inorder[maxSize], int size, int rootIndex)
{
    struct node *pos = start;
    pos->data = preorder[0];
    int ri = rootIndex;
    int pi;
    for (int i = 1; i < size; i++)
    {
        for (int j = 0; j < size; j++)
        {
            if (inorder[j] == preorder[i])
            {
                struct node *temp = (struct node *)malloc(sizeof(struct node));
                temp->data = preorder[i];
                temp->left = NULL;
                temp->right = NULL;
                if (temp != NULL)
                {
                    if (j < ri)
                    {
                        printf("%d <- %d\n ", temp->data, pos->data);
                        pos->left = temp;
                        pos = pos->left;
                        pi = ri;
                        ri = j;
                    }
                    else
                    {
                        printf("%d -> %d\n ", pos->data, temp->data);
                        pos->right = temp;
                        pos = pos->right;
                        ri = pi;
                        
                    }
                }
                else
                {
                    return 1;
                }
            }
        }
    }
    return 0;
}
void displayBtPreOrder(struct node *start)
{
    printf("%d ", start->data);
    if (start->left != NULL)
    {
        displayBtPreOrder(start->left);
    }
    else if (start->right != NULL)
    {
        displayBtPreOrder(start->right);
    }
}
void displayBtInOrder(struct node *start)
{
    if (start->left != NULL)
    {
        displayBtInOrder(start->left);
    }
    else
    {
        printf("%d ", start->data);
        if (start->right != NULL)
        {
            displayBtInOrder(start->right);
        }
    }
}
int main()
{
    int size;
    int preorder[maxSize], inorder[maxSize];
    struct node *start = (struct node *)malloc(sizeof(struct node));
    start->left = NULL;
    start->right = NULL;
    int ri;
    printf("Size of list (max size 100) : ");
    scanf("%d", &size);
    // for (int i = 0; i < size; i++)
    // {
    //     printf("Enter pre order element [%d] : ", i);
    //     scanf("%d", preorder + i);
    // }
    // for (int i = 0; i < size; i++)
    // {
    //     printf("Enter in order element [%d] : ", i);
    //     scanf("%d", inorder + i);
    // }
    preorder[0] = 1;
    preorder[1] = 2;
    preorder[2] = 4;
    preorder[3] = 8;
    preorder[4] = 5;
    preorder[5] = 3;
    preorder[6] = 6;
    preorder[7] = 7;
    inorder[0] = 4;
    inorder[1] = 8;
    inorder[2] = 2;
    inorder[3] = 5;
    inorder[4] = 1;
    inorder[5] = 6;
    inorder[6] = 3;
    inorder[7] = 7;
    ri = getRootIndex(preorder[0], inorder, size);
    makeBt(start, preorder, inorder, size, ri);
    printf("Binary Tree InOrder : ");
    displayBtInOrder(start);
    printf("\nBinary Tree PreOrder : ");
    displayBtPreOrder(start);
    return 0;
}