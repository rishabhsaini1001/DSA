#include<iostream>
using namespace std;
///////////////////////____________________________________stack_____________________________________//////////////////////////////////////
class stack{
	int top;
	int stack[50];
public:
	stack();
	void push(int data);
	int pop();
	void display();
	int returntop();
};
 stack::stack()
{
	top=-1;
}
void stack::push(int data)
{
	if(top<50)
	{
		stack[++top]=data;
	}
}
int stack::pop()
{
	if(top>-1)
	{
		return stack[top--];
	}
	else
		return -99999;
}
void stack::display()
{
	for(int i=top;i>-1;i--)
	{
		cout<<stack[i]<<" ";
	}
}
int stack::returntop()
{
	return top;
}
////////////////////////////////////////////////////____________________quicksort_____________________/////////////////////////////////////////
int partition(int *A,int p, int q)
{
	int x=A[q-1];
	int i=p-1,j=p;
	while(j<q)
	{
		if(A[j]<=x)
		{
			i++;
			//swap(A[i],A[j])
			int t=A[i];
			A[i]=A[j];
			A[j]=t;
			//i++;
		}
		j++;
	}
	return i;

}
void quicksort(int *A,int p,int r)
{
	if(r>p)
	{
		int q=partition(A,p,r);
		quicksort(A,p,q);
		quicksort(A,q+1,r);
	}
}
void quicksortNR(int *A,int p,int r)
{
	stack S;
	S.push(p);
	S.push(r);
	cout<<endl;
	S.display();
	cout<<endl<<S.returntop()<<endl;
	int bb=0;
	while(S.returntop()>-1)
	{
		bb++;if(bb>100)break;
		int r1=S.pop();
		int p1=S.pop();

		//cout<<p1<<r1<<endl;
		int q1=partition(A,p1,r1);
		
		S.display();
		cout<<p1<<q1<<r1<<"******"<<endl;
		for(int i=0;i<6;i++)
		cout<<A[i]<<" ";
		cout<<endl;
		if(q1>p1)
		{
			S.push(p1);
			S.push(q1);
		}
		if(r1>q1+1)
		{
			S.push(q1+1);
			S.push(r1);
		}
		//for(int i=0;i<6;i++)
		//cout<<A[i]<<" ";
		//cout<<endl;
	}
}	
/////////////////////////////////_________________________________main()____________________________//////////////////////////////////
int main()
{
	
	int n,A[50];
	cin>>n;
	for(int i=0;i<n;i++)
		cin>>A[i];
	///////////////////////////////shellsort____________________________________________________________________________________________
	/*
	int k=n/2;
	while(k>0)
	{
		for(int i=0;i<n;i+=k)
		{
			int temp=A[i];
			int j=i-k;
			while(j>=0 && A[j]>temp)
			{
				A[j+k]=A[j];
				j-=k;
			}
			A[j+k]=temp;
		}
		k/=2;
		for(int i=0;i<n;i++)
			cout<<A[i]<<" ";
		cout<<endl;

	}*/
	////////////////////////////quicksort_________________________________________________________________________________________________
	quicksortNR(A,0,n);
	//cout<<partition(A,0,n);
	//cout<<endl;
	for(int i=0;i<n;i++)
		cout<<A[i]<<" ";
	
	/*stack_________________________________________________________________________________________________________________________________ 
	stack S;
	int choice;
	do {
		cout << "Enter 1 to push\n";
		cout << "Enter 2 to pop\n";
		cout << "Enter 3 to display\n";
		cout << "Enter 0 to exit\n";
		cin >> choice;
		switch (choice)
		{
		case 1:
			cout << "Enter the new data:\n";
			int data;
			cin >> data;
			S.push(data);
			break;
		case 2:
			int data1;
			data1=S.pop();
			if(data1!=-99999)
				cout << "Element " << data1 << " was successfully deleted\n";
			break;
		case 3:
			S.display();
			break;
		}
	} while (choice != 0);
	*/

	return 0;
}