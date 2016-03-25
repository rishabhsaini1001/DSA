#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

void shellsort(int A[],int n)
{
	int k=n/2;
	while(k>0)
	{	
		int i=0;
		while(i+k<n)
		{
				for(int j=i;j<n;j+=k)
				{
					int k1=j,temp=A[j];
     				while((A[k1-k]>temp)&&(k1>i))
     				{
     					A[k1]=A[k1-k];
     					k1-=k;
     				}
     				A[k1]=temp;
				}

				i++;
		//for(int l=0;l<n;l++)
		//cout<<l<<" pass with inc."<<k<<"  "<<A[l]<<endl;
		//cout<<endl;
		}
	//	for(int l=0;l<n;l++)
	//	cout<<l<<" pass with inc."<<k<<"  "<<A[l]<<endl;
	
		k/=2;
	}
}
int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */   
    int n,m;
    cin>>n;
    int A[10000],B[10000];
    for(int i=0;i<n;i++)
        cin>>A[i];
    cin>>m;
    for(int i=0;i<m;i++)
        cin>>B[i];
    shellsort(A,n);
    shellsort(B,m);
    /*for(int i=0;i<n;i++)
        cout<<A[i]<<" ";
        cout<<endl;
    for(int i=0;i<m;i++)
        cout<<B[i]<<" ";
        cout<<endl;*/
    int i=0,j=0,n1=0;
    while(i<n && j<m)
        {
           n1++; 
        int key=0;
        if(A[i]!=B[j] && i<n && j<m)
        {cout<<B[j]<<" ";
         while(B[j]==B[++j]);
         //cout<<endl<<B[j];
        }
        else if(A[i]==B[j]){
                while( i<n && j<m && A[i]==B[j])
                {
                    if(i<n)
                    i++;
                    if(j<m)
                    j++;
                    //cout<<"Enter";
                    n1++;
                     if(n1==1000)
                    {   
                        cout<<"inf1";
                        break;
                    }    
                }
                if(i==n)
                    i--;
                if(j==m)
                    j--;
                //cout<<A[i]<<"\t"<<B[j];
                while(i<n && j<m && B[j]==A[i-1])
                    {
                    key=1;
                    n1++;
                     if(j<m)
                    j++;
                    //cout<<"second loop\t";
                    if(n1==1000)
                    {   
                        cout<<"inf1";
                        break;
                    }    
                }
            if(key==1)
                cout<<B[j-1]<<" " ;
        }    if(n1==1000)
                    {   
                        cout<<"inf2";
                        break;
                    }
    }    
    return 0;
}
