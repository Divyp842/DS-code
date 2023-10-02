#include <stdio.h>
#include <stdlib.h>

struct node
{
    int data;
    struct node *right;
    struct node *left;
};

struct node *createBST(struct node *, int);
void Inorder(struct node *);
void preorder(struct node *);
void postorder(struct node *);

int main()
{
    struct node *root = NULL;
    int choice, item, n, i;

    do
    {
        printf("\nBinary Search Tree Operations\n");
        printf("\n1.Creation of BST \n2. Traverse in Inorder \n3.Traverse in Preorder \n4. Traverse in Postorder\n5.EXIT");
        scanf("%d", &choice);
        switch (choice)
        {
        case 1:
            root = NULL;
            printf("\nBST for How Many Nodes?");
            scanf("%d", &n);
            for (i = 1; i <= n; i++)
            {
                printf("\n Enter data for node %d:", i);
                scanf("%d", &item);
                root = createBST(root, item);
            }
            printf("\n BST with %d nodes is ready to use!!", n);
            break;

        case 2:
            printf("\n BST Traversal in INORDER");
            Inorder(root);
            break;
        case 3:
            printf("\n BST Traversal in PREORDER");
            preorder(root);
            break;
        case 4:
            printf("\n BST Traversal in POSTORDER");
            postorder(root);
            break;
        case 5:
            printf("\n Terminating");
            break;
        default:
            printf("\n Invalid Option!!! Try Again!!\n\n");
            break;
        }
    } while (choice != 5);
}

struct node *createBST(struct node *root, int item)
{
    if (root == NULL)
    {
        root = (struct node *)malloc(sizeof(struct node));
        root->left = root->right = NULL;
        root->data = item;
        return root;
    }
    else
    {
        if (item < root->data)
            root->left = createBST(root->left, item);
        else if (item > root->data)
            root->right = createBST(root->right, item);
        else
            printf("Duplicate Element!!Not Allowed!!!");
        return (root);
    }
}

void Inorder(struct node *root)
{
    if (root != NULL)
    {
        Inorder(root->left);
        printf("%d", root->data);
        Inorder(root->right);
    }
}

void preorder(struct node *root)
{
    if (root != NULL)
    {
        printf("%d", root->data);
       preorder(root->left);
        preorder(root->right);
    }
}

void postorder(struct node *root)
{
    if (root != NULL)
    {
        postorder(root->left);
        postorder(root->right);
        printf("%d", root->data);
    }
}