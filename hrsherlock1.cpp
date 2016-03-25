#include<iostream.h>
#include<math.h>
int main()
{
	int n,A[100],B[100],N[100];
	cin>>n;
	for(int i=0;i<n;i++)
		{cin>>A[i]>>B[i];
			N[i]=0;
				for(int k=1;k<B[i];k++)
				{
					if((k*k>=A[i])&&(k*k<=sqrt(B[i])))
						N[i]++;
				}
			
		}
		for(int i=0;i<n;i++)
			cout<<N[i]<<endl;
	return 0;
}