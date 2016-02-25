#include<iostream>
using namespace std;
struct node {
	int data;
	node *next;
};
int length = 0;
void deleteList(node **head)
{
	if (*head != NULL)
	{
		node *ptr = *head;
		if ((*head)->next == NULL)
		{
			delete ptr;
			*head = NULL;
		}
		else {
			node *back = *head;
			ptr = (*head)->next;
			while (ptr != NULL)
			{
				node *delete_node = back;
				delete delete_node;
				back = ptr;
				ptr = ptr->next;
			}
			delete back;
			*head = NULL;
		}

	}
}
void insertatend(node **head,int item)
{
	node *newnode = new node;
	newnode->data = item;
	newnode->next = NULL;
	if (*head == NULL)
	{
		*head = newnode;
	}
	//node *ptr=new node;
	else
	{
		node *ptr;
		ptr = *head;
		while (ptr->next != NULL)
		{
			ptr = ptr->next;
		}
		ptr->next = newnode;
	}
	length++;
}
void insertatbeg(node **head,int item)
{
	node *newnode = new node;
	newnode->data = item;
	newnode->next = NULL;
	newnode->next = *head;
	*head = newnode;
	length++;
}
void insertList(node **head,int item, int pos)
{
	int  length1 = 0;
	node *ptr = *head;
	while (ptr != NULL)
	{
		length1++;
		ptr = ptr->next;
	}
	node *newnode = new node;
	//node *ptr = new node;
	newnode->data = item;
	newnode->next = NULL;
	///node *newnode=NULL;
	//newnode=new node;
	//newnode.next=NULL;
	if (*head == NULL)
	{
		*head = newnode;
		length++;
	}
	else if (pos >= length1 + 1) {
		insertatend(head,item);
	}
	else if (pos <= 1)
	{
		insertatbeg(head,item);
	}
	else {
		int i = 1;
		ptr = *head;
		while (i++<pos - 1)
		{
			ptr = ptr->next;
		}
		newnode->next = ptr->next;
		ptr->next = newnode;
		length++;
	}
}
void sInsertList(node **head,int item)
{
	node *ptr = new node;
	node *q = new node;
	ptr = *head;
	if (ptr->data>item)
	{
		insertatbeg(head,item);
	}
	else {
		q = ptr;
		ptr = ptr->next;
		if (ptr == NULL)
		{
			insertatend(head,item);
		}
		else
		{
			while ((ptr->data<item || q->data>item) && ptr->next != NULL)
			{
				ptr = ptr->next;
				q = q->next;
			}
			if (ptr->next == NULL)
			{
				//insertatend(item);
				if (ptr->data>item && q->data<item)
				{
					node *newnode = new node;
					newnode->data = item;
					q->next = newnode;
					newnode->next = ptr;
					length++;
				}
				else
				{
					node *newnode = new node;
					newnode->data = item;
					newnode->next = NULL;
					ptr->next = newnode;
					length++;
				}
			}
			else {
				node *newnode = new node;
				newnode->data = item;
				q->next = newnode;
				newnode->next = ptr;
				length++;
			}
		}
	}
}
void deleteatbeg(node **head)
{
	node *ptr = new node;
	ptr = *head;
	*head = (*head)->next;
	delete ptr;
	length--;
}
void deleteatend(node **head)
{
	//node *ptr =new node;
	node *ptr = *head;
	//int i = 1;
	//while (i++<length - 1)
	if (head != NULL)
	{
		if (ptr->next == NULL)
		{
			delete ptr;
			*head = NULL;
		}
		else
		{
			while (ptr->next->next != NULL)
			{
				ptr = ptr->next;
			}
			delete ptr->next;
			ptr->next = NULL;

		}
	}
	length--;
}
//////////////////////////////do not use deleteList() as the variable length being used in it is insecure
void deleteList(node **head,int pos)
{
	if (pos <= 1)
	{
		deleteatbeg(head);
	}
	else if (pos >= length)
	{
		deleteatend(head);
	}
	else
	{
		node *ptr = new node;
		node *x = new node;
		int i = 1;
		ptr = *head;
		while (i++<pos - 1)
		{
			ptr = ptr->next;
		}
		x = ptr->next;
		ptr->next = x->next;
		delete x;
		length--;
	}
}
void deleteItem(node **head,int item)
{
	node *ptr = new node;
	node *q = new node;
	ptr = *head;
	if (ptr->next == NULL)
	{
		if (ptr->data == item)
		{
			delete ptr;
			*head = NULL;
			length--;
		}
	}
	else
	{
		q = ptr;
		ptr = ptr->next;
		while (q->data == item && ptr->next != NULL)
		{
			*head = (*head)->next;
			length--;
			q = q->next;
			ptr = ptr->next;
		}
		while (ptr->next != NULL)
		{
			if (ptr->data == item)
			{
				q->next = ptr->next;
				ptr = ptr->next;
				length--;
			}
			else
			{
				ptr = ptr->next;
				q = q->next;
			}
		}
		if (ptr->data == item)
		{
			//delete ptr;	
			ptr = NULL;
			q->next = NULL;
			length--;
		}
		if (q->data == item && q == *head)
		{
			if (ptr != NULL)
				*head = ptr;
			else
				*head = NULL;
			length--;
		}
	}
}
void sDeleteList(node **head,int item)
{
	node *ptr = new node;
	node *q = new node;
	ptr = *head;
	int pos = 1;
	while (ptr->next != NULL && ptr->data<item)
	{
		ptr = ptr->next;
		pos++;
	}
	if (ptr->data == item)
	{
		ptr = ptr->next;
		deleteList(head,pos);
		pos++;
		if (ptr->data == item)
		{
			ptr = ptr->next;
			deleteList(head,pos++);

		}
	}
}
void display(node *Head)
{
	//node *ptr = new node;
	//ptr->next = NULL;
	node *ptr;
	ptr = Head;
	if (ptr != NULL)
	{
		while (ptr->next != NULL)
		{
			cout << ptr->data << " ";
			ptr = ptr->next;
		}
		cout << ptr->data << endl;
	}
}
void FrontBackList(node **head,node **Fhead,node **Lhead)
{
	int n,length1=0;
	node *ptr = *head;
	while (ptr != NULL)
	{
		length1++;
		ptr = ptr->next;
	}
	if (length1 % 2 == 0)
		n = length1 / 2;
	else
		n = length1 / 2 + 1;
	//node *ptr = new node;
	ptr = *head;
	node *fptr = new node;
	node *lptr = new node;
	if (length1 == 0)
	{
		*Fhead = NULL;
		*Lhead = NULL;
	}
	else
	{
		*Fhead = NULL;
		fptr = *Fhead;
		//////////////////
		node *newnode = new node;
		newnode->data = ptr->data;
		newnode->next = NULL;
		fptr = *Fhead = newnode;
		//Fhead=newnode;
		/////////////////
		//cout<<endl<<n;
		for (int i = 1; i<n; i++)
		{
			ptr = ptr->next;
			node *newnode1 = new node;
			newnode1->data = ptr->data;
			newnode1->next = NULL;
			//fptr->data=ptr->data;
			//ptr=ptr->next;
			fptr->next = newnode1;
			fptr = fptr->next;
		}
		if (ptr->next != NULL)
		{
			ptr = ptr->next;
			*Lhead = NULL;
			lptr = *Lhead;
			node *newnode2 = new node;
			newnode2->data = ptr->data;
			newnode2->next = NULL;
			lptr = *Lhead = newnode2;
			for (int i = n + 1; i < length1; i++)
			{
				//delete newnode;
				ptr = ptr->next;
				node *newnode3 = new node;
				newnode3->data = ptr->data;
				newnode3->next = NULL;
				//fptr->data=ptr->data;
				//ptr=ptr->next;
				lptr->next = newnode3;
				lptr = lptr->next;
			}
		}
	}
}
void swap(node **a_back, node **a, node **b_back, node **b)
{
	(*a_back)->next = *b;
	(*b_back)->next = (*b)->next;
	(*b)->next = *a;
}
void sort(node **head)
{	
	if (*head != NULL && (*head)->next!=NULL)
	{
		node *ptr = (*head)->next,*ptr_back=*head;
		while(ptr!=NULL)
		{
			node *q = *head,*q_back=*head;
			if (q->data > ptr->data && (*head)->next==ptr)
			{
				int temp = q->data;
				q->data = ptr->data;
				ptr->data = temp;
			}
			else if (q->data > ptr->data)
			{
				*head = ptr;
				ptr_back->next = ptr->next;
				ptr->next = q;
				ptr = ptr_back;
			}
			else 
			{
				q = q->next;
				while (q != ptr && q->data < ptr->data)
				{
					q = q->next;
					q_back = q_back->next;
				}
				if (q != ptr)
				{
					swap(&q_back, &q, &ptr_back, &ptr);
					ptr = ptr_back;
				}
			}
			if(ptr!=ptr_back)
				ptr_back = ptr_back->next;
			ptr = ptr->next;

		}
	}
}
void merge(node **sortedList, node **Lhead, node**Rhead)
{
	node *lptr = *Lhead, *rptr = *Rhead;
	while (lptr != NULL && rptr != NULL)
	{
		if (lptr->data < rptr->data)
		{
			insertatend(sortedList, lptr->data);
			lptr = lptr->next;
		}
		else
		{
			insertatend(sortedList,rptr->data);
			rptr = rptr->next;
		}
	}
	while (lptr != NULL)
	{
		insertatend(sortedList, lptr->data);
		lptr = lptr->next;
	}
	while (rptr != NULL)
	{
		insertatend(sortedList, rptr->data);
		rptr = rptr->next;
	}
}
void mergesort_merge(node **sortedList, node **Lhead, node**Rhead)
{
	node *lptr = *Lhead, *rptr = *Rhead;
	while (lptr != NULL && rptr != NULL)
	{
		if (lptr->data < rptr->data)
		{
			insertatend(sortedList, lptr->data);
			lptr = lptr->next;
		}
		else
		{
			insertatend(sortedList, rptr->data);
			rptr = rptr->next;
		}
	}
	while (lptr != NULL)
	{
		insertatend(sortedList, lptr->data);
		lptr = lptr->next;
	}
	while (rptr != NULL)
	{
		insertatend(sortedList, rptr->data);
		rptr = rptr->next;
	}
	deleteList(Lhead);
	deleteList(Rhead);
}
void mergeSort_partition(node ** head,node ** Fhead,node ** Lhead)
{
	int n, length1 = 0;
	node *ptr = *head;
	while (ptr != NULL)
	{
		length1++;
		ptr = ptr->next;
	}
	if (length1 % 2 == 0)
		n = length1 / 2;
	else
		n = length1 / 2 + 1;
	//node *ptr = new node;
	ptr = *head;
	node *fptr = new node;
	node *lptr = new node;
	if (length1 == 0)
	{
		*Fhead = NULL;
		*Lhead = NULL;
	}
	else
	{
		*Fhead = NULL;
		fptr = *Fhead;
		//////////////////
		node *newnode = new node;
		newnode->data = ptr->data;
		newnode->next = NULL;
		fptr = *Fhead = newnode;
		//Fhead=newnode;
		/////////////////
		//cout<<endl<<n;
		for (int i = 1; i<n; i++)
		{
			ptr = ptr->next;
			node *newnode1 = new node;
			newnode1->data = ptr->data;
			newnode1->next = NULL;
			//fptr->data=ptr->data;
			//ptr=ptr->next;
			fptr->next = newnode1;
			fptr = fptr->next;
		}
		if (ptr->next != NULL)
		{
			ptr = ptr->next;
			*Lhead = NULL;
			lptr = *Lhead;
			node *newnode2 = new node;
			newnode2->data = ptr->data;
			newnode2->next = NULL;
			lptr = *Lhead = newnode2;
			for (int i = n + 1; i < length1; i++)
			{
				//delete newnode;
				ptr = ptr->next;
				node *newnode3 = new node;
				newnode3->data = ptr->data;
				newnode3->next = NULL;
				//fptr->data=ptr->data;
				//ptr=ptr->next;
				lptr->next = newnode3;
				lptr = lptr->next;
			}
		}
	}
	deleteList(head);
}
void mergeSort(node **head)
{
	if (head!=NULL && (*head)->next != NULL)
	{
		node *Lhead = NULL, *Rhead = NULL;
		mergeSort_partition(head, &Lhead, &Rhead);
		mergeSort(&Lhead);
		mergeSort(&Rhead);
		mergesort_merge(head, &Lhead, &Rhead);
	}
}
void reverseList(node **head)
{
	node *Rhead = NULL, *ptr = *head;
	while (ptr != NULL)
	{
		insertatbeg(&Rhead, ptr -> data);
		ptr = ptr->next;
	}
	deleteList(head);
	*head = Rhead;
}

int main()
{
	node *head=NULL;
	node *Lhead = NULL, *Rhead = NULL;
	node *sortedList=NULL;
	int choice;
	do {
		cout << "Enter 1 to add a node\n";
		cout << "Enter 2 to delete\n";
		cout << "Enter 3 to display\n";
		cout << "Enter 4 to sort\n";
		cout << "Enter 5 to break list in two parts\n";
		cout << "Enter 6 to break list in two parts,sort them and then merge\n";
		cout << "Enter 7 to delete list\n";
		cout << "Enter 8 to reverse list\n";
		cout << "Enter 0 to exit\n";
		cin >> choice;
		switch (choice)
		{
		case 1:cout << "at which location do yu want to insert:\n";
			int pos;
			cin >> pos; 
			cout << "Enter the new data:\n";
			int data;
			cin >> data;
			insertList(&head,data,pos);
			break;
		case 2:
			cout << "Enter the data to be deleted:\n";
			int data1;
			cin >> data1;
			deleteItem(&head,data1);
			break;
		case 3:
			display(head);
			break;
		case 4:
			mergeSort(&head);
			display(head);
			break;
		case 5:
			FrontBackList(&head, &Lhead, &Rhead);
			cout << "The left and the right lists are:\n";
			display(Lhead);
			display(Rhead);
			deleteList(&Lhead);
			deleteList(&Rhead);
			break;
		case 6:
			FrontBackList(&head, &Lhead, &Rhead);
			sort(&Lhead);
			sort(&Rhead);
			cout << "The left and the right lists are:\n";
			display(Lhead);
			display(Rhead);
			merge(&sortedList,&Lhead, &Rhead);
			cout << "The merged sorted list is:\n";
			display(sortedList);
			deleteList(&Lhead);
			deleteList(&Rhead);
			deleteList(&sortedList);
			break;
		case 7:
			deleteList(&head);
			break;
		case 8:
			reverseList(&head);
			display(head);
			break;
		}
	} while (choice != 0);
	return 0;
}