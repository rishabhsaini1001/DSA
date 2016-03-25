#include<iostream.h>
#include<string.h>
using namespace std;
int top=-1;
int flag=1;

void push(int stack[],int max,int item);
void push(char stack[],int max,char item);

int pop(int stack[]);
int pop(char stack[]);

void display(int stack[]);
void display(char stack[]);

void infixtopostfix(char P[]);
void evaluation(char *Q);
void scanexpression(char P[],char Q[],char stack[],int i);
void priority(char Q[], char stack[],int operator1);
void evaluate(char Q,int A[], int estack[]);


int main()
{
	char P[50];
	cout<<"Enter an infix expression";
	gets(P);
	char Q[50];
	infixtopostfix(P);
	return 0;
}
void push(char stack[],int max,char item)
{
	if(top<max)
	{
		stack[++top]=item;
	}
	else
	{
		cout<<"\ncannot push into stack, not enough space \n";
	}
}
void push(int stack[],int max,int item)
{
	if(top<max)
	{
		stack[++top]=item;
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
void display(char stack[])
{
	for(int i=top;i>-1;i--)
	{
		cout<<stack[i]<<"\t";
	}	
}
void display(int stack[])
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
			scanexpression(P,Q,stack,i);
		}	
	i=0;
	cout<<"The postfix notation is "<<Q<<endl;
	evaluation(Q);
}	
	void evaluation(char *Q)
	{
	int A[100];
	int j=0,numberofoperands=0;
	int estack[100];
	while(Q[j]!='\0')
	{
	if(((int)Q[j]>=48 && (int)Q[j]<=57) || ((int)Q[j]>=65 && (int)Q[j]<=90) || ((int)Q[j]>=97 && (int)Q[j]<=122))
		{
			cout<<"Enter the value of "<<Q[j];
			int item;
			cin>>item;
			push(estack,100,item);
			numberofoperands++;
		}
	else if(Q[j]=='+' || Q[j]=='-' || Q[j]=='*' || Q[j]=='/' || Q[j]=='^' || Q[j]=='%')
		{
			evaluate(Q[j],A,estack);
		}	

		j++;
	}
	cout<<"The result of the expression "<<endl;
	display(estack);
}
void scanexpression(char P[],char Q[],char stack[],int i)
{
	if(((int)P[i]>=48 && (int)P[i]<=57) || ((int)P[i]>=65 && (int)P[i]<=90) || ((int)P[i]>=97 && (int)P[i]<=122))
	{
				int j=0;
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
				}
	}
	else if(P[i]=='(')
	{
		push(stack,50,'(');
	}
	else if(P[i]=='+' || P[i]=='-' || P[i]=='*' || P[i]=='/' || P[i]=='^' || P[i]=='%')
	{
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
		}
	}
}
void priority(char Q[], char stack[],int operator1)
{
	char item=pop(stack);
	if(operator1=='^')
	{
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
	}
	else if(operator1=='*' || operator1=='/' || operator1=='%')
		{
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
		}	
	else if(operator1=='+' || operator1=='-')
		{
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
		}		
}
void evaluate(char Q,int A[],int estack[])
{
			int a,b;
			a=pop(estack);
			b=pop(estack);
			switch(Q)
			{
			case '+': push(estack,50,b+a);
						break;
			case '-': push(estack,50,b-a);
						break;
			case '*': push(estack,50,b*a);
						break;
			case '/': push(estack,50,b/a);
						break;
			case '^': push(estack,50,b^a);
						break;	
			case '%': push(estack,50,b%a);
																				
			}
}
