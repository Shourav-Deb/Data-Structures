// C code to copy a binary tree.

#include <stdio.h>
#include <stdlib.h>

struct node
{
    int data;
    struct node* left;
    struct node* right;
};

struct node* newnode(int data)
{
    struct node* temp = (struct node*)malloc(sizeof(struct node));
    temp->data = data;
    temp->left = NULL;
    temp->right = NULL;
    return temp;
}

struct node* copytree(struct node* original)                        /// recursively copying
{
    if (original == NULL)
        return NULL;

    struct node* copy = newnode(original->data);
    copy->left = copytree(original->left);
    copy->right = copytree(original->right);

    return copy;
}

void inorder(struct node* root)
{
    if (root != NULL) {
        inorder(root->left);
        printf("%d ", root->data);
        inorder(root->right);
    }
}

int main()
{
    struct node* original = newnode(2);
    original->left = newnode(1);
    original->right = newnode(3);
    original->right->right = newnode(4);

    printf("---> Original Tree: ");
    inorder(original);

    struct node* copy = copytree(original);

    printf("\n---> Copied Tree: ");
    inorder(copy);

    return 0;
}
