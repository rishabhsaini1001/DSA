/*
Roll No: 101453006
Name: Rishabh Kumar Saini
Group: COE9
Question: 8
*/
#include<iostream>
using namespace std;
struct tnode {
	int data;
	tnode *left;
	tnode *right;
	tnode *parent;
};
void insertintoBST(tnode **root,int data)
{
	tnode *newnode = new tnode;
	newnode->right = NULL;
	newnode->left = NULL;
	newnode->parent = NULL;
	newnode->data = data;
	if (*root == NULL)
		*root = newnode;
	else {
		tnode *parent=NULL;
		tnode *ptr = *root;
		while (ptr != NULL)
		{
			if (ptr ->data>newnode->data)
			{
				parent = ptr;
				ptr = ptr->left;
			}
			else
			{
				parent = ptr;
				ptr = ptr->right;
			}
		}
		if (parent->data > data)
			parent->left = newnode;
		else
			parent->right = newnode;
		newnode->parent = parent;
	}
}
tnode* searchNonRecursive(tnode **root, int data)
{
	if (root != NULL)
	{
		tnode *ptr = *root;
		while (ptr != NULL && ptr->data!=data)
		{
			if (ptr->data > data)
				ptr=ptr->left;
			else
				ptr = ptr->right;
		}
		if (ptr!=NULL) {
			cout << "Element found!!\n";
			return ptr;
		}
		else
		{
			return NULL;
		}
	}
	else {
		return NULL;
	}
}
void searchRecursive(tnode **root,int data)
{
	if (*root != NULL)	
	{
		if ((*root)->data == data)
			cout << "Element found!\n";
		else if (data < (*root)->data)
			searchRecursive(&(*root)->left, data);
		else
			searchRecursive(&(*root)->right, data);
    }
}
int findMaxElement(tnode **root)
{
	if (*root != NULL)
	{
		tnode *ptr = *root;
		while (ptr->right != NULL)
			ptr = ptr->right;
		return ptr->data;
	}
	else
		return -99999;
}
int findMinElement(tnode **root)
{
	if (*root != NULL)
	{
		tnode *ptr = *root;
		while (ptr->left != NULL)
			ptr = ptr->left;
		return ptr->data;
	}
	else
		return 99999;
}
tnode* findSuccessor(tnode **root, int data)
{
	tnode *ptr = searchNonRecursive(root, data);
	if (ptr != NULL)
	{
		if (ptr->right != NULL)
			return ptr->right;
		else
		{
			tnode *x = ptr->parent;
			while ((x != NULL) && (x->right == ptr))
			{
				ptr = x;
				x = ptr->parent;
			}
			return x;
		}
	}
}
tnode* findPredecessor(tnode **root, int data)
{
	tnode *ptr = searchNonRecursive(root, data);
	if (ptr != NULL)
	{
		if (ptr->left != NULL)
			return ptr->left;
		else {
			tnode *x = ptr->parent;
			while ((x != NULL) && (x->left == ptr))
			{
				ptr = x;
				x = ptr->parent;
			}return x;
		}
	}
}
void deleteNode(tnode **root, int value)
{
	tnode *z = searchNonRecursive(root, value);
	tnode *x, *y;
	if (z!= NULL)
	{
		if (z->left == NULL || z->right == NULL)
		{
			y = z;
		}
		else
		{
			y = findSuccessor(root, value);
		}
		if (y->left != NULL)
			x = y->left;
		else
			x = y->right;
		if (x != NULL)
			x->parent = y->parent;
		if (y->parent == NULL)
			*root = x;
		else
		{
			if (y == y->parent->left)
				y->parent->left = x;
			else
				y->parent->right = x;
		}
		if (y != z)
		{
			z->data = y->data;
		}
	}
} 
int main()
{
	tnode *root = NULL;
	int choice = 99;
	int max,min,data;
	tnode *successor, *predecessor;
	do {
		cout << "Enter 1 to add a node\n";
		cout << "Enter 2 to delete a node\n";
		cout << "Enter 3 to search an element in the tree\n";
		cout << "Enter 4 to view the tree\n";
		cout << "Enter 5 to find minimum element in the tree\n";
		cout << "Enter 6 to find maximum element in the tree\n";
		cout << "Enter 7 to find successor of an element in the tree\n";
		cout << "Enter 8 to find predecessor of an element in the tree\n";
		cout << "Enter 0 to exit";
		cin >> choice;
		switch (choice)
		{
		case 1:int newData;
			cout << "Enter the new data";
			cin >> newData;
			insertintoBST(&root,newData);
			break;
		case 2:
			int deleteData;
			cout << "Enter the data to be deleted";
			cin >> deleteData;
			deleteNode(&root,deleteData);
			break;
		case 3:
			cout << "Enter the data to be searched\n";
			int finddata;
			cin >> finddata;
			tnode *ptr;
			ptr=searchNonRecursive(&root, finddata);
			if(ptr!=NULL)
				cout << ptr->data<<endl;
			break;
		case 4:
			//displayTree(root);
			break;
		case 5:
			 min = findMinElement(&root);
			if (min != 99999)
				cout << min << endl;
			break;
		case 6:
			max = findMaxElement(&root);
			if (max != -99999)
				cout << max << endl;
			break;
		case 7:
			cout << "Enter the data whose successor is to be found\n";
			cin >> data;
			successor = findSuccessor(&root, data);
			if(successor!=NULL)
				cout <<"successor is "<< successor->data << endl;
			break;
		case 8:
			cout << "Enter the data whose predecessor is to be found\n";
			cin >> data;
			predecessor = findPredecessor(&root, data);
			if (predecessor != NULL)
				cout << "predecessor is " << predecessor->data << endl;
			break;
		}

	} while (choice != 0);
	return 0;
}