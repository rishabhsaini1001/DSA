#include<iostream>
using namespace std;
int main()
{
	long int a,min,difference=0,flag=0,n,i=0;
	cin>>n;
	while(i++!=n)
	{
		cin>>a;
		if(flag==0)
		{
			min=a;
			flag=1;
			difference=0;
		}
		if(a<min)
			min=a;
		else if(a-min>difference)
			difference=a-min;
	}
    if(difference==0)
        difference=-1;
	cout<<difference;
	return 0;
}