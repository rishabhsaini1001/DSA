#include<iostream>
using namespace std;
void bubblesort(int s[],int n)
	{
		int temp;
		for(int i=0;i<n;i++)
		{
			for(int j=0;j<n-i;j++)
			{
				if(s[j]>s[j+1])
				{
					temp=s[j];
					s[j]=s[j+1];
					s[j+1]=temp;
				}
			}
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
	bubblesort(A,n);
	for(int i=0;i<n;i++)
		cout<<A[i]<<endl;
	return 0;
}