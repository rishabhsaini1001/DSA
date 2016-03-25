#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <string.h>
using namespace std;


int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */   
    int t;
    cin>>t;
    while(t-->0)
    {
    	char s[100000],r[100000];
    	cin>>s;
    	int i=0,len=0;
    	while(s[i++]!='\0')
    		len++;
    	for(int j=0;j<len;j++)
    		r[j]=s[len-1-j];
    	//cout<<s<<r;
    	int flag=0;
    	i=1;
    	//cout<<abs((int)'a'-(int)'b');
    	while(s[i]!='\0')
    	{
    		//cout<<abs((int)s[i]-(int)s[i-1])<<endl;
    		//cout<<abs((int)r[i]-(int)r[i-1])<<endl;
    		if(abs((int)s[i]-(int)s[i-1])==abs((int)r[i]-(int)r[i-1]))
    		{
    			//cout<<"hi ";
    			flag++;
    		}
    		i++;
    	}
    	//cout<<flag;
    	if(flag==len-1)
    		cout<<"Funny"<<endl;
    	else
    		cout<<"Not Funny"<<endl;
    }
    return 0;
}
