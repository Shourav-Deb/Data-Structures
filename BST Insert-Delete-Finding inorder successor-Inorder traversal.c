/// Write a menu driven program. The menu items are i) insert,  ii)delete, iii) finding in-order successor, iv) print in-order traversal and v) exit. Complete the function in the context of binary search tree.


#include <stdio.h>
#include <stdlib.h>


struct node                                             /// structure organized
{
    int data;
    struct node *left;
    struct node *right;
};

struct node *create_new_node(int item)                                                                                 /// new node created with data
{
    struct node *temp = (struct node*)malloc(sizeof(struct node));
    temp->data = item;
    temp->left = temp->right = NULL;
    return temp;
}

struct node *insert_node(struct node *temp, int item)                                                                /// new node insertion
{
    if (temp == NULL)
        return create_new_node (item);

    if (item <= temp->data)
        temp->left = insert_node(temp->left, item);
    else
        temp->right = insert_node(temp->right, item);
    return temp;
}

void inorder_traversal(struct node *temp)                                                                            /// in-order sort
{
    if (temp == NULL)
        return;
    inorder_traversal (temp->left);
    printf ("%d ", temp->data);
    inorder_traversal (temp->right);
}

struct node *search(struct node *temp, int item)                                                                       /// search item in BST
{
    if (temp == NULL)
        return NULL;
    if (item == temp->data)
        return temp;

    if (item < temp->data)
        search(temp->left, item);
    else
        search(temp->right, item);
}

struct node *min_successor(struct node *temp)                                                                       /// search lowest value
{
    while (temp->left != NULL)
        temp = temp->left;
    return temp;
}

int inorder_successor(struct node *temp, int item)                                                               /// search inorder_successor in BST
{

    struct node *current = search(temp, item);

    if (current == NULL)
        return 0;
    if (current->right != NULL) {
        return min_successor(current->right)->data;
    }
    else {
        struct node* suc = NULL;
        struct node* anc = temp;
        while (anc != current) {
            if (current->data < anc->data) {
                suc = anc;
                anc = anc->left;
            }
            else {
                anc = anc->right;
            }
        }
        if(suc == NULL)
        return 0;
        else
        return suc->data;
    }
}

struct node *delete_node(struct node *temp, int item)                                                           /// delete a data
{
    if(temp == NULL)
        return temp;
    if(item < temp->data)
        temp->left = delete_node(temp->left, item);
    else if(item > temp->data)
        temp->right = delete_node(temp->right, item);
    else
    {
        if(temp->left == NULL)
        {
            struct node *return_temp = temp->right;
            return return_temp;
        }
        else if(temp->right == NULL)
        {
            struct node *return_temp = temp->left;
            return return_temp;
        }
        else
        {
        struct node *return_temp = min_successor(temp->right);
        temp->data = return_temp->data;
        temp->right = delete_node(temp->right, return_temp->data);
        }
    }

    return temp;

}


int main ()
{
    struct node *root = NULL;
    int choice, item;

    while (1)
    {

        printf ("1.Insert.\n");
        printf ("2.Delete.\n");
        printf ("3.Find In-order Successor.\n");
        printf ("4.Print In-order Traversal.\n");
        printf ("5.Exit.\n");
        printf ("Choose your option: ");
        scanf ("%d", &choice);


        if (choice == 5)
        {
            break;
        }

        else if (choice == 1)
        {
            printf ("\n-> Enter data to insert: ");
            scanf ("%d", &item);
            root = insert_node (root, item);
            printf ("Data inserted.\n\n");
        }

        else if (choice == 2)
        {
            if (root == NULL)
                printf ("\n-> Tree is empty.\n\n");

            else
            {
                printf ("\n-> Enter data to delete: ");
                scanf ("%d", &item);
                if(search(root, item)!=NULL)
                {
                    root = delete_node(root, item);
                    printf ("Data deleted.\n\n");
                }
                else
                    printf ("Data not found.\n\n");
            }
        }

        else if (choice == 3)
        {
            if (root == NULL)
                printf ("\n-> Tree is empty.\n\n");

            else
            {
                printf ("\n-> Enter data to find in-order successor: ");
                scanf ("%d", &item);

                if(search(root, item)!=NULL)
                {
                    if(inorder_successor(root,item) == 0)
                        printf ("-> %d is the highest value. Thus it has no in-order successor.\n\n", item);
                    else
                        printf ("-> %d is the in-order successor of %d.\n\n", inorder_successor(root,item), item);

                }

                else
                    printf ("Data not found.\n\n");
            }
        }
        else if (choice == 4)
        {
            if (root == NULL)
                printf ("\n-> Tree is empty.\n\n");
            else
            {
                printf ("\n-> In-order Traversal: ");
                inorder_traversal (root);
                printf ("\n\n");
            }
        }
        else
            printf ("\nWrong Input.\n\n");
    }
}
