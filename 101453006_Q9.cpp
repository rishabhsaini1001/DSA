/*
Roll No: 101453006
Name: Rishabh Kumar Saini
Group: COE9
Question: 9
*/
#include<iostream>
using namespace std;
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
void maxHeapify(int *A,int n,int i)
{
	int flag=1;
	while(left(i)<n && flag==1)
	{
		flag=0;
		int largest=i;
		if(A[left(i)]>A[i])
			largest=left(i);
		if(right(i)<n && A[right(i)]>A[largest])
			largest=right(i);
		if(largest!=i)
		{
			int temp=A[largest];
			A[largest]=A[i];
			A[i]=temp;
			flag=1;
			i=largest;
		}
	}
}
void buildMaxHeap(int *A,int n)
{
	for(int i=n/2-1;i>=0;i--)
		maxHeapify(A,n,i);
}
void heapsort(int *A,int n)
{
	buildMaxHeap(A,n);
	show(A,n);
	for(int i=n-1;i>=0;i--)
	{
		//swap first and last elements
		int temp=A[0];
		A[0]=A[i];
		A[i]=temp;
		show(A,n);
		//
		maxHeapify(A,i-1,0);
	}
}
int main()
{
	int A[50],n;
	input(A,&n);
	heapsort(A,n);
	show(A,n);
	return 0;	
}