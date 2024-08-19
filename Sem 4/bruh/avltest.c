#include <stdio.h>
#include <stdlib.h>

struct node
{
    int data;
    struct node *left;
    struct node *right;
    int height;
};

int max(int a, int b)
{
    return a > b ? a : b;
}

int height(struct node *root)
{
    if (root == NULL)
        return -1;
    return max(height(root->left), height(root->right) + 1);
}

struct node *create(int d)
{
    struct node *temp = (struct node *)malloc(sizeof(struct node));
    temp->data = d;
    temp->left = NULL;
    temp->right = NULL;
    return temp;
}

struct node *r(struct node *root)
{
    struct node *a = root->left;
    struct node *b = a->right;
    a->right = root;
    root->left = b;
    return a;
}
struct node *l(struct node *root)
{
    struct node *a = root->right;
    struct node *b = a->left;
    a->left = root;
    root->right = b;
    return a;
}
int balance(struct node *root)
{
    if (root == NULL)
        return 0;
    return height(root->left) - height(root->right);
}

struct node *insert(struct node *root, int d)
{
    if (root == NULL)
        return create(d);
    else if (d < root->data)
    {
        root->left = insert(root->left, d);
    }
    else if (d > root->data)
    {
        root->right = insert(root->right, d);
    }
    else
    {
        printf("Duplicate node not allowed\n");
        return root;
    }
    int b = balance(root);
    if (b > 1 && d < root->left->data)
    {
        return r(root);
    }
    if (b < -1 && d > root->right->data)
    {
        return l(root);
    }
    if (b > 1 && d > root->left->data)
    {
        root->left = l(root->left);
        return r(root);
    }
    if (b < -1 && d < root->right->data)
    {
        root->right = r(root->right);
        return l(root);
    }
    return root;
}
void preOrder(struct node *root)
{
    if (root != NULL)
    {
        printf("%d ", root->data);
        preOrder(root->left);
        preOrder(root->right);
    }
}
void preorderbal(struct node *root)
{
    if (root != NULL)
    {
        printf("%d:%d , ", root->data, balance(root));
        preorderbal(root->left);
        preorderbal(root->right);
    }
}
int main()
{
    struct node *root = NULL;

    int c, val;
    printf("1:Insert, 2:Preorder and balance, 3:Exit\n");
    while (1)
    {
        printf("Choice: ");
        scanf("%d", &c);
        switch (c)
        {
        case 1:
            printf("Data: \n");
            scanf("%d", &val);
            root = insert(root, val);
            printf("Inserted\n");
            break;
        case 2:
            printf("Preorder traversal of the constructed AVL tree is \n");
            preOrder(root);
            printf("\nBalance factors: \n");
            preorderbal(root);
            printf("\n");
            break;
        case 3:
            exit(0);
            break;
        default:
            printf("Enter valid choice\n");
            break;
        }
    }

    return 0;
}