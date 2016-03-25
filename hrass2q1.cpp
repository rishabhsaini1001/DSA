#include<iostream>
using namespace std;
void show(int *A,int n)
{
	for(int i=0;i<n;i++)
		cout<<A[i]<<" ";
	cout<<endl;
}
int main()
{
	int n,A[100000];
	cin>>n;
	for(int i=0;i<n;i++)
		cin>>A[i];
	int flag=1,k=0;
	int deletel[100000],o=0;
	while(flag==1)
	{
		flag=0;
		int i=0,j=1,o=0;
		while(j<n)
		{
			while(A[j]==0 && j<n)
			{
				j++;
			}
			if(A[i]<A[j] && j<n)
			{
				flag=1;
				//A[j]=0;
				deletel[o++]=j;
				i=j;
			}else
			i=j;
			if(j<=n-1)
			j++;
			
			//show(deletel,o);
			//show(A,n);
		}		
		for(int i=0;i<o;i++)
				A[deletel[i]]=0;
		k++;
		//show(A,n);
		//cout<<k<<endl<<"*************************************\n";
	}
	cout<<k-1;
	return 0;
}