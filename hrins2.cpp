
#include <iostream>
using namespace std;

int main() {
   int n,A[10000],temp,j,i,flag=0;
    cin>>n;
    for( i=0;i<n;i++)
        cin>>A[i];
    for(int i=1;i<n;i++)
    {
    temp=A[i];
    j=i;
    flag=0;    
    //cout<<temp<<endl<<j;
    while((j>=0)&&(A[j-1]>temp))
        {
        A[j]=A[j-1];
        j--;
            }    
    A[j]=temp;
    //if(flag==1)   
        {
        for(int k=0;k<n;k++)
            cout<<A[k]<<" ";
            cout<<endl; 
    }
    } 
    //for(int k=0;k<n;k++)
      //      cout<<A[k]<<" ";
   return 0;
}
