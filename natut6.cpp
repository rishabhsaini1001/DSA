#include<iostream>
using namespace std;
int main()
{
	float a[1000][1000],b[1000][1000];
	int n;
	cout<<"Enter the number of equations you want to work with:\n";
	cin>>n;
	for(int i=0;i<n;i++)
		for(int j=0;j<=n;j++)
			{
				cin>>a[i][j];
				b[i][j]=a[i][j];
			}	
	for(int i=0;i<n;i++)
		{
			for(int j=0;j<=n;j++)
			{
				cout<<a[i][j]<<" ";
			}
			cout<<endl;
		}			
	for(int i=1;i<n;i++)
	{
		int j=0,k=j;
		while(j<=n)
		{
			if(j<i)
			{
				k=j;
			}
			cout<<k<<endl;
			b[i][j]=a[i][j]-(a[i][k]/a[i-1][k])*a[i-1][j];
			j++;
		}
		///for n^3 complexity
		/*for(int j=0;j<i;j++)
		{
			for(int k=j;k<=n;k++)
			{
				b[i][k]=a[i][k]-(a[i][j]/a[i-1][j])*a[i-1][k];	
				for(int i=0;i<n;i++)
				{
					for(int j=0;j<=n;j++)
					{
						cout<<b[i][j]<<"      ";
					}
					cout<<endl;
				}cout<<endl;		
			}
		}	*/
	}
	for(int i=0;i<n;i++)
		{
			for(int j=0;j<=n;j++)
			{
				cout<<b[i][j]<<"      ";
			}
			cout<<endl;
		}		
	float x[1000];
		x[n]=1;
	for(int i=n-1;i>=0;i--)
	{
		float sum=0;
		sum+=x[n]*b[i][n];
		for(int j=n-1;j>i;j--)
		{
			sum-=x[j]*b[i][j];
		}
		x[i]=sum/b[i][i];
	}
	for(int i=0;i<n;i++)
		cout<<endl<<x[i]<<" ";
	return 0;
}