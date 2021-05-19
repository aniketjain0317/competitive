#include <stdio.h>
#include <stdlib.h>

typedef struct Node
{
  int key;
  struct Node* parent;
  struct Node* left;
  struct Node* right;
} Node;

void leftRotate(Node* root, Node* x)
{
  Node* y = x->right;

  // MOVING YL TO XR
  x->right = y->left;
  if(y->left!=NULL) y->left->parent = x;


  // CHANGING SON OF XP TO Y
  y->parent = x->parent;
  if(x->parent==NIL) root = y;
  else if(x==x->parent->left) x->parent->left = y;
  else(x==x->parent->right) x->parent->right = y;

  // SWAPPING X AND Y
  x->parent = y;
  y->left = x;
}

// x-a,b  y-x,c
// x-a,y y-b,c
void rightRotate(Node* root, Node* x)
{
  Node* y = x->parent;
  Node* xr = x->right;
  Node* yp = y->parent;

  y->left = xr;
  if(xr!=NULL) xr->parent = y;

  x->parent = yp;
  if(yp==NULL) root = y;
  else if(yp->left = y) yp->left = x;
  else if(yp->right = y) yp->right = x;

  y->parent = x;
  x->right = y;
}
