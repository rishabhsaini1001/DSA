#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

int main(){
    int t;
    cin >> t;
    for(int a0 = 0; a0 < t; a0++){
        int n;
        int c;
        int m;
        cin >> n >> c >> m;
        int w,w1,w2,no=0;
        no=w=n/c;
        while(w/m!=0)
            {
            w1=w/m;
            no+=w1;
            w2=w%m;
            w=w1+w2;
        }
       cout<<no<<endl; 
    }
    return 0;
}
