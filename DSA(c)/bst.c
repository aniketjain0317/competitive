#include <stdio.h>
#include <stdlib.h>

typedef struct Node
{
  int key;
  struct Node* left;
  struct Node* right;
} Node;

Node* find(Node * root, int key)
{
  if(root==NULL) return root;
  if(root->key==key) return root;
  if(root->key>key) return find(root->left,key);
  if(root->key<key) return find(root->right,key);
}

Node* insert(Node* root, int key)
{
  Node* n = find(root,key);
  if(n==NULL)
  {
    n = (Node*) malloc(sizeof(Node));
    n->key=key;
    n->left=NULL;
    n->right=NULL;
  }
  return n;
}

Node* findMin(Node* root)
{
  if(root==NULL) return root;
  if(root->left!=NULL) return findMin(root->left);
  return NULL;
}

Node* delete(Node* root, int key)
{
  if(root==NULL) return root;
  else if(root->key>key) root->left = delete(root->left,key);
  else if(root->key<key) root->right = delete(root->right,key);
  else
  {
    if(root->left==NULL && root->right==NULL) return NULL;
    else if(root->right==NULL)
    {
      Node* temp = root->left;
      free(root);
      return temp;
    }
    else if(root->left==NULL)
    {
      Node* temp = root->right;
      free(root);
      return temp;
    }
    else
    {
      Node* temp = findMin(root->right);
      root->key = temp->key;
      root->right = delete(root->right,temp->key);
      return root;
    }
  }
  return root;
}

int inorder(Node* root, int arr[], int index)
{
    if(root==NULL) return index;
    index = inorder(root->left,index);
    arr[index++] = root.key;
    index = inorder(root->right, index);
    return index;
}

int main()
{
  Node* root = insert(NULL,5);
}
