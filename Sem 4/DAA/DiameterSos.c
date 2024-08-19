#include <stdio.h>
#include <stdlib.h>

struct node
{
    int data;
    struct node *left, *right;
};

struct node *create(int val)
{
    int n;
    if (val == -1)
        return NULL;
    struct node *nd = (struct node *)malloc(sizeof(struct node));
    nd->data = val;
    printf("enter left child of %d or -1: ", nd->data);
    scanf("%d", &n);
    nd->left = create(n);
    printf("enter right child of %d or -1: ", nd->data);
    scanf("%d", &n);
    nd->right = create(n);
    return nd;
}
void inorder(struct node *root)
{
    if (root)
    {

        inorder(root->left);
        printf("%d ", root->data);
        inorder(root->right);
    }
}
int height(struct node *root)
{
    if (root == NULL)
        return 0;
    int leftHeight = height(root->left);
    int rightHeight = height(root->right);
    return 1 + (leftHeight > rightHeight ? leftHeight : rightHeight);
}

// Function to find the diameter of a binary tree
int diameterOfBinaryTree(struct node *root)
{
    if (root == NULL)
        return 0;
    int leftHeight = height(root->left);
    int rightHeight = height(root->right);

    int leftDiameter = diameterOfBinaryTree(root->left);
    int rightDiameter = diameterOfBinaryTree(root->right);

    return (leftHeight + rightHeight > leftDiameter && leftHeight + rightHeight > rightDiameter) ? leftHeight + rightHeight : (leftDiameter > rightDiameter ? leftDiameter : rightDiameter);
}

int main()
{
    int n;
    printf("enter value of root:");
    scanf("%d", &n);
    struct node *root = create(n);
    inorder(root);
    printf("\n");
    int diameter = diameterOfBinaryTree(root);
    printf("Diameter of the binary tree is: %d\n", diameter);
    return 0;
}