#include<iostream>
using namespace std;
int main()
{
	int n;
	float a[10][10],b[10],x[10][10];
	for(int i=0;i<n;i++)
			{
				for(int j=0;j<n;j++)
					{
						x[i][j]=0;
					}	
					
			}		
	cout<<"Enter the number of variables you want to work with: \n";
	cin>>n;
	cout<<"Enter the coefficients of the equations: \n";
	for(int i=0;i<n;i++)
	{
		for(int j=0;j<=n;j++)
		{
			if(j==n)
			{
				//cout<<"b["<<i<<"]: ";
				cin>>b[i];
			}
			else
			{
				//cout<<"a["<<i<<"]"<<"["<<j<<"]: ";
				cin>>a[i][j];
			}
		}
	}
	cout<<"Enter the initial point: ";
	for(int i=0;i<n;i++)
		cin>>x[0][i];
	int k=1;
	int trial=0,firstrun=1;
	float condition=1;
	do{
		trial++;
		//////////////////////////////////copying x[k][] to xo[]
		float xo[10];
		for(int i=0;i<n;i++)
			xo[i]=x[k-1][i];
		/////////////////////////////////for a complete transversal of all the equations
		for(int i=0;i<n;i++)
		{
			x[k][i]=b[i];
			////////////////////////////////////transversing within the equations
			for(int j=0;j<n;j++)
			{
				if(j!=i)
				{
					x[k][i]-=a[i][j]*xo[j];
				}
			}
			////////////////////////////////updating the new x[][]
			x[k][i]/=a[i][i];
			xo[i]=x[k][i];
		}
		for(int i=0;i<=k;i++)
			{
				for(int j=0;j<n;j++)
					{
						cout<<x[i][j]<<" ";
					}	
					cout<<endl;
			}		
		
		cout<<"***\n";
		/////////////////////////checking the ending condition.............
		double nummax=(x[k][0]-x[k-1][0]),denmax=x[k][0];
		for(int i=1;i<=n;i++)
		{
			if(x[k][i]-x[k-1][i]>nummax)
				nummax=x[k][i]-x[k-1][i];
			if(x[k][i]>denmax)
				denmax=x[k][i];
		} 
		condition=1;
		if(nummax/denmax<0.1)
			condition=0;
		cout<<"__________"<<(nummax/denmax)<<endl;
		k++;
		//////////////////////////////
		firstrun++;
		if(firstrun==3)
			firstrun=0;
		//////////////////////////////
	}while(condition==1 || firstrun!=0);
	return 0;
}