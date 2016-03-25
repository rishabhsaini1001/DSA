
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
        char A[100000],B[100000];
        cin>>A>>B;
        int i=0,j=0,flag=0,Aflag=0,Bflag=0;
        char charsetA[26],charsetB[26];
        int k1=0,k2=0,flag1=0,flag2=0;
        charsetA[0]=charsetB[0]='!';
        while(A[i]!='\0' || B[i]!='\0')
            {
            if(A[i]!='\0' && Aflag!=1)
            {
            	flag1=0;
            	for(int j=0;j<k1;j++)
            	{

            		if(charsetA[j]==A[i])
            		{
            			flag1=1;
            			break;
            		}
            	}	
            	if(flag1!=1)
            	{
            		charsetA[k1++]=A[i];
            	}
            }	
            else
            {
            	Aflag=1;
            }
            ////////////////////////////////////////////////
            if(B[i]!='\0' && Bflag!=1)
            {	
            	flag2=0;
            	for(int j=0;j<k2;j++)
            	{	

            		if(charsetB[j]==B[i])
            		{
            			flag2=1;
            			break;
            		}
            	}		
            	if(flag2!=1)
            	{
            		charsetB[k2++]=B[i];
            	}
           	}
           	else
           	{
           		Bflag=1;
           	}
           	for(int j=0;j<k1;j++)
           	{
           		//cout<<" a "<<charsetA[j]<<endl;
           		for(int k=0;k<k2;k++)
           		{
           			//cout<<" b "<<charsetB[k]<<endl;
           			if(charsetA[j]==charsetB[k])
           				{
           					flag=1;
           					break;
           				}	
           		}
           		if(flag==1)
           			break;
           	}
/*
            j=0;
            while(B[j]!='\0')
                {
                if(A[i]==B[j])
                    {
                    flag=1;
                    break;
                }
                j++;
            }*/
            i++;
            if(flag==1)
                {
                break;
            }
        }
        if(flag==1)
            cout<<"YES";
        else
            cout<<"NO";
    }
    
    return 0;
}
