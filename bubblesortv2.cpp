#include<iostream>
using namespace std;
void bubblesort(int *A, int n)
{
	for (int i = 0; i < n ; i++)
	{
		for (int j = 0; j < n ; j++)
		{
			if (A[j] > A[j + 1])
			{
				int temp = A[j];
				A[j] = A[j + 1];
				A[j + 1] = temp;
			}
		}

	}
	for (int i = 0; i < n; i++)
		cout << A[i];
}
void show(int *A, int n)
{
	for (int i = 0; i < n; i++)
		cout << A[i];
}
int main()
{
	int A[100];
	int n;
	cout << "Enter the size of the array: ";
	cin >> n;
	cout << "Enter the array: ";
	for (int i = 0; i < n; i++)
		cin >> *(A + i);
	for (int i = 0; i < n; i++)
		cout << A[i];
	cout << endl;
	bubblesort(A,n);
	show(A, n);
	//cin.get();
	//getch();
	return 0;
}