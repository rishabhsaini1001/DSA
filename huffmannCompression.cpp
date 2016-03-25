#include<iostream>
using namespace std;
struct node{
	int data;
	node *left;
	node *right;
};
void inputData(node *A[10],int *n)
{
	cin>>*n;
	for(int i=0;i<*n;i++)
		{
			A[i]=new node;
			cin>>A[i]->data;
			A[i]->left=NULL;
			A[i]->right=NULL;
		}	
}
void showData(node* A[10],int n)
{
	for(int i=0;i<n;i++)
		cout<<A[i]->data;
}
void input(int* A,int *n)
{
	cin>>*n;
	for(int i=0;i<*n;i++)
		cin>>A[i];
}
void show(int* A,int n)
{
	//cin>>n;
	for(int i=0;i<n;i++)
		cout<<A[i]<<" ";
	cout<<endl;
}
int left(int i)       	
{
	return 2*i+1;
}
int right(int i)
{
	return 2*i+2;
}
int parent(int i)
{
	return (i-1)/2;
}
void minHeapify(node *A[],int n,int i)
{
	int flag=1;
	while(left(i)<n && flag==1)
	{
		flag=0;
		int largest=i;
		if(A[left(i)]->data<A[i]->data)
			largest=left(i);
		if(right(i)<n && A[right(i)]->data<A[largest]->data)
			largest=right(i);
		if(largest!=i)
		{
			int temp=A[largest]->data;
			A[largest]->data=A[i]->data;
			A[i]->data=temp;
			flag=1;
			i=largest;
		}
	}
}
void buildMinHeap(node *A[],int n)
{
	for(int i=n/2-1;i>=0;i--)
		minHeapify(A,n,i);
}
void insertIntoPriorityQueue(node *A[],int *n,node *a)
{
	A[*n++]=a;
	int i=*n;
	while(i>0 && A[parent(i)]->data>A[i]->data)
	{
		node *temp=A[parent(i)];
		A[parent(i)]=A[i];
		A[i]=temp;
		i=parent(i);
	}
}
int main()
{
	node *A[10];
	int n;
	///*
	cin>>n;
	for(int i=0;i<n;i++)
		{
			A[i]=new node;
			cin>>A[i]->data;
			A[i]->left=A[i]->right=NULL;
		}	
	//*/
	//inputData(A,&n);
	buildMinHeap(A,n);
	//createEncodingTree(A)
	showData(A,n);
	node *a=new node;
	a->data=2;
	a->left=a->right=NULL;
	insertIntoPriorityQueue(A,&n,a);
	showData(A,n);
	return 0;
}