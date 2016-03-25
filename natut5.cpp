#include<iostream>
using namespace std;
int main()
{
	float A[1000][1000],x[1000];
	int n;
	cout<<"Enter the number of points:\n";
	cin>>n;
	for(int i=0;i<n;i++)
	{
		cin>>x[i];
		cin>>A[0][i];
	}
	for(int i=1;i<n;i++)
	{
		for(int j=0;j<n-i;j++)
		{
			A[i][j]=(A[i-1][j+1]-A[i-1][j])/(x[i+j]-x[j]);
		}
	}
//
	float P=0,xj,multerm=0;
        
        cout<<"Enter the new x";
        cin>>xj;
        P=A[0][0];
        for(int i=1;i<=n;i++)
        {
                multerm=A[i][0];
                for(int j=0;j<=i-1;j++)
                        multerm*=(xj-x[j]);
                P+=multerm;
        }
        cout<<endl<<P<<endl;
//
	for(int i=0;i<n;i++)
		{
			for(int j=0;j<n;j++)
			cout<<A[j][i]<<" ";
		cout<<endl;
	}
	return 0;
}
/*
        int n;
        cout<<"Enter the number of inputs";
        cin>>n;
        float x[100],f[100][100];
        for(int i=0;i<=n;i++)
                cin>>x[i]>>f[i][0];
        //1float a[100];
/*      for(int i=1;i<=n;i++)
                for(int j=1;j<=i;j++)
                        f[i][j]=(f[i][j-1]-f[i-1][j-1])/(x[i]-x[i-j]);
 */ /*    for(int j=1;j<=n;j++)
        {
                for(int i=j;i<=n;i++)
                {
                        f[i][j]=(f[i][j-1]-f[i-1][j-1])/(x[i]-x[i-j]);

                }
        }
        cout<<f[1][1]<<endl<<f[2][1]<<endl<<f[2][2];
        float P=0,xj,multerm=0;
        /*
        cout<<"Enter the new x";
        cin>>xj;
        P=f[0][0];
        for(int i=1;i<=n;i++)
        {
                multerm=f[i][i];
                for(int j=0;j<=i-1;j++)
                        multerm*=(xj-x[j]);
                P+=multerm;
        }
        cout<<P;
        return 0;
}
~
~*/