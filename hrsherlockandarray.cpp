
#include <iostream.h>
using namespace std;


int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */   
    int t,flag=0;
    long int A[100000],n[100000],sumr=0,suml=0;
    cin>>t;
    for(int i=0;i<t;i++)
    {
    	cin>>n[i];
    	sumr=suml=0;
    	for(int j=0;j<n[i];j++)
    	{
    		cin>>A[j]; 
    		sumr+=A[j];
    	}
    	//cout<<sumr;
    	sumr-=A[0];
    	//cout<<endl<<sumr<<endl<<suml;
    	
    	if(sumr==suml)
    		flag=1;
    	for(int j=1;j<n[i];j++)
    	{
    		sumr-=A[j];
    		suml+=A[j-1];
    		cout<<suml<<"\t"<<sumr<<endl;
    		if(sumr==suml)
    			{
    				flag=1;
    				cout<<j<<suml<<sumr;
    				break;
    			}	
    	}
    	if(flag==0)
    		cout<<"NO"<<endl;
    	else
    		cout<<"YES"<<endl;
    }
    return 0;
}
