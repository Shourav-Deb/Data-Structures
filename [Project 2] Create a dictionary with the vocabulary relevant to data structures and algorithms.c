/*
    Project 2
   -------------
   Create a dictionary with the vocabulary relevant to data structures and algorithms. You have to use a binary search tree as a key data structure.
   The menu option will be
                                i) Add a new word,
                                ii) Search a word,
                                iii) Delete a word,
                                iv) Print Dictionary,
                                 v) Exit.
   On the exit, each time the system will save all the words with its meaning in a file. The system will create a binary search tree with the words in the file during each session.
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct node                                                                    /// structure define
{
    char word[50];
    char meaning[500];
    struct node *left;
    struct node *right;
} Node;

Node* create_node(char *word, char *meaning)                                         /// new node creation
{
    Node *temp = (Node*) malloc(sizeof(Node));
    strcpy(temp->word, word);
    strcpy(temp->meaning, meaning);
    temp->left = temp->right = NULL;
    return temp;
}

Node* insert(Node *root, char *word, char *meaning)                                /// new word insert
{
    if (root == NULL)
    {
        return create_node(word, meaning);
    }
    if (strcmp(word, root->word) < 0)
        root->left = insert(root->left, word, meaning);
    else if (strcmp(word, root->word) > 0)
        root->right = insert(root->right, word, meaning);

    return root;
}

Node* search(Node *root, char *word)                                               /// search word in BST
{
    if (root == NULL)
        return NULL;

    if (strcmp(word, root->word) == 0)
        return root;

    if (strcmp(word, root->word) < 0)
        search(root->left, word);
    else
        search(root->right, word);
}

Node* min_suc(Node *temp)                                                          /// search lowest ASCII valued word
{

    while (temp->left != NULL)
    {
        temp = temp->left;
    }
    return temp;
}

Node* delete(Node *root, char *word)                                                 /// delete a word
{
    if (root == NULL)
    {
        return root;
    }
    if (strcmp(word, root->word) < 0)
    {
        root->left = delete(root->left, word);
    }
    else if (strcmp(word, root->word) > 0)
    {
        root->right = delete(root->right, word);
    }
    else
    {
        if (root->left == NULL)
        {
            Node *temp = root->right;
            free(root);
            return temp;
        }
        else if (root->right == NULL)
        {
            Node *temp = root->left;
            free(root);
            return temp;
        }
        Node *temp = min_suc(root->right);
        strcpy(root->word, temp->word);
        strcpy(root->meaning, temp->meaning);
        root->right = delete(root->right, temp->word);
    }
    return root;
}

void save_dictionary(Node *root)                                                            /// save file on exit
{
    if (root != NULL)
    {
        save_dictionary(root->left);
        FILE *fp = fopen("dictionary.txt", "a");
        fprintf(fp, "%s:%s\n", root->word, root->meaning);
        fclose(fp);
        save_dictionary(root->right);
    }
}

void inorder_traversal(Node *temp)                                                          /// in-order sort word
{

    if (temp == NULL)
        return;

    inorder_traversal (temp->left);
    printf ("->> %s = %s.\n", temp->word, temp->meaning);
    inorder_traversal (temp->right);
}

Node* build_dictionary(FILE *fp)                                                            /// built tree from file on startup
{
    Node *root = NULL;
    char line[600];
    char *word, *meaning;
    while (fgets(line, sizeof(line), fp) != NULL)
    {
        word = strtok(line, ":");
        meaning = strtok(NULL, "\n");
        root = insert(root, word, meaning);
    }
    fclose(fp);
    return root;
}

int main()
{

    FILE *fp = fopen("dictionary.txt", "r");
    Node *root = build_dictionary(fp);


    char word[50], meaning[50];
    int choice;

    while(1)
    {

        printf("\n# Menu:\n");
        printf("1. Add a new word.\n");
        printf("2. Search a word.\n");
        printf("3. Delete a word.\n");
        printf("4. Print Dictionary.\n");
        printf("5. Exit.\n");
        printf("Choose your option: ");
        scanf("%d", &choice);
        printf("\n");

        if(choice == 1)
        {

            printf("-> Enter word: ");
            scanf("%s", &word);
            fflush(stdin);
            printf("-> Enter meaning: ");
            scanf("%[^\n]s", meaning);
            Node *found = search(root, word);
            if(found == NULL)
            {
                root = insert(root, word, meaning);
                printf("\n\t\t>> Word entered successfully. <<");
            }

            else
                printf("\n\t\t>> Word already exists in the dictionary. <<\n");
        }
        else if(choice == 2)
        {
            printf("-> Enter word: ");
            scanf("%s", word);
            Node *found = search(root, word);
            if (found != NULL)
                printf("->> %s = %s.\n", found->word, found->meaning);
            else
                printf("\n\t\t>> Word not found in the dictionary. <<\n");
        }

        else if(choice == 3)
        {
            printf("-> Enter word: ");
            scanf("%s", word);
            Node *found = search(root, word);
            if (found != NULL)
            {
                root = delete(root, word);
                printf("\n\t\t>> Word deleted successfully. <<");
            }
            else
                printf("\n\t\t>> Word not found in the dictionary. <<\n");


        }

        else if(choice == 4)
        {

            inorder_traversal(root);
            printf("\n\t\t>> All word printed successfully! <<\n\n");
        }

        else if(choice == 5)
        {
            save_dictionary(root);
            printf("\n\t\t>> Updated successfully! <<\n\n");
            break;
        }

        else
            printf("Invalid choice. Please try again.\n");
    }
    return 0;
}
