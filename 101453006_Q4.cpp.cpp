/*
Roll No: 101453006
Name: Rishabh Kumar Saini
Group: COE9
Question: 4
*/
#include<iostream>
#include<math.h>
using namespace std;
int p1[100], p2[100], p3[100], top1 = 0, top2 = 0, top3 = 0;
void pushp1(int a)
{
	if (a != 0)
		p1[top1++] = a;
}
int popp1(void)
{
	if (top1 == 0)
		return 0;
	else
		return p1[--top1];
}
void displayp1(void)
{
	int i;
	cout << "\nTower 1 ->> ";
	if (top1 == 0)
		cout << "Empty";
	else
		for (i = 0; i<top1; i++)
		{
			cout << p1[i];
		}
	cout << "\n";
}
void pushp2(int a)
{
	if (a != 0)
		p2[top2++] = a;
}
int popp2(void)
{
	if (top2 == 0)
		return 0;
	else
		return p2[--top2];
}
void displayp2(void)
{
	int i;
	cout << "Tower 2->> ";
	if (top2 == 0)
		cout << "Empty";
	else
		for (i = 0; i<top2; i++)
		{
			cout << p2[i];
		}
	cout << "\n";
}
void pushp3(int a)
{
	if (a != 0)
		p3[top3++] = a;
}
int popp3(void)
{
	if (top3 == 0)
		return 0;
	else
		return p3[--top3];
}
void displayp3(void)
{
	int i;
	cout << "Tower 3 ->> ";
	if (top3 == 0)
		cout << "Empty";
	else
		for (i = 0; i<top3; i++)
		{
			cout << p3[i];
		}
	cout << "\n";
}
void show(int *A, int n)
{
	for (int i = 0; i < n; i++)
		cout << A[i] << " ";
	cout << endl;
}
void merge(int *A, int p, int q, int r)
{
	int L[100], R[100], n1 = 0, n2 = 0;
	for (int i = p; i < q; i++)
	{
		L[i - p] = A[i];
		n1++;
	}
	for (int i = q; i < r; i++)
	{
		R[i - q] = A[i];
		n2++;
	}
	int i = 0, j = 0, k = p;
	while (i < n1 && j < n2)
	{
		if (L[i] < R[j])
			A[k++] = L[i++];
		else
			A[k++] = R[j++];
	}
	while (i < n1)
		A[k++] = L[i++];
	while (j<n2)
		A[k++] = R[j++];
}
void mergesort(int *A, int p, int r)
{
	if (r > p + 1)
	{
		int q = 0;
		q = (p + r);
		q = q / 2;
		mergesort(A, p, q);
		mergesort(A, q, r);
		merge(A, p, q, r);
	}
	else
	{

	}
}
int partition(int *A, int p, int r)
{
	int i = p - 1, j = p;
	int x = A[r - 1];
	while (j < r - 1)
	{
		if (A[j] < x)
		{
			int temp = A[i + 1];
			A[i + 1] = A[j];
			A[j] = temp;
			i++;
		}
		j++;
	}
	int temp = A[i + 1];
	A[i + 1] = A[r - 1];
	A[r - 1] = temp;
	i++;
	return i;
}
void quicksort_recursive(int *A, int p, int r)
{
	if (r > p)
	{
		int q = partition(A, p, r);
		quicksort_recursive(A, p, q);
		quicksort_recursive(A, q + 1, r);
	}
}
int top = -1;
int flag = 1;
void push(int stack[], int max, int item)
{
	if (top<max)
	{
		stack[++top] = item;
	}
	else
	{
		cout << "\ncannot push into stack, not enough space \n";
	}
}
int pop(int stack[])
{
	flag = 1;
	if (top == -1)
	{
		cout << "\ncannot pop, no element left in stack\n";
		flag = 0;
	}
	else
		top--;
	return stack[top + 1];
}
void display(int stack[])
{
	for (int i = top; i>-1; i--)
	{
		cout << stack[i] << "\t";
	}
}
void quicksort_nonrecursive(int *A, int p, int r)
{
	int stack[50];
	push(stack, 50, p);
	push(stack, 50, r);
	while (top > -1)
	{
		int r1 = pop(stack);
		int p1 = pop(stack);
		int q1 = partition(A, p1, r1);
		if (q1 > p1)
		{
			push(stack, 50, p1);
			push(stack, 50, q1);
		}
		if (q1 + 1 < r1)
		{
			push(stack, 50, q1 + 1);
			push(stack, 50, r1);
		}

	}
}
void towers(int num, char source, char destination, char mid)
{
	if (num == 1)
	{
		cout << "\n Move from tower " << source << " to tower " << destination;
		return;
	}
	towers(num - 1, source, mid, destination);
	cout << "\n Move from tower " << source << " to tower " << destination;
	towers(num - 1, mid, destination, source);
}
int main()
{
	//
	int A[100];
	int n;
	cout << "Welcome to Assignment-1 -> Question-4\nThapar University....";
	cout << "\n created by Rishabh Kumar Saini \n101453006\nCOE\n\n";
	cout << "This program will execute mergesort and quicksort(recursive and non-recursive).\nAlso this program will implement the solution towers of hanoi(recursive and non-recursive)\n";
	cout << "Enter the size of the array you want to work with: \n";
	//
	
	//
	int choice;
	do {
		cout << "Enter 1 to enable merge sort: \n";
		cout << "Enter 2 to enable quick sort(recursive): \n";
		cout << "Enter 3 to enable quick sort(non-recursive): \n";
		cout << "Enter 4 to enable towers of hanoi(recursive): \n";
		cout << "Enter 5 to enable towers of hanoi(non-recursive): \n";
		cout << "Enter 0 to exit: \n";
		cin >> choice;
		switch (choice)
		{
		case 1:cout << "Enter the size of array";
			cin >> n;
			cout << "Enter the array: ";
			for (int i = 0; i < n; i++)
			{
				cin >> A[i];
			}
			mergesort(A, 0, n);
			show(A, n);
			break;
		case 2:cout << "Enter the size of array";
			cin >> n;
			cout << "Enter the array: ";
			for (int i = 0; i < n; i++)
			{
				cin >> A[i];
			}
			quicksort_recursive(A, 0, n);
			show(A, n);
			break;
		case 3:cout << "Enter the size of array"; 
			cin >> n;
			cout << "Enter the array: ";
			for (int i = 0; i < n; i++)
			{
				cin >> A[i];
			}
			quicksort_nonrecursive(A, 0, n);
			show(A, n);
			break;
		case 4: int num;
			cout << "Enter the number of disks : ";
			cin >> num;
			cout << "The sequence of moves involved in the Tower of Hanoi are :\n";
			towers(num, 'A', 'C', 'B');
		case 5:int  i;
			int x, a, b;
			cout << "\nEnter the no. of Disks: ";
			cin >> n;
			for (i = 0; i<n; i++)
			{
				pushp1(n - i);
			}
			x = pow(2, n) - 1;
			displayp1();
			displayp2();
			displayp3();
			for (i = 1; i <= x; i++)
			{
				if (i % 3 == 1)
				{
					a = popp1();
					b = popp3();
					if (a == 0)
					{
						pushp1(b);
					}
					else if (b == 0)
					{
						pushp3(a);
					}
					else if (a>b)
					{
						pushp1(a);
						pushp1(b);
					}
					else
					{
						pushp3(b);
						pushp3(a);
					}
					displayp1();
					displayp2();
					displayp3();
					continue;
				}
				else if (i % 3 == 2)
				{
					a = popp1();
					b = popp2();
					if (a == 0)
					{
						pushp1(b);
					}
					else if (b == 0)
						pushp2(a);
					else if (a>b)
					{
						pushp1(a);
						pushp1(b);
					}
					else
					{
						pushp2(b);
						pushp2(a);
					}
					displayp1();
					displayp2();
					displayp3();
					continue;
				}
				else if (i % 3 == 0)
				{
					a = popp2();
					b = popp3();
					if (a == 0)
					{
						pushp2(b);
					}
					else if (b == 0)
						pushp3(a);
					else if (a>b)
					{
						pushp2(a);
						pushp2(b);
					}
					else
					{
						pushp3(b);
						pushp3(a);
					}
					displayp1();
					displayp2();
					displayp3();
					continue;
				}
			}
			cout << "\nCompleted\nFinal Position\n";
			displayp1();
			displayp2();
			displayp3();
			
		}
	} while (choice != 0);
	return 0;
}