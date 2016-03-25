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
        int R;
        int C;
        cin >> R >> C;
        int G[1000][1000];
        for(int i = 0;i < R;i++)
            for(int j=0;j<C;j++)
                cin>>G[i][j];
        ///////////////////////////
        int r;
        int c;
        cin >> r >> c;
        int P[1000][1000];
        for(int i = 0;i < r;i++)
            for(int j=0;j<c;j++)
                cin>>P[i][j];
        ////////////////////////////
        int key=0,key1=0;    
        for(int i=0;i<R-r;i++)
        {
            for(int j=0;j<C-c;j++)
                {
                key1=0;
                if(G[i][j]==P[i][j])
                    {
                   // cout<<i<<j;
                    key++;
                    for(int z=i;z<i+r;z++)
                        for(int x=j;x<j+c;x++)
                        if(G[z][x]==P[z][x])
                        {
                        key++;
                        cout<<z<<x<<endl;
                        if(key==r+c)
                            {
                                key1=1;
                                break;
                            }
                        }
                }
                else
                    key=0;
            }  if(key1==1)
            break;
        } 
        if(key1==1)
            cout<<"YES"<<endl;
        else
            cout<<"NO"<<endl;
            
    }
    return 0;
}
