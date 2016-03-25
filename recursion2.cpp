
///////////////////recursion practice-5/2/16
#include<iostream.h>
int fibonacci(int N)
{
	if(N==1 || N==2)
		return 1;
	else
	{
		int result=0;
		result+=fibonacci(N-1)+fibonacci(N-2);
		return result;
	}
}
int main()
{
	int N;
	cin>>N;
	cout<<fibonacci(N);
	return 0;
}