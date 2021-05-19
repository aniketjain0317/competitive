#include <stdio.h>
#include <stdlib.h>

typedef struct node
{
	int data;
	struct node* left;
	struct node* right;
	int h;
} Node;

Node* min(Node* root)
{
	Node* x = NULL;
	if(root==NULL)
		return x;
	x = root;
	while(root->left!=NULL)
		root = root->left;
	return root;
}

Node* newNode(int val)
{
	Node* x = (Node *)malloc(sizeof(Node));
	x->data = val;
	x->left = NULL;
	x->right = NULL;
	x->h = 0;
	return x;
}

Node* getParent(Node* root, Node* child)
{
	if(root==NULL)
	return NULL;
	if(child==NULL)
	return NULL;
	Node* parent = NULL;
	while(root!=NULL)
	{
		if(root->left==child || root->right==child)
		return root;
		else if(root->data > child->data)
		root = root->left;
		else
		root = root->right;
	}
	return root;
}

void printTree(Node* root)
{
	if(root==NULL)
		return;
	printTree(root->left);
	printf("Node Value: %d \n",root->data);
	if(root->left!=NULL)
		printf("  Left child: %d\n",root->left->data);
	if(root->right!=NULL)
		printf("  Right child: %d\n",root->right->data);
	printTree(root->right);
}

Node* add(Node* root, int val)
{
	if(root==NULL)
	{
		root = newNode(val);
	 	return root;
	}
	if(root->data > val)
		root->left = add(root->left,val);
	else
		root->right = add(root->right,val);
}

Node* find(Node* root, int val)
{
	if(root==NULL)
		return root;
	if(root->data==val)
		return root;
	else if (root->data > val)
			return find(root->left,val);
	else
		return find(root->right,val);
}

Node* inOrderSuccessor(Node* x, Node* root)
{
	if(x==NULL)
		return NULL;
	if(x->right!=NULL)
		return min(x->right);

	Node* y = getParent(root,x);
	while(y!=NULL && x==y->right)
	{
		x = y;
		y = getParent(root,x);
	}
	return y;
}

Node* delete(Node* root, int val)
{
	Node* f = find(root,val);
	if(f==NULL)
		return root;
	if(f->right==NULL && f->left==NULL)
	{
		Node* parent = getParent(root,f);
		if(parent==NULL)
		{
			free(f);
			return NULL;
		}

		if(parent->left==f)
			parent->left=NULL;
		else if(parent->right==f)
			parent->right = NULL;

		free(f);
		return root;
	}

	else if(f->right==NULL)
	{
		 Node* parent = getParent(root,f);
                if(parent==NULL)
                {
			Node* temp = f->left;
                        free(f);
                        return temp;
                }

                if(parent->left==f)
                        parent->left=f->left;
                else if(parent->right==f)
                        parent->right = f->left;

                free(f);
                return root;
	}

	else if(f->left==NULL)
	{
		Node* parent = getParent(root,f);
                if(parent==NULL)
                {
			Node* temp = f->right;
                        free(f);
                        return temp;
                }

                if(parent->left==f)
                        parent->left=f->right;
                else if(parent->right==f)
                        parent->right = f->right;

                free(f);
                return root;

	}

	else{

		Node* temp = inOrderSuccessor(f,root);
		Node* parent = getParent(root,temp);
		int x = temp->data;
		f->data = x;
		if(parent->left==temp)
		{
			parent->left = delete(temp,x);
			printTree(root);
		}
		else if(parent->right==temp)
		{
			parent->right = delete(temp,x);
		}
		f->data = x;
		return root;
	}
}

int height(Node* root)
{
	if(root==NULL)
		return 0;
	if(root->left==NULL && root->right==NULL)
		return 0;
	int a = height(root->left);
	int b = height(root->right);
	int m = a > b ? a : b;
	root->h = m+1;
	return m+1;
}

Node* rotate(Node* bt, Node* X, Node* Y, Node* Z)
{
	Node* a = NULL;
	Node* b = NULL;
	Node* c = NULL;
	if(X->data < Y->data && X->data < Z->data)
	{
		a = X;
		if(Y->data < Z->data)
			b=Y, c=Z;
		else
			c=Y, b=Z;
	}
	else if(Y->data < X->data && Y->data < Z->data)
	{
		a=Y;
		if(X->data < Z->data)
			b=X, c=Z;
		else
			c=X, b=Y;
	}
	else if(Z->data < X->data && Z->data < Y->data)
	{
		a=Z;
		if(X->data < Y->data)
			b=X, c=Y;
		else
	 		b=Y, c=X;
	}
	Node* T0,* T1,* T2,* T3;
	T0 = a->left;
	if(a->right!=b)
		T1 = a->right;
	else
		T1 = b->left;
	if(b->right!=c)
		T2 = b->right;
	else
		T2 = c->left;
	T3 = c->right;
	Node* parent = getParent(bt, Z);
	if(parent==NULL)
		bt=b;
	else{
	if(parent->left==Z)
		parent->left = b;
	else
		parent->right = b;}
	b->left = a;
	b->right = c;
	a->left = T0;
	a->right = T1;
	c->left = T2;
	c->right = T3;
	return bt;
}

Node* addAVL(Node* root, int val)
{
	root = add(root,val);
	Node* X, *Y, *Z;
	X = find(root,val);
	Node* b = X;
	height(root);
	while(X!=NULL)
	{
		X = b;
		if(X==root)
			break;
		Y = getParent(root,X);
		if(Y==root)
			break;
		Z = getParent(root,Y);
		int x;
		if(Z->left!=NULL && Z->right!=NULL)
			x = abs(height(Z->left) - height(Z->right));
		else if(Z->left!=NULL)
			x = height(Z->left)+1;
		else if(Z->right!=NULL)
			x = height(Z->right)+1;
		else
			x = 0;
		if(x>1)
		{
			if(X->data < Y->data && X->data < Z->data)
				b = Y->data < Z->data ? Y : Z;
			else if(Y->data < Z->data && Y->data < X->data)
				b = Z->data < X->data ? Z : X;
			else if(Z->data < X->data && Z->data < Y->data)
				b = X->data < Y->data ? X : Y;
			root = rotate(root,X,Y,Z);
 		}
		if(b==root)
			break;
		b = getParent(root,b);
	}
	return root;
}

Node* fixDelete(Node* root, Node* temp)
{
	Node* X, *Y, *Z;
	Z = temp;
	Node* b = Z;
	height(root);
	while(Z!=NULL)
	{
		Z = b;
		int x;
		if(Z->left!=NULL && Z->right!=NULL)
			x = abs(height(Z->left) - height(Z->right));
		else if(Z->left!=NULL)
			x = height(Z->left)+1;
		else if(Z->right!=NULL)
			x = height(Z->right)+1;
		else
			x = 0;
		if(x>1)
		{
			if(Z->left==NULL)
				Y = Z->right;
			else if(Z->right==NULL)
				Y = Z->left;
			else if(height(Z->left) > height(Z->right))
				Y = Z->left;
			else
				Y = Z->right;

			if(Y->right==NULL)
				X = Y->left;
			else if(Y->left==NULL)
				X = Y->right;
			else if(height(Y->left) > height(Y->right))
				X = Y->left;
			else
				X = Y->right;

			if(X->data < Y->data && X->data < Z->data)
				b = Y->data < Z->data ? Y : Z;
			else if(Y->data < Z->data && Y->data < X->data)
				b = Z->data < X->data ? Z : X;
			else if(Z->data < X->data && Z->data < Y->data)
				b = X->data < Y->data ? X : Y;
			root = rotate(root,X,Y,Z);
 		}
		if(b==root)
			break;
		b = getParent(root,b);
	}
	return root;
}

Node* deleteAVL(Node* root, int val)
{
	Node* f = find(root,val);
	if(f==NULL)
		return root;
	if(f->right==NULL && f->left==NULL)
	{
		Node* parent = getParent(root,f);
		if(parent==NULL)
		{
			free(f);
			return NULL;
		}
		if(parent->left==f)
			parent->left=NULL;
		else if(parent->right==f)
			parent->right = NULL;
		free(f);
		root = fixDelete(root,parent);
		return root;
	}
	else if(f->right==NULL)
	{
		Node* parent = getParent(root,f);
    if(parent==NULL)
    {
			Node* temp = f->left;
      free(f);
      return temp;
    }
    if(parent->left==f)
    	parent->left=f->left;
    else if(parent->right==f)
    	parent->right = f->left;
		free(f);
		root = fixDelete(root,parent);
    return root;
	}
	else if(f->left==NULL)
	{
		Node* parent = getParent(root,f);
    if(parent==NULL)
    {
			Node* temp = f->right;
      free(f);
      return temp;
      if(parent->left==f)
      	parent->left=f->right;
      else if(parent->right==f)
      	parent->right = f->right;
      free(f);
			root = fixDelete(root,parent);
      return root;
		}
		else
		{
			Node* temp = inOrderSuccessor(f,root);
			Node* parent = getParent(root,temp);
			int x = temp->data;
			f->data = x;
			if(parent->left==temp)
			{
				parent->left = deleteAVL(temp,x);
				printTree(root);
			}
			else if(parent->right==temp)
				parent->right = deleteAVL(temp,x);
			f->data = x;
			root = fixDelete(root,parent);
			return root;
		}
	}
}

int main()
{
	Node* root = NULL;
	printf("\nNew Binary Tree created with 10 numbers\n\n");
	root = add(root,15);
	root = add(root,25);
	root = add(root,10);
	root = add(root,5);
	root = add(root,70);
	root = add(root,30);
	root = add(root,45);
	root = add(root,65);
	root = add(root,75);
	root = add(root,80);
	printTree(root);
	printf("\nDelete Values: 15, 25, 5\n\n");

	root = delete(root,15);
	root = delete(root,25);
	root = delete(root,5);
	printTree(root);

	printf("\nNew AVL search tree created with 8 numbers\n\n");
	Node* AVLroot = NULL;
	AVLroot = addAVL(AVLroot,15);
	AVLroot = addAVL(AVLroot,20);
	AVLroot = addAVL(AVLroot,80);
	AVLroot = addAVL(AVLroot,30);
	AVLroot = addAVL(AVLroot,50);
	AVLroot = addAVL(AVLroot,90);
	AVLroot = addAVL(AVLroot,50);
	AVLroot = addAVL(AVLroot,60);
	AVLroot = addAVL(AVLroot,55);
	printTree(root);

	printf("\nDelete values: 60, 30, 15, 20\n\n");
	AVLroot = deleteAVL(AVLroot,60);
	AVLroot = deleteAVL(AVLroot,30);
	AVLroot = deleteAVL(AVLroot,15);
	AVLroot = deleteAVL(AVLroot,20);

	printf("\n");
	return 0;
}
