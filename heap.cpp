//////////////////heaps..
#include<iostream>
using namespace std;
class heap{
	int *A;
	int B[50];
	int n;
public:
	int left(int i);
	int right(int i);
	void maxHeapify(int i);
	void buildMaxHeap();
	void display();
	void takeArrayInput();
	friend void heapSort(int *A,int n,heap h1);
};
int heap::left(int i)
{
	return 2*i+1;
}
int heap::right(int i)
{
	return 2*i+2;
}
void heap::maxHeapify(int i)
{
	int l=left(i);
	int r=right(i);
	int largest=A[i];
	int flag=0;
	if(l<n && A[l]>A[i])
		largest=A[l];
	if(r<n && A[r]>largest)
		{
			largest=A[r];
			flag=1;
		}
	if(largest!=A[i])
	{
		int j=0;
		if(flag==0)
			j=l;
		else
			j=r;
		int temp=A[j];
		A[j]=A[i];
		A[i]=temp;
		maxHeapify(j);
	}
}
void heap::buildMaxHeap()
{
	for(int i=n/2-1;i>=0;i--)
		{
			maxHeapify(i);
			cout<<"***"<<i<<"\n";
			display();
			cout<<"***\n";
		}	
}
void heap::display()
{
	for(int i=0;i<n;i++)
		cout<<A[i]<<" ";
	cout<<endl;
}
void heap::takeArrayInput()
{
	cout<<"This program will convert an array into a heap:: \n";
	cout<<"Enter the size of the array: \n";
	cin>>n;
	cout<<"Enter the array to be converted into a heap: \n";
	for(int i=0;i<n;i++)
		cin>>B[i];
	A=B;
}
void heapSort(int *A1,int n,heap h1)
{
	h1.A=A1;
	h1.n=n;
	h1.buildMaxHeap();
	for(int i=n-1;i>=1;i--)
	{
		int temp=h1.A[0];
		h1.A[0]=h1.A[i];
		h1.A[i]=temp;
		h1.n--;
		h1.maxHeapify(0);
	}
		A1=h1.A;
}
int main()
{
	int A[10];
	int n;
	cout<<"This program will convert an array into a heap:: \n";
	cout<<"Enter the size of the array: \n";
	cin>>n;
	cout<<"Enter the array to be converted into a heap: \n";
	for(int i=0;i<n;i++)
		cin>>A[i];
	/*
	heap Heap;
	
	Heap.takeArrayInput();
	//Heap.display();
	Heap.buildMaxHeap();
	*/
	heap h1;
	heapSort(A,n,h1);
	for(int i=0;i<n;i++)
		cout<<A[i];
	//Heap.display();
	return 0;
}