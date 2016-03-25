
#include <iostream.h>

void shellsort(int A[],int n)
{
	int k=n/2;
	while(k>0)
	{	
		int i=0;
		while(i+k<n)
		{
				for(int j=i;j<n;j+=k)
				{
					int k1=j,temp=A[j];
     				while((A[k1-k]>temp)&&(k1>i))
     				{
     					A[k1]=A[k1-k];
     					k1-=k;
     				}
     				A[k1]=temp;
				}

				i++;
		for(int l=0;l<n;l++)
		cout<<l<<" pass with inc."<<k<<"  "<<A[l]<<endl;
		cout<<endl;
		}
	//	for(int l=0;l<n;l++)
	//	cout<<l<<" pass with inc."<<k<<"  "<<A[l]<<endl;
	
		k/=2;
	}
}
using namespace std;
int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */
	int n,A[1000];
    cin>>n;
    for(int i=0;i<n;i++)
    	cin>>A[i];
    int numberofstickscut=0,min,j,n1;
    while(numberofstickscut!=n)
    {
    	n1=0;
    	for(int i=1;i<n;i++)
    	{
    		if(A[i]!=0)
    		{
    			min=A[i];
    			j=i;
    			break;
    		}	
    	}
    	for(int i=j+1;i<n;i++)
    		if((A[i]<min)&&(A[i]!=0))
    			min=A[i];
    	for(int i=0;i<n;i++)
    		if(A[i]!=0)
    			{
    				n1++;
    				A[i]-=min;
    				if(A[i]==0)
    					numberofstickscut++;
    			}		
    	cout<<n1;				
    }
    return 0;
}