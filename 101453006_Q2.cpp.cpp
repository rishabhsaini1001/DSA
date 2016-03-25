/*
Roll No: 101453006
Name: Rishabh Kumar Saini
Group: COE9
Question: 2
*/
#include<iostream>
#include<string>
using namespace std;
struct student {
	int regno;
	char name[30];
	char branch[5];
	float cgpa;
};
void stringcopy(char *A,char *B)
{
	int i;
	for ( i = 0; i < strlen(B); i++)
		A[i] = B[i];
	A[i] = '\0';

}
void linearsearch(int regno1, student s[], int n)
{
	int flag = 0;
	for (int i = 0; i<n; i++)
	{
		if (regno1 == s[i].regno)
		{
			flag = 1;
			cout << endl << "found!!!!\n" << s[i].regno << "\n" << s[i].name << "\n" << s[i].branch << "\n" << s[i].cgpa << "\n";
		}
	}
	if (flag == 0)
		cout << "element not found...\n";
}
void regno_bubblesort(student s[], int n)
{
	int tregno;
	char tname[30], tbranch[5];
	float tcgpa;
	for (int i = 0; i<n; i++)
	{
		for (int j = 0; j<n-1; j++)
		{
			if (s[j].regno>s[j + 1].regno)
			{
				tregno = s[j].regno;
				stringcopy(tname, s[j].name);
				stringcopy(tbranch, s[j].branch);
				tcgpa = s[j].cgpa;
				/////////////////////////////
				s[j].regno = s[j + 1].regno;
				stringcopy(s[j].name, s[j + 1].name);
				stringcopy(s[j].branch, s[j + 1].branch);
				s[j].cgpa = s[j + 1].cgpa;
				/////////////////////////////
				s[j + 1].regno = tregno;
				stringcopy(s[j + 1].name, tname);
				stringcopy(s[j + 1].branch, tbranch);
				s[j + 1].cgpa = tcgpa;
			}
		}
	}
	for (int i = 0; i<n; i++)
	{
		cout << endl << "regno ";
		cout << s[i].regno << endl;
		cout << "name ";
		cout << s[i].name << endl;
		cout << "branch ";
		cout << s[i].branch << endl;
		cout << "cgpa ";
		cout << s[i].cgpa << endl << endl;
	}
}
void binarysearch(student *A, int n, int item)
{
	cout << "searching in...\n";
	regno_bubblesort(A, n);
	int a = 0, b = n, mid = n / 2;
	while (A[mid].regno != item && b >= a)
	{
		if (A[mid].regno > item)
		{
			b = mid - 1;
			mid = (a + b) / 2;
		}
		else
		{
			a = mid + 1;
			mid = (a + b) / 2;
		}
	}
	if (A[mid].regno == item)
		cout << endl << "found!!!!\n" << A[mid].regno << "\n" << A[mid].name << "\n" << A[mid].branch << "\n" << A[mid].cgpa << "\n";

	else
		cout << "item not found\n";
}
void cgpa_insertionsort(student *A,int n)
{
		int j, treg;
		char tname[100], tbranch[100];
		float temp;
		for (int i = 1; i < n; i++)
		{
			j = i;
			treg = A[j].regno;
			stringcopy(tname, A[j].name);
			stringcopy(tbranch, A[j].branch);
			temp = A[j].cgpa;
			while (A[j - 1].cgpa < temp && j >= 1)
			{
				A[j].cgpa = A[j-1].cgpa;
				stringcopy(A[j].name, A[j-1].name);
				stringcopy(A[j].branch, A[j-1].branch);
				A[j].regno = A[j-1].regno;
				j--;
			}
			
			A[j].regno = treg;
			stringcopy(A[j ].name, tname);
			stringcopy(A[j ].branch, tbranch);
			A[j ].cgpa = temp;
		}
		for (int i = 0; i<n; i++)
		{
			cout << endl << "regno ";
			cout << A[i].regno << endl;
			cout << "name ";
			cout << A[i].name << endl;
			cout << "branch ";
			cout << A[i].branch << endl;
			cout << "cgpa ";
			cout << A[i].cgpa << endl << endl;
		}
}
int main()
{
	student s[50];
	int n;
	cout << "Welcome to Assignment-1 -> Question-2\nThapar University....";
	cout << "\n created by Rishabh Kumar Saini \n101453006\nCOE\n\n";
	cout << "This program will manage a list of maximum 50 students: \n";
	cout << "Enter the number of test cases";
	cin >> n;
	cout << "Enter the details of the students\n";
	for (int i = 0; i<n; i++)
	{
		cout << "regno " << endl;
		cin >> s[i].regno;
		cout << "name " << endl;
		cin >> s[i].name;
		cout << "branch " << endl;
		cin >> s[i].branch;
		cout << "cgpa " << endl;
		cin >> s[i].cgpa;
	}		
	int choice;
	do {
		cout << "Enter 1 to enable bubblesort on regno: \n";
		cout << "Enter 2 to enable linearsearch on regno: \n";
		cout << "Enter 3 to enable binarysearch on regno: \n";
		cout << "Enter 4 to enable insertionsort on cgpa: \n";
		cout << "Enter 0 to exit: \n";
		cin >> choice;
		switch (choice)
		{
		case 1:regno_bubblesort(s, n);
			break;
		case 2:int item;
			cout << "\nEnter the registeration  number to be searched: ";
			cin >> item;
			linearsearch(item, s, n);
			break;
		case 3:
			cout << "\nEnter the registeration  number to be searched: ";
			cin >> item;
			binarysearch(s, n, item);
			break;
		case 4:cgpa_insertionsort(s, n);
		}
	} while (choice != 0);
	return 0;
}