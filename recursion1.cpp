///////////////////recursion practice-5/2/16
#include<iostream.h>
int sumofNnaturalnumbers(int N)
{
	if(N==1)
		return 1;
	else
	{
		int result=N;
		result+=sumofNnaturalnumbers(N-1);
		return result;
	}
}
int main()
{
	int N;
	cin>>N;
	cout<<sumofNnaturalnumbers(N);
	return 0;
}