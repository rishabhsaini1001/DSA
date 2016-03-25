#include<iostream>
using namespace std;
void merge(int *A,int p,int q,int r)
{
	int L[50],R[50],n1=0,n2=0;
	for(int i=p;i<q;i++)
	{
		L[i-p]=A[i];
		n1++;
	}
	for(int i=q;i<r;i++)
	{
		R[i-q]=A[i];
		n2++;
	}
	int i=0,j=0,k=p;
	while(i<n1 && j<n2)
	{
		if(L[i]<R[j])
		{
			A[k++]=L[i++];
		}
		else
		{
			A[k++]=R[j++];
		}
	}
	while(i<n1)
	{
		A[k++]=L[i++];
	}
	while(j<n2)
	{
		A[k++]=R[j++];
	}
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
	int n,A[100];
	cout<<"huhuhu";
	cin>>n;
	for(int i=0;i<n;i++)
		cin>>A[i];
	mergesort(A,0,n);	
	for(int i=0;i<n;i++)
		cout<<A[i];
	return 0;
}