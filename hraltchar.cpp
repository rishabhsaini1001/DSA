#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;


int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */   
    int t;
    cin>>t;
    while(t-->0)
    {
    	char s[100000];
    	cin>>s;
    	int count=0;
    	int i=0,n=0;
    	while(s[i+1]!='\0')
    	{
    		if(s[i]==s[i+1])
    			count++;
    		i++;
    		n++;
    		if(n==1000)
    			break;
    	}
    	cout<<count;
    }
    return 0;
}
