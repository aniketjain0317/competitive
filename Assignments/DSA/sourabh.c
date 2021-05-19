#include <stdio.h>
#include <stdlib.h>

typedef struct node{
	int data;
	struct node* left;
	struct node* right;
	int h;
}tree_node;

tree_node* new_node(int val)
{
	tree_node* x = (tree_node *)malloc(sizeof(tree_node));
	x->data = val;
	x->left = NULL;
	x->right = NULL;
	x->h = 0;
	return x;
}

tree_node* min(tree_node* root)
{
	tree_node* x = NULL;
	if(root==NULL)
		return x;
	x = root;
	while(root->left!=NULL)
	{root = root->left;}
	return root;
}

void print_tree(tree_node* root)
{
	if(root==NULL)
		return;
	print_tree(root->left);
	printf("Value of the node : %d \n",root->data);
	if(root->left!=NULL)
	{
		printf(" Left Child: %d \n",root->left->data);
	}
	if(root->right!=NULL)
	{
	printf(" Right Child: %d \n",root->right->data);
	}
	print_tree(root->right);

}

tree_node* add(tree_node* root, int val)
{
	if(root==NULL)
	{root = new_node(val);
	 return root;}

	if(root->data > val)
	{
		root->left = add(root->left,val);
	}
	else{
		root->right = add(root->right,val);
	}

}

tree_node* Get_parent(tree_node* root, tree_node* child)
{
	if(root==NULL)
		return NULL;
	if(child==NULL)
		return NULL;
	tree_node* parent = NULL;
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

tree_node* find(tree_node* root, int val)
{
	if(root==NULL)
		return root;
	if(root->data==val)
		return root;
	else if
		(root->data > val)
			return find(root->left,val);
	else
		return find(root->right,val);
}

tree_node* in_order_successor(tree_node* x, tree_node* root)
{
		if(x==NULL)
			return NULL;
		if(x->right!=NULL)
			return min(x->right);

		tree_node* y = Get_parent(root,x);
		while(y!=NULL && x==y->right)
		{
			x = y;
			y = Get_parent(root,x);
		}


		return y;

}
int height_tree(tree_node* root)
{
	if(root==NULL)
		return 0;
	if(root->left==NULL && root->right==NULL)
		return 0;
	int b = height_tree(root->right);
	int a = height_tree(root->left);

	int m = a > b ? a : b;
	root->h = m+1;
	return m+1;
}

tree_node* delete(tree_node* root, int val)
{
	tree_node* f = find(root,val);
	if(f==NULL)
		return root;
	if(f->right==NULL && f->left==NULL)
	{
		tree_node* parent = Get_parent(root,f);
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
		 tree_node* parent = Get_parent(root,f);
                if(parent==NULL)
                {
				tree_node* temp = f->left;
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
		tree_node* parent = Get_parent(root,f);
                if(parent==NULL)
                {
			tree_node* temp = f->right;
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

		tree_node* temp = in_order_successor(f,root);
		tree_node* parent = Get_parent(root,temp);
		int x = temp->data;
		f->data = x;
		if(parent->left==temp)
		{
			parent->left = delete(temp,x);
			print_tree(root);
		}
		else if(parent->right==temp)
		{
			parent->right = delete(temp,x);
		}
		f->data = x;
		return root;
	}

}

tree_node* rotate(tree_node* bt, tree_node* X, tree_node* Y, tree_node* Z)
{
	tree_node* c = NULL;
	tree_node* b = NULL;
	tree_node* a = NULL;


	if(X->data < Y->data && X->data < Z->data)
		{
			a = X;
			if(Y->data < Z->data)
			{
				b=Y;
				c=Z;
			}
			else{
				c=Y;
				 b=Z;
			}
		}

	else if(Y->data < X->data && Y->data < Z->data)
	{
		a=Y;
		if(X->data < Z->data)
		{
			b=X;;
			c=Z;
		}
		else{
			c=X;
			b=Y;
		}
	}

	else if(Z->data < X->data && Z->data < Y->data)
	{
		a=Z;
		if(X->data < Y->data)
		{
			b=X;
			c=Y;
		}
		else{
			 b=Y;
			c=X;
		}
	}

	tree_node* T0,* T1,* T2,* T3;
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

	tree_node* parent = Get_parent(bt, Z);
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

tree_node* fix_delete(tree_node* root, tree_node* temp)
{
	tree_node* X, *Y, *Z;


		Z = temp;
		tree_node* b = Z;

		height_tree(root);
		while(Z!=NULL)
		{
			Z = b;
			int x;
			if(Z->left!=NULL && Z->right!=NULL)
				x = abs(height_tree(Z->left) - height_tree(Z->right));
			else if(Z->left!=NULL)
				x = height_tree(Z->left)+1;
			else if(Z->right!=NULL)
				x = height_tree(Z->right)+1;
			else
				x = 0;

			if(x>1)
			{

				if(Z->left==NULL)
					Y = Z->right;
				else if(Z->right==NULL)
					Y = Z->left;
				else if(height_tree(Z->left) > height_tree(Z->right))
					Y = Z->left;
				else
					Y = Z->right;

				if(Y->right==NULL)
					X = Y->left;
				else if(Y->left==NULL)
					X = Y->right;
				else if(height_tree(Y->left) > height_tree(Y->right))
					X = Y->left;
				else
					X = Y->right;

				if(X->data < Y->data && X->data < Z->data)
				{
					b = Y->data < Z->data ? Y : Z;
				}
				else if(Y->data < Z->data && Y->data < X->data)
				{
					b = Z->data < X->data ? Z : X;
				}
				else if(Z->data < X->data && Z->data < Y->data)
				{
					b = X->data < Y->data ? X : Y;
				}

				root = rotate(root,X,Y,Z);

				}
				if(b==root)
					break;
				b = Get_parent(root,b);

			}

		return root;
}

tree_node* add_AVL(tree_node* root, int val)
{
	root = add(root,val);
	tree_node* X, *Y, *Z;
	X = find(root,val);
	tree_node* b = X;
	height_tree(root);
	while(X!=NULL)
	{
			X = b;
			if(X==root)
				break;
			Y = Get_parent(root,X);
			if(Y==root)
				break;
			Z = Get_parent(root,Y);
			int x;
			if(Z->left!=NULL && Z->right!=NULL)
				x = abs(height_tree(Z->left) - height_tree(Z->right));
			else if(Z->left!=NULL)
				x = height_tree(Z->left)+1;
			else if(Z->right!=NULL)
				x = height_tree(Z->right)+1;
			else
				x = 0;
			if(x>1)
			{

				if(X->data < Y->data && X->data < Z->data)
				{
					b = Y->data < Z->data ? Y : Z;
				}
				else if(Y->data < Z->data && Y->data < X->data)
				{
					b = Z->data < X->data ? Z : X;
				}
				else if(Z->data < X->data && Z->data < Y->data)
				{
					b = X->data < Y->data ? X : Y;
				}
				root = rotate(root,X,Y,Z);

         	}
				if(b==root)
					break;
				b = Get_parent(root,b);

	}

	return root;
}

tree_node* delete_AVL(tree_node* root, int val)
{
	tree_node* f = find(root,val);

	if(f==NULL)
		return root;
	if(f->right==NULL && f->left==NULL)
	{
		tree_node* parent = Get_parent(root,f);
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
		root = fix_delete(root,parent);

		return root;
	}

	else if(f->right==NULL)
	{
		 tree_node* parent = Get_parent(root,f);
                if(parent==NULL)
                {
			tree_node* temp = f->left;
                        free(f);
                        return temp;
                }

                if(parent->left==f)
                        parent->left=f->left;
                else if(parent->right==f)
                        parent->right = f->left;

                free(f);
		root = fix_delete(root,parent);
                return root;
	}

	else if(f->left==NULL)
	{
		tree_node* parent = Get_parent(root,f);
                if(parent==NULL)
                {
			tree_node* temp = f->right;
                        free(f);
                        return temp;
                }

                if(parent->left==f)
                        parent->left=f->right;
                else if(parent->right==f)
                        parent->right = f->right;

                free(f);
		root = fix_delete(root,parent);
                return root;

	}

	else{

		tree_node* temp = in_order_successor(f,root);

		tree_node* parent = Get_parent(root,temp);
		int x = temp->data;
		f->data = x;
		if(parent->left==temp)
		{
			parent->left = delete_AVL(temp,x);
			print_tree(root);
		}
		else if(parent->right==temp)
		{
			parent->right = delete_AVL(temp,x);
		}
		f->data = x;
		root = fix_delete(root,parent);
		return root;
	}

}

int main()
{
	tree_node* root = NULL;
	printf("\nCreating binary search tree with 8 numbers\n");
	root = add(root,2);
	root = add(root,26);
	root = add(root,11);
	root = add(root,15);
	root = add(root,49);
	root = add(root,32);
	root = add(root,62);
	root = add(root,91);
	print_tree(root);
	printf("\n\nDeleting the values 1,15 and 49\n");

	root = delete(root,11);
	root = delete(root,15);
	root = delete(root,49);
	print_tree(root);


	printf("\n\nCreating an AVL search tree with 6 numbers\n");
	tree_node* AVL_Root = NULL;
	AVL_Root = add_AVL(AVL_Root,1);
	AVL_Root = add_AVL(AVL_Root,18);
	AVL_Root = add_AVL(AVL_Root,78);
	AVL_Root = add_AVL(AVL_Root,37);
	AVL_Root = add_AVL(AVL_Root,50);
	AVL_Root = add_AVL(AVL_Root,86);
	AVL_Root = add_AVL(AVL_Root,42);
	print_tree(root);

	printf("\n\nDeleting the values 1,18 and 37\n");
	AVL_Root = delete_AVL(AVL_Root,1);
	AVL_Root = delete_AVL(AVL_Root,18);
	AVL_Root = delete_AVL(AVL_Root,37);

	print_tree(root);
	printf("\n\n");
	return 0;
}
