/*
Roll No: 101453006
Name: Rishabh Kumar Saini
Group: COE9
Question: 1
*/
#include<iostream>
using namespace std;
int numberofswaps = 0, numberofcomparisons = 0;
void show(int *A, int n)
{
	for (int i = 0; i < n; i++)
		cout << A[i] << " ";
	cout << endl;
}
void insertionsort(int *A, int n)
{
	int j, temp, flag = 0;
	for (int i = 1; i < n; i++)
	{
		j = i;
		temp = A[j];
		flag = 0;
		while (A[j - 1] > temp && j >= 1)
		{
			A[j] = A[j - 1];
			j--;
			flag = 1;
			numberofswaps++;
			numberofcomparisons++;
		}
		A[j] = temp;
		if (j >= 1)
			numberofcomparisons++;
	}
}
void bubblesort(int *A, int n)
{
	for (int i = 0; i < n - 1; i++)
	{
		for (int j = 0; j < n - i - 1; j++)
		{
			if (A[j] > A[j + 1])
			{
				int temp = A[j];
				A[j] = A[j + 1];
				A[j + 1] = temp;
				numberofswaps++;
			}
			numberofcomparisons++;
		}

	}
}
void selectionsort(int *A, int n)
{
	int pos, item;
	for (int i = 0; i < n - 1; i++)
	{
		item = A[i];
		pos = i;
		int flag = 0;
		for (int j = i + 1; j < n; j++)
		{
			if (item > A[j])
			{
				pos = j;
				item = A[j];
				flag = 1;
			}
			numberofcomparisons++;
		}
		if (flag == 1)
		{
			A[pos] = A[i];
			A[i] = item;
			numberofswaps++;
		}
	}
}
void linearsearch(int item, int A[], int n)
{
	int flag = 0;
	for (int i = 0; i<n; i++)
	{
		numberofcomparisons++;
		if (item == A[i])
		{
			flag = 1;
			cout << endl << "found at position !!!!" << i + 1 << "\n";
			break;
		}
	}
	if (flag == 0)
		cout << "element not found...\n";
}
void binarysearch(int *A, int n, int item)
{
	insertionsort(A, n);
	numberofcomparisons = 0;
	numberofswaps = 0;
	int a = 0, b = n, mid = n / 2;
	while (A[mid] != item && b >= a)
	{
		if (A[mid] > item)
		{
			b = mid - 1;
			mid = (a + b) / 2;
		}
		else
		{
			a = mid + 1;
			mid = (a + b) / 2;
		}
		numberofcomparisons++;
	}
	if (b >= a)
		numberofcomparisons++;
	if (A[mid] == item)
		cout << endl << "found!!!!\n";
	else
		cout << "item not found\n";
}
void shellsort(int A[], int n)
{
	int k = n / 2;
	while (k>0)
	{
		int i = 0;
		while (i + k<n && i<k)
		{
			int flag = 0;
			for (int j = i; j<n; j += k)
			{
				int k1 = j, temp = A[j];
				flag = 0;
				while ((A[k1 - k]>temp) && (k1>i))
				{
					A[k1] = A[k1 - k];
					k1 -= k;
					flag = 1;
					numberofswaps++;
					numberofcomparisons++;
				}
				A[k1] = temp;
				if (k1 > i)
					numberofcomparisons++;
			}
			i++;
		}
		k /= 2;
	}
}

int main()
{
	//A[] will act as the original array whose contents remain intact throughout the do-while loop iterations
	//dummy[] will act as a dummy array which will get modified by the sort and search functions 
	int A[100],dummy[100];
	int n;
	cout << "Welcome to Assignment-1 -> Question-1\nThapar University....";
	cout << "\n created by Rishabh Kumar Saini \n101453006\nCOE\n\n";
	cout << "This program will calculate the number of swaps and comparisons in various sorting and searching techniques:\n";
	cout << "Enter the size of the array you want to work with: ";
	cin >> n;
	cout << "Enter the array: ";
	for (int i = 0; i < n; i++)
	{
		cin >> A[i];
		dummy[i] = A[i];
	}
	int choice;
	do {
		cout << "Enter 1 to enable insertion sort: \n";
		cout << "Enter 2 to enable bubble sort: \n";
		cout << "Enter 3 to enable selection sort: \n";
		cout << "Enter 4 to enable linear search: \n";
		cout << "Enter 5 to enable binary search: \n";
		cout << "Enter 6 to enable shell sort: \n";
		cout << "Enter 0 to exit: \n";
		cin >> choice;
		switch (choice)
		{
		case 1:insertionsort(dummy, n);
			break;
		case 2:bubblesort(dummy, n);
			break;
		case 3:selectionsort(dummy, n);
			break;
		case 4:int item;
			cout << "\nEnter the item to be searched: ";
			cin >> item;
			linearsearch(item, dummy, n);
			break;
		case 5:
			cout << "\nEnter the item to be searched: ";
			cin >> item;
			binarysearch(dummy, n, item);
			break;
		case 6:shellsort(dummy, n);
		}
		if (choice == 0)
			break;
		if(choice==4 )
			cout << "\nthe number of comparisons in the search process were: " << numberofcomparisons<<endl;
		else if (choice == 5)
		{
			cout << "\nthe number of comparisons in the search process were: " << numberofcomparisons << endl;
			//recovering the original array in the integer array dummy[] for next iteration
			for (int i = 0; i < n; i++)
				dummy[i] = A[i];
		}
		else if((choice>=1 && choice<=3)||choice==6)
		{
			cout << "the number of swaps in the sort process were: " << numberofswaps;
			cout << "\nthe number of comparisons in the sort process were: " << numberofcomparisons<<endl;
			//recovering the original array in the integer array dummy[] for next iteration
			for (int i = 0; i < n; i++)
				dummy[i] = A[i];
		}
		//reinitialising count parameters for the next iteration of do-while loop
		numberofcomparisons = 0;
		numberofswaps = 0;
	} while (choice != 0);
	return 0;
}
