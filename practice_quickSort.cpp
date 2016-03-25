#include<iostream>
using namespace std;
int partition(int *A,int p,int r)
{
	int x=A[r-1];
	int i=p-1,j=p;
	while(j<r)
	{
		if(A[j]<=x)
		{
			i++;
			int temp=A[j];
			A[j]=A[i];
			A[i]=temp;
		}
		j++;
	}
	return i;
}
void quicksort(int *A,int p,int r)
{
	if(r>p)
	{
		int q=partition(A,p,r);
		quicksort(A,p,q);
		quicksort(A,q+1,r);
	}
}
int main()
{
	int n,A[100];
	cout<<"huhuhu";
	cin>>n;
	for(int i=0;i<n;i++)
		cin>>A[i];
	quicksort(A,0,n);	
	for(int i=0;i<n;i++)
		cout<<A[i];
	return 0;
}