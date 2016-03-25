#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include<string.h>
using namespace std;


int main(){
    char s[81];
    cin >> s;
    int L,r,c;
    L=strlen(s);
    cout<<L;
    r=sqrt(L);
    if(r*r==L)
    {
    	c=r;
    }
    else 
    {
    	c=r+1;
    }
    if(r*c<L)
    	r++;
    cout<<endl<<r<<c<<endl;
    for(int i=0;i<c;i++)
    {
    	for(int j=0;j<r && j*c+i<L ;j++ )
    	{
    		cout<<s[j*c+i];
    		//cout<<j*c+i;
    	}cout<<" ";
    }
    return 0;
}
