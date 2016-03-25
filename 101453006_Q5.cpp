/*
Roll No: 101453006
Name: Rishabh Kumar Saini
Group: COE9
Question: 5
*/
#include<iostream>
using namespace std;
class queue {
	int A[100];
	int n;
	int front;
	int rear;
public:
	void insertQueue(int data);
	int deleteQueue();
	void initialize(int limit);
	void display();
};
void queue::initialize(int limit)
{
	front = rear = -1;
	n = limit;
}
void queue::insertQueue(int data)
{
	if (front == -1  && rear == -1)
	{
		front = rear = 0;
		A[rear] = data;
	}
	else if ((front == 0 && rear == n - 1) || rear == front - 1)
	{

	}
	else
	{
		rear = (rear + 1) % n;
		A[rear] = data;
	}
}
int queue::deleteQueue()
{
	if (front == -1 && rear == -1)
		return -99999;
	if (front == rear)
	{
		int temp = A[front];
		front = rear = -1;
		return temp;
	}
	else
	{
		int temp = A[front];
		front = (front + 1) % n;
		return temp;
	}
}
void queue::display()
{
	if (front != -1)
	{
		for (int i = front; i <= rear; i = (i + 1) % n)
		{
			cout << A[i] << " ";
			if (i == rear)
				break;
		}cout << endl;
	}
}
int main()
{
	cout << "Enter the size of the queue you want to work with\n";
	int n;
	cin >> n;
	queue Q;
	Q.initialize(n);
	int choice;
	do {
		cout << "Enter 1 to insert\n";
		cout << "Enter 2 to delete\n";
		cout << "Enter 3 to display\n";
		cout << "Enter 0 to exit\n";
		cin >> choice;
		switch (choice)
		{
		case 1:
			cout << "Enter the new data:\n";
			int data;
			cin >> data;
			Q.insertQueue(data);
			break;
		case 2:
			int data1;
			data1=Q.deleteQueue();
			if(data1!=-99999)
				cout << "Element " << data1 << " was successfully deleted\n";
			break;
		case 3:
			Q.display();
			break;
		}
	} while (choice != 0);
	return 0;
}