// DIAMETER
#include <stdio.h>
#include <stdlib.h>
struct node
{
    int data;
    struct node *left;
    struct node *right;
};
struct node *root = NULL;

struct node *newnode(int a)
{
    struct node *temp = (struct node *)malloc(sizeof(struct node));
    temp->data = a;
    temp->left = temp->right = NULL;
    return temp;
};
struct node *insert(struct node *root, int d)
{
    if (root == NULL)
    {
        return newnode(d);
    }
    else if (root->data < d)
    {
        return insert(root->right, d);
    }
    else
    {
        return insert(root->left, d);
    }
    return root;
}
struct node *search(struct node *root, int d)
{
    if (root == NULL || root->data == d)
    {
        return root;
    }
    else if (root->data < d)
    {
        return search(root->right, d);
    }
    else if (root->data > d)
    {
        return search(root->left, d);
    }
}
int max(int a, int b) { return (a > b) ? a : b; }

int height(struct node *root)
{
    if (root == NULL)
        return 0;
    return 1 + max(height(root->left), height(root->right));
}
int diameter(struct node *root)
{
    if (root == NULL)
        return 0;

    int lh = height(root->left);
    int rh = height(root->right);

    int ld = diameter(root->left);
    int rd = diameter(root->right);

    return max(lh + rh + 1, max(ld, rd));
}
void inorder(struct node *root)
{
    inorder(root->left);
    printf("%d", root->data);
    inorder(root->right);
}
void main()
{
    int c, d;
    struct node start;
    printf("Enter 1 to insert, 2 to Diameter, 3 to exit\n");
    while (1)
    {
        printf("\nChoice:");
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
            inorder(root);
            printf("Diameter= %d\n", diameter(root));
            break;
        case 3:
            printf("Exiting");
            exit(0);
            break;
        default:
            printf("Invalid");
            break;
        }
    }
}