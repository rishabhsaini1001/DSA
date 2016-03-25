#include<iostream>
using namespace std;
struct node{
	int data;
	node *left;
	node *right;
	node *parent;
};
class stack{
	int top;
	node *x[50];
public:
	stack();
	void push(node *ptr);
	node* pop();
};
stack::stack()
{
	top=-1;
}
void stack::push(node *ptr)
{
	if(top<50 && ptr!=NULL)
		x[++top]=ptr;
}
node *stack::pop()
{
	if(top>-1)
		return x[top--];
	else
		return NULL;
}
void preorderNR(node **root)
{
	node *ptr=*root;
	stack s;
	while(ptr!=NULL)
	{
		cout<<ptr->data;
		s.push(ptr->right);
		ptr=ptr->left;
		if(ptr==NULL)
			ptr=s.pop();
	}
}
void inorderNR(node **root)
{
	node *ptr=*root;
	stack s;
	while(ptr!=NULL)
	{
		s.push(ptr);
		ptr=ptr->left;
		if(ptr==NULL)
		{
			ptr=s.pop();
			a:
			cout<<ptr->data;
			ptr=ptr->right;
			if(ptr->right==NULL)
				{
					ptr=s.pop();
					goto a;
				}
		}
	}
}
void insertIntoBST(node **root,int data)
{
	node *newnode=new node;
	newnode->data=data;
	newnode->left=NULL;
	newnode->right=NULL;
	newnode->parent=NULL;
	if(*root==NULL)
		*root=newnode;
	else
	{
		node *p=*root;
		node *q=NULL;
		while(p!=NULL)
		{
			q=p;
			if(data<p->data)
				p=p->left;
			else
				p=p->right;
		}
		newnode->parent=q;
		if(data<q->data)
			q->left=newnode;
		else
			q->right=newnode;
	}
}
void preorderR(node **root)
{
	if(*root!=NULL)
	{
		cout<<(*root)->data;
		preorderR(&((*root)->left));
		preorderR(&((*root)->right));
	}
}
void inorderR(node **root)
{
	if(*root!=NULL)
	{
		inorderR(&((*root)->left));
			cout<<(*root)->data;
		inorderR(&((*root)->right));
	}
}
void postorderR(node **root)
{
	if(*root!=NULL)
	{
		postorderR(&((*root)->left));
		postorderR(&((*root)->right));
		cout<<(*root)->data;
	}
}
int main()
{
	node *root=NULL;
	int choice=1,data;
	do{
		cout<<"Enter 1 to insert an element in the BST:\n";
		cout<<"Enter 2 to transverse the BST in a preorder fashion:\n";
		cout<<"Enter 3 to transverse the BST in a inorder fashion:\n";
		cout<<"Enter 4 to transverse the BST in a postorder fashion:\n";
		cout<<"Enter 0 to exit:\n";
		cin>>choice;
		switch(choice)
		{
			case 1:cout<<"Enter the new data:\n";
			cin>>data;
			insertIntoBST(&root,data);
			break; 
			case 2:preorderNR(&root);
			cout<<endl;
			break;
			case 3:inorderNR(&root);
			cout<<endl;
			break;
			case 4:postorderR(&root);
			break;
		}
	}while(choice!=0);
	return 0;
}
