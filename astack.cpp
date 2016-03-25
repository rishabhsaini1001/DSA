#include<iostream.h>
using namespace std;
int top=-1;
int flag=1;

void push(int stack[],int max,int item)
{
	if(top<max)
	{
		stack[++top]=item;
		//cout<<top;
	}
	else
	{
		cout<<"\ncannot push into stack, not enough space \n";
	}
}
int pop(int stack[])
{
	flag=1;
	if(top==-1)
			{
				cout<<"\ncannot pop, no element left in stack\n";
				flag=0;
			}	
	else
		top--;
	return stack[top+1];
}
void display(int stack[])
{
	for(int i=top;i>-1;i--)
	{
		cout<<stack[i]<<"\t";
	}	
}
int main()
{
	char P[50],Q[50];
	int stack[50];
	//int top=-1;
	int choice;
	do{
		cout<<"Enter 1 to push\n";
		cout<<"Enter 2 to pop\n";
		cout<<"Enter 3 to display\n";
		cout<<"Enter 0 to exit\ntop "<<top<<endl;
		cin>>choice;
		switch(choice)
		{
			case 1: cout<<"Enter the element to be entered\n";
					int element;
					cin>>element;
					push(stack,50,element);
					break;
			case 2: int item;
					item=pop(stack);
					if(flag==1)
						cout<<item<<endl;
					flag=1;
					break;
			case 3: display(stack);
					break;
			default: if(choice!=0)
						cout<<"Enter an option from 1 to 3";						

		}

	}while(choice!=0);
	return 0;
}