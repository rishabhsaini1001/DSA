#include<iostream>
using namespace std;

int main()
{
	long double n,A[1000000],min=0;
	cin>>n;
	for(int i=0;i<n;i++)
		cin>>A[i];
	for(int i=0;i<n-1;i++)
	{
		for(int j=i+1;j<n;j++)
			if(A[j]-A[i]>min)
				{
					min=A[j]-A[i];
				}	
	}
	if(min!=0)
		cout<<min;
	else
		cout<<-1;
	return 0;
}