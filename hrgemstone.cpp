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
    char commonset[26];
    int k=0,flag=0,n=0;
    commonset[0]='!';
    while(t-->0)
    {
    	char s[100];
    	cin>>s;
    	int i=0;
    	flag=0;
    	while(s[i]!='\0')
    		{
    			flag=0;
    			if(s[i]>=97 && s[i]<=97+26)
    			{
    				cout<<s[i]<<endl;
    				for(int j=0;j<k;j++)
    				{
    					if(s[i]==commonset[j])
    						{
    							flag=1;
    							cout<<"common\n";
    							n++;
    							if(n==10000)
    							break;
    						}	
    				}
    				if(flag==0)
    					commonset[k++]=s[i];
    				n++;
    				if(n==1000)
    					break;
    			
    			}
    			i++;
    			n++;
    				if(n==1000)
    					break;
    		}
    		cout<<k;
    		if(n==1000)
    					break;
    		//for(int j=0;j<k;j++)
    		//	cout<<endl<<"***"<<commonset[j]<<" ";
    		cout<<endl;
    }
    return 0;
}
