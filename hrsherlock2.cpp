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
        long number=0,n5=0,n3=0;
        cin >> n;
        n5=n;
        for(int i=0;i<n;i++)
        	number+=pow(10,i)*5.0;
        //////////testing.....
        cout<<number<<endl<<n5<<endl<<n3<<endl;
        //////////
        int j=0,k=0;
        cout<<k;
        //while((n5/3!=0.0)&&(n3/5!=0.0)&&(k>0))
 		{
 			for(int i=0;i<n;i++)
 			{
 				
 			}
 		}



        	{
        		if(k%2==0)
        		{
        			number-=2*pow(10,j);
        			j++;
        		}	
        		else
        		{	
        		number-=2*pow(10,j);
        		number+=2*pow(10,j-1);
        		}
        		k--;
        	}	
        	cout<<number;
    }
    return 0;
}
