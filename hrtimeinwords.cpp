#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;


int main(){
    int h;
    cin >> h;
    int m;
    cin >> m;
    char unit_number[12][12]={"one","two","three","four","five","six","seven","eight","nine","ten","eleven","twelve"};
    char ten_number[10][12]={"ten","eleven","twelve","thirteen","fourteen","fifteen","sixteen","seventeen","eighteen","ninteen"};

    //char unit_number[10][8]={"twenty","thirty","forty","fifty"};
    //cout<<unit_number[1];
    if(m==0)
    	cout<<unit_number[h-1]<<" o' clock";
    else if(m<30)
    {
    	if(m==1)
    	{
    		cout<<unit_number[m-1]<<" minute past "<<unit_number[h-1];
    	}
    	else if(m>=2 && m<=9)
    	{
    		cout<<unit_number[m-1]<<" minutes past "<<unit_number[h-1];
    	}
    	else if( m==15)
    	{
    		cout<<"quater past "<<unit_number[h-1];   		
    	}
    	else if(m>=10 && m<=19 && m!=15)
    	{
    		cout<<ten_number[m-10]<<" minutes past "<<unit_number[h-1];   		
    	}
    	else if(m==20)
    	{
    		cout<<"twenty"<<" minutes past "<<unit_number[h-1];   		
    	}
    	else if(m>=21 && m<=29)
    	{
    		cout<<"twenty "<<unit_number[m-21]<<" minutes past "<<unit_number[h-1];   		
    	}
    }
    else if (m==30)
    {
    	cout<<"half past "<<unit_number[h-1];
    }
    else if(m>30)
    {
    	m=60-m;
    	if(m==1)
    	{
    		cout<<unit_number[m-1]<<" minute to "<<unit_number[h];
    	}
    	else if(m>=2 && m<=9)
    	{
    		cout<<unit_number[m-1]<<" minutes to "<<unit_number[h];
    	}
    	else if( m==15)
    	{
    		cout<<"quater to "<<unit_number[h];   		
    	}
    	else if(m>=10 && m<=19 && m!=15)
    	{
    		cout<<ten_number[m-10]<<" minutes to "<<unit_number[h];   		
    	}
    	else if(m==20)
    	{
    		cout<<"twenty"<<" minutes to "<<unit_number[h];   		
    	}
    	else if(m>=21 && m<=29)
    	{
    		cout<<"twenty "<<unit_number[m-21]<<" minutes to "<<unit_number[h];   		
    	}
    }
    return 0;
}
