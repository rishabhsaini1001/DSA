#include<iostream>
using namespace std;
void shellsort(int A[],int n)
{
	int k=n/2;
	while(k>0)
	{	
		int i=0;
		while(i+k<n)
		{
				for(int j=i;j<n;j+=k)
				{
					int k1=j,temp=A[j];
     				while((A[k1-k]>temp)&&(k1>i))
     				{
     					A[k1]=A[k1-k];
     					k1-=k;
     				}
     				A[k1]=temp;
				}

				i++;
		for(int l=0;l<n;l++)
		cout<<l<<" pass with inc."<<k<<"  "<<A[l]<<endl;
		cout<<endl;
		}
	//	for(int l=0;l<n;l++)
	//	cout<<l<<" pass with inc."<<k<<"  "<<A[l]<<endl;
	
		k/=2;
	}
}
void insertionsort(int A[],int n)
{

}
int main()
{
	int n,A[100];
	cout<<"Enter the size of the array";
	cin>>n;
	cout<<"Enter the array";
	for(int i=0;i<n;i++)
		cin>>A[i];
	shellsort(A,n);
	for(int i=0;i<n;i++)
		cout<<i<<A[i]<<endl;
	return 0;
}