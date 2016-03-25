#include<iostream.h>
#include<string.h>
using namespace std;
int top=-1;
int flag=1;

void push(int stack[],int max,int item);
int pop(int stack[]);
void display(int stack[]);
void infixtopostfix(char P[]);
void scanexpression(char P[],char Q[],char stack[],int i);
void priority(char Q[], char stack[],int operator1);
int evaluate(char Q[],int A[]);


int main()
{
	char P[50];
	//int stack[50];
	//int top=-1;
	//int choice;
	cout<<"Enter an infix expression";
	gets(P);
	char Q[50];
	infixtopostfix(P);
	//cout<<"\nThe equivalent postfix expression is "<<Q;

	/*do{
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

	}while(choice!=0);*/
	return 0;
}
void push(char stack[],int max,char item)
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
int pop(char stack[])
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
void display(char stack[])
{
	for(int i=top;i>-1;i--)
	{
		cout<<stack[i]<<"\t";
	}	
}
void infixtopostfix(char P[])
{
	char Q[50];
	Q[0]='\0';
	char stack[50];
	int i=0,len=0;
	while(P[i]!='\0'){
		i++;
		len++;
	}
	P[len]=')';
	P[len+1]='\0';
	push(stack,50,'(');
	for(int i=0;i<len+1;i++)
		{
			//cout<<P[i]<<endl;
			scanexpression(P,Q,stack,i);
			//scanexpression(P,Q,1);


		}	
	cout<<"P "<<P<<endl;
	i=0;
	//while(Q[i]!='\0')
	cout<<"Q "<<Q<<endl;
	//cout<<"stack ";
	//display(stack);
	///////////////////**********************************************************************************/////////////////////////////////////////
	//////////////////////***************************************************************************/////////////////////////////////////////////
	////////////////////////***********************************************************************///////////////////////////////////////////////
	/////////////////////////////////////////////////////////////////////////////////////////////////////////////evaluating the postfix expression
	int A[100];
	int j=0,numberofoperands=0;
	while(P[j]!='\0')
	{
		//j++;
		//if(((int)Q[i]>=65 && (int)Q[i]<=90) || ((int)Q[i]>=97 && (int)Q[i]<=122))
	if(((int)P[j]>=48 && (int)P[j]<=57) || ((int)P[j]>=65 && (int)P[j]<=90) || ((int)P[j]>=97 && (int)P[j]<=122))
		{
			cout<<"Enter the value of "<<P[j];
			//int item;
			//cin>>item;
			cin>>A[numberofoperands++];
		}
		j++;
	}
	cout<<"numberofoperands:  "<<numberofoperands<<" "<<j;
	for(int k=0;k<numberofoperands;k++)
		cout<<endl<<A[k]<<endl;
	//int result=evaluate(Q,A);

}
void scanexpression(char P[],char Q[],char stack[],int i)
{
	if(((int)P[i]>=48 && (int)P[i]<=57) || ((int)P[i]>=65 && (int)P[i]<=90) || ((int)P[i]>=97 && (int)P[i]<=122))
	{
				int j=0;
				cout<<P[i]<<endl;

				if(Q[0]=='\0')
				{
					Q[0]=P[i];
					Q[1]='\0';
				}	
				else
				{
					while(Q[j]!='\0')
				{
					j++;
				}
					Q[j]=P[i];
					Q[j+1]='\0';
					cout<<"****"<<Q<<endl;
				}
	}
	else if(P[i]=='(')
	{
		push(stack,50,'(');
	}
	else if(P[i]=='+' || P[i]=='-' || P[i]=='*' || P[i]=='/' || P[i]=='^' || P[i]=='%')
	{
		//cout<<P[i];
		priority(Q,stack,P[i]);

	}
	else if(P[i]==')')
	{
		char item=pop(stack);
		int k=0;
		while(item!='(' )
		{
			int j=0;
			if(Q[0]=='\0')
				{
					Q[0]=item;
					Q[1]='\0';
				}	
				else
				{
					while(Q[j]!='\0')
				{
					j++;
				}
					Q[j]=item;
					Q[j+1]='\0';
				}	
			item=pop(stack);
			cout<<"\nending"<<k<<" "<<item<<endl;
		}
	}
}
void priority(char Q[], char stack[],int operator1)
{
	char item=pop(stack);
	cout<<"hi";
	if(operator1=='^')
	{
		cout<<"hii";
		while(item=='^')
		{
			int j=0;
			if(Q[0]=='\0')
				{
					Q[0]=item;
					Q[1]='\0';
				}	
				else
				{
					while(Q[j]!='\0')
				{
					j++;
				}
					Q[j]=item;
					Q[j+1]='\0';
				}
			item= pop(stack);	
		}
		push(stack,50,item);
		push(stack,50,operator1);
		display(stack);
	}
	else if(operator1=='*' || operator1=='/' || operator1=='%')
		{
			cout<<endl<<"\nhiiiiii\n";
			//char item=pop(stack);
			int j=0;
			while(item=='^' || item=='*' ||item=='/' || item=='%')
			{
			int j=0;
			if(Q[0]=='\0')
				{
					Q[0]=item;
					Q[1]='\0';
				}	
				else
				{
					while(Q[j]!='\0')
				{
					j++;
				}
					Q[j]=item;
					Q[j+1]='\0';
				}
			item= pop(stack);	
		}
		push(stack,50,item);
		push(stack,50,operator1);
		display(stack);

		}	
	else if(operator1=='+' || operator1=='-')
		{
			cout<<endl<<"\nhiiiiii\n";
			//char item=pop(stack);
			int j=0;
			while(item=='^' || item=='*' ||item=='/' ||item=='-'||item=='+' || item=='%')
			{
			int j=0;
			if(Q[0]=='\0')
				{
					Q[0]=item;
					Q[1]='\0';
				}	
				else
				{
					while(Q[j]!='\0')
				{
					j++;
				}
					Q[j]=item;
					Q[j+1]='\0';
				}
			item= pop(stack);	
		}
		push(stack,50,item);
		push(stack,50,operator1);
		display(stack);

		}		
}
int evaluate(char Q[],int A[])
{
	int j=0;
	while(Q[j]!=0)
	{
		if(((int)Q[j]>=65 && (int)Q[j]<=90) || ((int)Q[j]>=97 && (int)Q[j]<=122))
		{

		}
	}
}
