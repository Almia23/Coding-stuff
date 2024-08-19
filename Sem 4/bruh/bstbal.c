#include <stdio.h>
#include <stdlib.h>

struct node
{
    int data;
    struct node *left;
    struct node *right;
};

int max(int a, int b)
{
    return (a > b ? a : b);
}

struct node *insert(struct node *root, int d)
{
    if (root == NULL)
    {
        root = (struct node *)malloc(sizeof(struct node));
        root->data = d;
        root->left = NULL;
        root->right = NULL;
    }
    else if (root->data < d)
    {
        root->right = insert(root->right, d);
    }
    else if (root->data > d)
    {
        root->left = insert(root->left, d);
    }
    else
    {
        printf("Duplicate node\n");
        exit(0);
    }
    return (root);
}

int height(struct node *root)
{
    if (root == NULL)
    {
        return -1;
    }
    else
    {
        return (max(height(root->left), height(root->right)) + 1);
    }
}

void preorder(struct node *root)
{
    if (root)
    {
        printf("%d ", root->data);
        preorder(root->left);
        preorder(root->right);
    }
}
void preorderbal(struct node *root)
{
    if (root)
    {
        int bal = height(root->left) - height(root->right);
        printf("Value:%d Balance factor:%d\n", root->data, bal);
        preorderbal(root->left);
        preorderbal(root->right);
    }
}

int main()
{
    struct node *root = NULL;
    int c, d;

    while (1)
    {
        printf("\n1:Insert, 2:Preorder, 3:Balance Factors, 4:Exit\n");
        printf("Choice: ");
        scanf("%d", &c);
        switch (c)
        {
        case 1:
            printf("Enter data: ");
            scanf("%d", &d);
            root = insert(root, d);
            printf("Inserted\n");
            break;
        case 2:
            printf("Printing preorder: \n");
            preorder(root);
            printf("\n");
            break;
        case 3:
            printf("Printing balance factors: \n\n");
            preorderbal(root);
            printf("\n");
            break;
        case 4:
            printf("Exiting ");
            exit(0);
            break;
        default:
            printf("Enter valid choice");
            break;
        }
    }
    return 0;
}