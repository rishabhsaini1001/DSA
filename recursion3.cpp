 ///////////////////recursion practice-5/2/16
#include<iostream.h>
#include<string.h>
char* reversestring(char* N,int a,int b)
{
	//int len=strlen(N),i=len;
	int i=b-1;
	while(i>=a)
	{
		if(N[i]==' ')
		{
			reverse(N);
		}
	}
	return N;
}
int main()
{
	char N[100];
	gets(N);
	cout<<reversestring(N,0,strlen(N));
	return 0;
}