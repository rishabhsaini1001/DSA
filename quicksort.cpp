#include <map>
#include <set>
#include <list>
#include <cmath>
#include <ctime>
#include <deque>
#include <queue>
#include <stack>
#include <bitset>
#include <cstdio>
#include <vector>
#include <cstdlib>
#include <numeric>
#include <sstream>
#include <iostream>
#include <algorithm>
using namespace std;
int main()
    {
    int n,A[1000],pi=0,p,key,i;
    cin>>n;
    for( i=0;i<n;i++)
        {
        cin>>A[i];
    }
    p=A[pi];
    for(int j=1;j<n;j++)
        {
        if(A[j]<p)
            {
            key=A[j];
            for( i=j;i>pi;i--)
                {
                A[i]=A[i-1];
            }
            A[i]=key;
            
        }
    }
    for( i=0;i<n;i++)
        cout<<A[i]<<" ";
    return 0;
}
