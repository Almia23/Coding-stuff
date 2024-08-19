#include <stdio.h>
#include <stdlib.h>
struct node
{
    int data;
    struct node *left, *right;
};
struct node *create(int d)
{
    struct node *newnode = (struct node *)malloc(sizeof(struct node));
    newnode->data = d;
    newnode->left = newnode->right = NULL;
    return newnode;
}
struct node *insert(struct node *root, int d)
{
    if (root == NULL)
    {
        return create(d);
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
    else
    {
        return search(root->left, d);
    }
}
int main()
{
    struct node *root;
    int c, val;
    printf("1:Insert, 2:Search, 3:Exit\n");
    while (1)
    {
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
            printf("Data: \n");
            scanf("%d", &val);
            if (search(root, val)->data == val)
            {
                printf("Found element");
            }
            else
            {
                printf("Not found");
                insert(root, val);
            }
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