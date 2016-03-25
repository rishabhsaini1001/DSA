#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <string.h>
using namespace std;


int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */   
    char char_string[26];
    char_string[0]='!';
    int i=0,k=0;
    char s[1000];
    gets(s);
    int flag=0;
    //cout<<(char)(s[0]-32);
    //puts(s);
    while(s[i]!='\0')
    {
    	if((s[i]>=65 && s[i]<=65+26)||(s[i]>=97 && s[i]<=97+26))
    	{
    		if(s[i]>=97)
    			s[i]-=32;
    		//cout<<endl<<s[i];
    		flag=0;
    		for(int j=0;j<k;j++)
    		{
    			if(s[i]==char_string[j])
    			{
    				flag=1;
    				//break;
    			}
    		}
    		if(flag==0)
    			char_string[k++]=s[i];
    		//for(int j=0;j<k;j++)
    			//cout<<"\n**"<<char_string[j]<<"**\n";
    	//
    	}
    	i++;
    	//if(flag==1)
    	//	break;
    }
    //if(flag==1)
    //	cout<<"not pangram";
    //cout<<k;
    if(k==26)
    	cout<<"pangram";
    else
    	cout<<"not pangram";
    return 0;
}
