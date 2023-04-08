/// Create a C program that constructs a binary search tree (BST) from its given inorder and preorder traversals.


#include <stdio.h>
#include <stdlib.h>

struct node {
  int data;
  struct node* left;
  struct node* right;
};

struct node* newNode(int data)                                                          /// new node creation
{
    struct node* temp = (struct node*)malloc(sizeof(struct node));
    temp->data = data;
    temp->left = NULL;
    temp->right = NULL;
    return temp;
}

struct node* buildTree(int in[], int pre[], int inStart, int inEnd)                 /// recursively constructing
{
  static int preIndex = 0;

  if (inStart > inEnd)
      return NULL;

  struct node* temp = newNode(pre[preIndex++]);

  if (inStart == inEnd)
      return temp;

  int inIndex = search(in, inStart, inEnd, temp->data);

  temp->left = buildTree(in, pre, inStart, inIndex - 1);
  temp->right = buildTree(in, pre, inIndex + 1, inEnd);

  return temp;
}

int search(int arr[], int start, int end, int value)
{
  for (int i = start; i <= end; i++)
  {
    if (arr[i] == value)
        return i;
  }
}

void inorder(struct node* temp) {
  if (temp == NULL)
      return;

  inorder(temp->left);
  printf("%d ", temp->data);
  inorder(temp->right);
}

int main() {
  int in[] = { 1, 2, 3, 4, 5 };
  int pre[] = { 4, 2, 1, 3, 5 };
  int len = sizeof(in) / sizeof(in[0]);

  struct node* root = buildTree(in, pre, 0, len - 1);

  printf("Inorder traversal of the constructed tree is: ");
  inorder(root);

  return 0;
}
