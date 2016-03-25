#include<iostream>
int C[100];
int* mergesort(int A[],int B[],int m,int n)
{
	//int C[100];
	int i=0,j=0,k=0;
	while(i<m && j<n)
	{
		if(A[i]<=B[j])
			C[k++]=A[i++];
		else
			C[k++]=B[j++];
	}
	while(i<m)
		C[k++]=A[i++];
	while(j<n)
		C[k++]=B[j++];
	return C;
	
}
int* merge(int *A,int n)
{
	if(n==1)
		{return A;}
	else
	{
		int B[50], C[50];
		for(int i=0;i<n/2;i++)
			B[i]=A[i];
		int k=0;
		for(int i=n/2;i<n;i++)
			C[k++]=A[i];
		A=mergesort(merge(B,n/2+1),merge(C,n/2),n/2+1,n/2);
		return A;
	}	
} 
int main()
{
	int A[]={1,4,7},B[]={2,3,6,9};
	int *C;
	int D[]={1,7,3,9,2,4,9,4,6,8};
	int *E=merge(D,10);
	//C=mergesort(A,B,3,4);
	for(int i=0;i<7;i++)
		cout<<E[i];
	return 0;
}