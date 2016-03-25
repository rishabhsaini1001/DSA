#include<iostream>
using namespace std;
int inversion_count=0;
void show(int *A,int n)
{
	for(int i=0;i<n;i++)
		cout<<A[i]<<" ";
	cout<<endl;
}
void merge(int *A,int p,int q,int r)
{
	int L[500000],R[500000],n1=q-p,n2=r-q;
	for(int i=p;i<q;i++)
		L[i-p]=A[i];
	for(int i=q;i<r;i++)
		R[i-q]=A[i];
	/*cout<<endl;
	show(L,n1);
	show(R,n2);
	cout<<endl;*/
	int i=0,j=0,k=p;
	while(i<n1 && j<n2)
	{
		if(L[i]>R[j])
			{
				A[k++]=R[j++];
				//inversion_count+=(q-i+1);
				//inversion_count++;
				inversion_count+=(n1-i);
				//cout<<"\n***"<<inversion_count<<"***\n";
			}	
		else
			A[k++]=L[i++];
	}
	while(i<n1)
		A[k++]=L[i++];
	while(j<n2)
		A[k++]=R[j++];
	//show(A,6);
}
void mergesort(int *A,int p,int r)
{
	if(r>p+1)
	{
		int q=(p+r)/2;
		mergesort(A,p,q);
		mergesort(A,q,r);
		merge(A,p,q,r);
	}
}
int main()
{
	int n,A[1000000];
	//cout<<"Enter the size of the array: ";
	cin>>n;
	//cout<<"Enter the array";
	for(int i=0;i<n;i++)
		cin>>A[i];
	mergesort(A,0,n);
	//show(A,n);
	cout<<inversion_count;
	//merge(A,0,n/2,n);
	//show(A,n);
	return 0;
}