#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

int main(){
    int n;
    
    cin >> n;
    char s[100];
    cin >> s;
    int k;
    cin >> k;
    while(k>26)
    	k-=26;
    int k1,k2;
    for(int i=0;i<n;i++)
    {
    	if((s[i]<=90)&&(s[i]>=65))
    	{
    		if(s[i]+k<=90)
    			s[i]+=k;
    		else
    		{
    			k1=90-s[i];
    			s[i]=64+k-k1;
    		}
    	}
    	if((s[i]<=122)&&(s[i]>=97))
    	{
    		if(s[i]+k<=122)
    			s[i]+=k;
    		else
    		{
    			k1=122-s[i];
    			s[i]=96+k-k1;
    		}
    	}
    }
    cout<<s;
    /*/////////////////
    char a='Y';
    int k1,k=2;
    k1=90-a;
    a=64+k-k1;
    cout<<a;
*/
    return 0;
}
