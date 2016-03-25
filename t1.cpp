#include<iostream>
using namespace std;
long long p1[100], p2[100], top1 = -1, top2 = -1;

void push1(int item)
{
	if (top1<100)
	{
		p1[++top1] = item;
	}
	else
	{
		//cout << "\ncannot push into stack, not enough space \n";
	}
}
int pop1()
{
	if (top1 == -1)
		return 0;
	else
		return p1[top1--];
}
void display1()
{
	for (long long i = top1; i>-1; i--)
	{
		cout << p1[i] << "\t";
	}cout << endl;
}
void push2(int item)
{
	if (top2<100)
	{
		p2[++top2] = item;
	}
	else
	{
		//cout << "\ncannot push into stack, not enough space \n";
	}
}
int pop2()
{
	if (top2 == -1)
		return 0;
	else
		return p2[top2--];
}
void display2()
{
	for (int i = top2; i>-1; i--)
	{
		cout << p2[i] << "\t";
	}cout << endl;
}
int main()
{
	//int A[100000];
	long long n;
	cin >> n;
	for (int i = 0; i < n; i++)
	{
		int item;
		cin >> item;
		push1(item);
		//display1();
	}
	int flag = 1,j=0;
while(flag==1)
	{
		flag = 0;
	while (top1 > -1)
	{
		if (top2 == -1)
		{
			int item = pop1();
			push2(item);
			//display1();
			//display2();
		}
		else
		{
			int a = pop1();
			int b = pop2();
			if (b > a)
			{
				push2(a);
				flag = 1;
			}
			else
			{
				push2(b);
				push2(a);
			}
		}
	}
	//display1();
	//display2();
	while (top2 > -1)
	{
		int item = pop2();
		push1(item);
	}
	//display1();
	//display2();
	j++;
}
cout << --j;
	/*int j = n,item1=0;
	while (j-- > -9)
		 item1=pop1();
	display1();
	*/

	/*
	int j=0,flag = 1;
	while (flag == 1)
	{
		flag = 0;
		for (int i = 1; i < n; i++)
		{
			if (A[i] > A[i - 1] && A[i]!=-99)
			{
				A[i] = -99;
				flag = 1;
			}
		}
		j++;
	}
	*/
	//

	//
	//cout << j;
	return 0;
}
