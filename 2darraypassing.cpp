#include<iostream>
using namespace std;
void show(int m,int n,int *A)
{
	for(int i=0;i<m;i++)
		{for (int j=0;j<n;j++)
			cout<<*((A+i*n)+j);
		cout<<endl;}
}
int main()
{
	int A[5][5];
	for(int i=0;i<5;i++)
		for (int j=0;j<5;j++)
			A[i][j]=i+j;
	show(5,5,(int *)A);	
	return 0;
}
