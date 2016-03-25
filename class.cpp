#include<iostream>
class student{
		int roll;
		char name[30];
		public:
			void getinfo();
			void showinfo();
			void addroll(student S);
};
void student::getinfo()
{
	cout<<"Enter the information of the student..roll..name\n";
	cin>>roll>>name;
}
void student::showinfo()
{
	cout<<"The information of the student is\n";
	cout<<" "<<name<<roll;
}
void student::addroll(student S)
{
	roll+=S.roll;
	cout<<"The rolls are successfully added to the current student "<<name;
	cout<<"\nwith current roll being "<<roll;
}
int main()
{
	int A[10];
	student s,s1;
	s.getinfo();
	s1.getinfo();
	s1.addroll(s);
	s1.showinfo();
	return 0;
}