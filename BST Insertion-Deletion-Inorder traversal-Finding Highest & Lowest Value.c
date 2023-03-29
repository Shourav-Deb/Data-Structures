// Write a code to create a binary tree with insertion, deletion, in-order traversal & finding highest-lowest value function.


#include <stdio.h>
#include <stdlib.h>



struct node                                                                     /// structure organized
{
        int value;
        struct node *left;
        struct node *right;
};

struct node *create_new_node(int item)                                                                   /// new node created with data
{
        struct node *temp = (struct node *)malloc(sizeof(struct node));
        temp->value = item;
        temp->left = temp->right = NULL;
        return temp;
}

struct node *insert_node(struct node *temp, int item)                                                     /// new node insertion
{
        if (temp == NULL)
                return create_new_node(item);

        if (item <= temp->value)
                temp->left = insert_node(temp->left, item);
        else
                temp->right = insert_node(temp->right, item);
        return temp;
}

void inorder_traversal(struct node *root)                                                                       /// in-order sort
{
        if (root == NULL)
                return;
        inorder_traversal(root->left);
        printf("%d ", root->value);
        inorder_traversal(root->right);
}

void highest_lowest(struct node *root)                                                          /// finding lowest-highest value
{
    struct node *temp1, *temp2;
    temp1=temp2=root;

    while (temp1->left != NULL)
                temp1 = temp1->left;

    while (temp2->right != NULL)
                temp2 = temp2->right;
    printf("\n>>  Lowest data is %d & highest data is %d.", temp1->value, temp2->value);
}

struct node *successor(struct node *temp)
{
        while (temp->left != NULL)
                temp = temp->left;
        return temp;
}

struct node *delete_node(struct node *root, int item)                                                           /// delete a data
{
        if (root == NULL)
                return root;
        if (item < root->value)
                root->left = delete_node(root->left, item);
        else if (item > root->value)
                root->right = delete_node(root->right, item);
        else
        {
                if (root->left == NULL)
                {
                        struct node *temp = root->right;
                        return temp;
                }
                else if (root->right == NULL)
                {
                        struct node *temp = root->left;
                        return temp;
                }
                struct node *temp1 = successor(root->right);
                root->value = temp1->value;
                root->right = delete_node(root->right, temp1->value);
        }
        return root;

}

int main()
{

        struct node *tree_root = NULL;

        printf("# Data Printed as binary tree in-order expression:\n\n");

        tree_root = insert_node(tree_root, 36);
        tree_root = insert_node(tree_root, 42);
        tree_root = insert_node(tree_root, 22);
        tree_root = insert_node(tree_root, 18);

        printf("->  After data add:- ");
        inorder_traversal(tree_root);
        highest_lowest(tree_root);

        tree_root = insert_node(tree_root, 26);
        tree_root = insert_node(tree_root, 12);
        tree_root = insert_node(tree_root, 48);
        tree_root = insert_node(tree_root, 32);
        tree_root = insert_node(tree_root, 6);


        printf("\n\n->  After extra data add:- ");
        inorder_traversal(tree_root);
        highest_lowest(tree_root);


        delete_node(tree_root, 12);
        printf("\n\n->  After single child data delete:- ");
        inorder_traversal(tree_root);

        delete_node(tree_root, 6);
        printf("\n\n->  After leaf data delete:- ");
        inorder_traversal(tree_root);

        delete_node(tree_root, 42);
        printf("\n\n->  After 2 child data delete:- ");
        inorder_traversal(tree_root);
        return 0;
}
