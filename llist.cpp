#include<iostream>
using namespace std;
struct node{
	int data;
	node *next;
}*head;
int length=0;
insertatend(int item)
{
	node *newnode=new node;
	node *ptr=new node;
	newnode->data=item;
	newnode->next=NULL;
		ptr=head;
		while(ptr->next!=NULL)
		{
			ptr=ptr->next;
		}
		ptr->next=newnode;
	length++;
}
void insertatbeg(int item)
{
	node *newnode=new node;
	newnode->data=item;
	newnode->next=NULL;
	newnode->next=head;
	head=newnode;
	length++;
}
void insertList(int item,int pos)
{
	node *newnode=new node;
	node *ptr=new node;
	newnode->data=item;
	newnode->next=NULL;
	///node *newnode=NULL;
	//newnode=new node;
	//newnode.next=NULL;
	if(head==NULL)
		{
			head=newnode;
			length++;
		}
	else if(pos>=length+1){
		insertatend(item);
	}
	else if(pos<=1)
	{
		insertatbeg(item);
	}
	else{
		int i=1;
		ptr=head;
		while(i++<pos-1)
		{
			ptr=ptr->next;
		}
		newnode->next=ptr->next;
		ptr->next=newnode;
		length++;
		}
}
void sInsertList(int item)
{
	node *ptr=new node;
	node *q=new node;
	ptr=head;
	if(ptr->data>item)
	{
		insertatbeg(item);
	}
	else{
			q=ptr;
			ptr=ptr->next;
			if(ptr==NULL)
			{
				insertatend(item);
			}
			else
			{
				while((ptr->data<item || q->data>item)&&ptr->next!=NULL)
				{
					ptr=ptr->next;
					q=q->next;
				}
				if(ptr->next==NULL)
				{	
					//insertatend(item);
					if(ptr->data>item && q->data<item)
					{
						node *newnode=new node;
						newnode->data=item;
						q->next=newnode;
						newnode->next=ptr;
						length++;	
					}
					else
					{
						node *newnode=new node;
						newnode->data=item;
						newnode->next=NULL;
						ptr->next=newnode;
						length++;
					}
				}
				else{
					node *newnode=new node;
					newnode->data=item;
					q->next=newnode;
					newnode->next=ptr;
					length++;	
				}
			}
		}
}
void deleteatbeg()
{
	node *ptr=new node;
	ptr=head;
	head=head->next;
	delete ptr;
	length--;
}
void deleteatend()
{
	node *ptr=new node;
	ptr=head;
	int i=1;
	while(i++<length-1)
	{
		ptr=ptr->next;
	}
	delete ptr->next;
	ptr->next=NULL;
	length--;
}
void deleteList(int pos)
{
	if(pos<=1)
	{
		deleteatbeg();
	}
	else if(pos>=length)
	{
		deleteatend();
	}
	else
	{
		node *ptr= new node;
		node *x= new node;
		int i=1;
		ptr=head;
		while(i++<pos-1)
		{
		ptr=ptr->next;
		}
		x=ptr->next;
		ptr->next=x->next;
		delete x;
		length--;
	}
}
void deleteItem(int item)
{
	node *ptr=new node;
	node *q=new node;
	ptr=head;
	if(ptr->next==NULL)
		{
			if(ptr->data==item)
			{
				delete ptr;
				head=NULL;
				length--;
			}
		}
	else
	{	
		q=ptr;
		ptr=ptr->next;	
		while(q->data==item && ptr->next!=NULL)
		{
			head=head->next;
			length--;	
			q=q->next;
			ptr=ptr->next;		
		}			
		while(ptr->next!=NULL)
		{
			if(ptr->data==item)
			{
				q->next=ptr->next;
				ptr=ptr->next;
				length--;
			}
			else
			{
				ptr=ptr->next;
				q=q->next;
			}
		}
		if(ptr->data==item)
		{
			//delete ptr;	
			ptr=NULL;
			q->next=NULL;
			length--;
		}	
		if(q->data==item && q==head)
		{
			if(ptr!=NULL)
				head=ptr;
			else
				head=NULL;
			length--;
		}
	}
}
void sDeleteList(int item)
{
	node *ptr=new node;
	node *q=new node;
	ptr=head;
			int pos=1;
			while(ptr->next!=NULL && ptr->data<item)
			{
				ptr=ptr->next;
				pos++;
			}
			if(ptr->data==item)
			{
				ptr=ptr->next;
				deleteList(pos);
				pos++;
				if(ptr->data==item)
					{
						ptr=ptr->next;
						deleteList(pos++);
						
					}	
			}
}
void display()
{
	node *ptr=new node;
	ptr->next=NULL;
	ptr=head;
	if(ptr!=NULL)
	{
		while(ptr->next!=NULL)
			{
				cout<<ptr->data<<" ";
				ptr=ptr->next;
			}
			cout<<ptr->data<<endl;
	}
}

node *Fhead,*Lhead;
void FrontBackList()
{
	int n;
	if(length%2==0)
		n=length/2;
	else
		n=length/2+1;
	node *ptr=new node;
	ptr=head;
	node *fptr=new node;
	node *lptr=new node;
	if(length==0)
		{
			Fhead=NULL;
			Lhead=NULL;
		}
	else
	{
		Fhead=NULL;	
		fptr=Fhead;	
		//////////////////
		node *newnode=new node;
		newnode->data=ptr->data;
		newnode->next=NULL;
		fptr=Fhead=newnode;		
		//Fhead=newnode;
		/////////////////
		//cout<<endl<<n;
		for(int i=1;i<n;i++)
		{
			ptr=ptr->next;
			node *newnode1=new node;
			newnode1->data=ptr->data;
			newnode1->next=NULL;
			//fptr->data=ptr->data;
			//ptr=ptr->next;
			fptr->next=newnode1;
			fptr=fptr->next;
		}	
		ptr=ptr->next;
		Lhead=NULL;
		lptr=Lhead;
		node *newnode2=new node;
		newnode2->data=ptr->data;
		newnode2->next=NULL;
		lptr=Lhead=newnode2;
		for(int i=n+1;i<length;i++)
		{
			//delete newnode;
			ptr=ptr->next;
			node *newnode3=new node;
			newnode3->data=ptr->data;
			newnode3->next=NULL;
			//fptr->data=ptr->data;
			//ptr=ptr->next;
			lptr->next=newnode3;
			lptr=lptr->next;
		}				
	}
}
void Fdisplay()
{
	node *ptr=new node;
	ptr->next=NULL;
	ptr=Fhead;
	if(ptr!=NULL)
	{
		while(ptr->next!=NULL)
			{
				cout<<ptr->data<<" ";
				ptr=ptr->next;
			}
			cout<<ptr->data<<endl;
	}
}	
void Ldisplay()
{
	node *ptr=new node;
	ptr->next=NULL;
	ptr=Lhead;
	if(ptr!=NULL)
	{
		while(ptr->next!=NULL)
			{
				cout<<ptr->data<<" ";
				ptr=ptr->next;
			}
			cout<<ptr->data<<endl;
	}
}	
int main()
{
	head=NULL;
	cout<<"Enter the number of items to be added";
	int n;
	cin>>n;
	cout<<"Enter the nos.";
	while(n-->0)
	{
		int a;
		cin>>a;
		insertList(a,length+1);
	}
	/*cout<<"**************\nEnter the position and number u want to add";
	int a,no;
	//cin>>no;
	cin>>a>>no;
	insertList(no,a);
	//insertatend(no);
	//deleteatbeg();
	//deleteatend();
	display();
	cout<<"**************\nEnter the position  	";
	cin>>a;
	deleteList(a);*/
	//sInsertList(3);
	/*cout<<"\nEnter the item you want to delete";
	int item;
	cin>>item;
	deleteItem(item);
	//sDeleteList(3);*/
	FrontBackList();
	display();
		Fdisplay();
		Ldisplay();
	cout<<"length::"<<length;
	return 0;
}