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
    for(int i=0;i<t;i++)
        {
        long int A[100000],n,count=0;
        cin>>n;
        for(int j=0;j<n;j++)
            {
                cin>>A[j];
            }
        for(int j=0;j<n-1;j++)
            {
            for(int k=j+1;k<n;k++)
                {
                if(A[j]==A[k] && i!=k)
                    count++;
            }
        }
        cout<<count;
        }
    return 0;
}
