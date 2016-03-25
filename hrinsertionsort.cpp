
#include <iostream>
using namespace std;

int main() {
   int n,A[10000],temp,j,i;
    cin>>n;
    for( i=0;i<n;i++)
        cin>>A[i];
    temp=A[n-1];
    j=n-1;
    //cout<<temp<<endl<<j;
    while((j>=0)&&(A[j-1]>temp))
        {
        A[j]=A[j-1];
        j--;
         for(int k=0;k<n;k++)
            cout<<A[k]<<" ";
        cout<<endl;
    }
    A[j]=temp;
    for(int k=0;k<n;k++)
            cout<<A[k]<<" ";
   return 0;
}
