#include<iostream>
using namespace std;

int main()
{
	long double n,A[1000000],min=0,max;
	cin>>n;
	for(int i=0;i<n;i++)
		cin>>A[i];
	min=A[0];
	max=A[0];
	for(int i=0;i<n-1;i++)
	{
		if(A[i]<min)
			min=A[i];
		if(A[i]>max)
			max=A[i];
	}
	cout<<min<<max;
	if(min!=0)
		cout<<min;
	else
		cout<<-1;
	return 0;
}