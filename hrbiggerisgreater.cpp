#include <cmath>
#include <cstdio>
#include <string.h>
#include <iostream>
#include <algorithm>
using namespace std;


int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */   
    int t;
    char s[1000];
    cin>>t;
    for(int k=0;k<t;k++)
    {
        cin>>s;
        int flag=0;
        int n=strlen(s);
        for(int i=n-2;i>=0;i--)
        {
            for(int j=n-1;j>i;j--)
        {
            if(s[j]>s[i])
            {
                char t;
                t=s[j];
                s[j]=s[i];
                s[i]=t;
                flag=1;
                sort(s+i+1,s+n);
                cout<<s<<endl;
                /*for(int m=n-1;m>i;m--)
                    {
                    //if(s[m]<s[m-1])
                    {
                        t=s[m];
                        s[m]=s[m+1];
                        s[m+1]=t;
                
                    }        
                }*/
                break;
            }
        }   
            if(flag==1)
                break;
        }
        if(flag==0)
            cout<<"no answer\n";
    
    }
    return 0;
}
