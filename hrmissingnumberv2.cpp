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
        int G[1000];
         for(int i = 0;i < R;i++){        
            G[i]=0;    
        }
        for(int i = 0;i < R;i++){
         
            cin>>G[i];
            //cout<<G[i]<<"\t";
        }
        ///////////////////////////
        int r;
        int c;
        cin >> r >> c;
        int P[1000];
        for(int i = 0;i < r;i++)
                cin>>P[i];
        ////////////////////////////
        int key=0,key1=0;    
        for(int i=0;i<=R-r;i++)
        {
            for(int j=C-1;j>=c-1;j--)
            {
                key1=0;
                cout<<((int)(G[i]/pow(10,j)))%10<<endl;    
                if(((int)(G[i]/pow(10,j)))%10==((int)(P[0]/pow(10,c-1)))%10)
                    {
                        cout<<"match!!! "<<i+1<<j;
                        //cout<<i<<j<<G[i][j]<<P[0][0]<<"\t";
                            key++;
                            if(key==r*c)
                            {
                                key1=1;
                                break;
                            }

                        for(int z=i;z<i+r;z++)
                            { 
                                int k=c-1;
                                for(int x=j;x>=j-c+1;x--)
                                 {   
                                    cout<<"*"<<z<<x<<endl;
                                    //int k=c-1;
                                    cout<<((int)(G[z]/pow(10,x)))%10<<"$";
                                    cout<<((int)(P[z-i]/pow(10,k)))%10<<"!"<<k<<endl;
                                    // k--;
                        if(((int)(G[z]/pow(10,x)))%10==((int)(P[z-i]/pow(10,k)))%10 )
                        {
                        k--;    
                        key++;
                        //cout<<z<<x<<endl;
                        if(key>=r*c)
                            {
                                key1=1;
                                break;
                            }
                        }
                        else
                        {
                            cout<<"hi";
                            break;
                        }
                         if(key>=r*c)
                            {
                                key1=1;
                                break;
                            }

                    }
                    }}
                else
                    key=0;
            }  
            if(key1==1)
                break;
        } 
        if(key1==1)
            cout<<"YES"<<endl;
        else
            cout<<"NO"<<endl;
            
    }
    return 0;
}
