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
        int i=0,j=0,flag=0;
        while(A[i]!='\0')
            {
            j=0;
            while(B[j]!='\0')
                {
                if(A[i]==B[j])
                    {
                    flag=1;
                    break;
                }
                j++;
            }
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
