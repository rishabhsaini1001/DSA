#include<iostream>
#include<string>
using namespace std;
struct student{
	int regno;
	char name[30];
	char branch[5];
	float cgpa;
	};
	
	void linearsearch(int regno,student s[],int n);
	void regno_bubblesort();
	void binarysearch();
	void cgpa_insertionsort();

	void linearsearch(int regno1,student s[],int n)
	{
		for(int i=0;i<n;i++)
		{
			if(regno1==s[i].regno)
			{
				cout<<endl<<"found!!!!\n"<<s[i].regno<<"\n"<<s[i].name<<"\n"<<s[i].branch<<"\n"<<s[i].cgpa<<"\n";
			}
		}
	}
	void regno_bubblesort(student s[],int n)
	{
		int tregno;
		char tname[30],tbranch[5];
		float tcgpa;
		for(int i=0;i<n;i++)
		{
			for(int j=0;j<n;j++)
			{
				if(s[j].regno>s[j+1].regno)
				{
					tregno=s[j].regno;
					strcpy(tname,s[j].name);
					strcpy(tbranch,s[j].branch);
					tcgpa=s[j].cgpa;
					/////////////////////////////
					s[j].regno=s[j+1].regno;
					strcpy(s[j].name,s[j+1].name);
					strcpy(s[j].branch,s[j+1].branch);
					s[j].cgpa=s[j+1].cgpa;
					/////////////////////////////
					s[j+1].regno=tregno;
					strcpy(s[j+1].name,tname);
					strcpy(s[j+1].branch,tbranch);
					s[j+1].cgpa=tcgpa;
					cout<<endl<<tregno<<s[j+1].regno<<endl<<tname<<s[j+1].name<<endl<<tbranch<<s[j+1].branch<<endl<<tcgpa<<s[j+1].cgpa;
				}
			}
		}
		/*for(int i=0;i<n;i++)
{
		int i=1;	
	    cout<<endl<<"regno ";
		cout<<s[i].regno<<endl;
		cout<<"name ";
		cout<<s[i].name<<endl;
		cout<<"branch ";
		cout<<s[i].branch<<endl;
		cout<<"cgpa ";
		cout<<s[i].cgpa<<endl<<endl;
}	*/
	}
	void binarysearch();
	void cgpa_insertionsort();

int main()
{
	student s[50];
	int n;
	cout<<"Enter the number of test cases";
	cin>>n;
	cout<<"Enter the details of the students\n";
	for(int i=0;i<n;i++)
	{
		cout<<"regno "<<endl;
		cin>>s[i].regno;
		cout<<"name "<<endl;
		cin>>s[i].name;
		cout<<"branch "<<endl;
		cin>>s[i].branch;
		cout<<"cgpa "<<endl;
		cin>>s[i].cgpa;	
	}
	//regno_bubblesort(s,n);
	linearsearch(1,s,n);
	for(int i=0;i<n;i++)
{
	    cout<<endl<<"regno ";
		cout<<s[i].regno<<endl;
		cout<<"name ";
		cout<<s[i].name<<endl;
		cout<<"branch ";
		cout<<s[i].branch<<endl;
		cout<<"cgpa ";
		cout<<s[i].cgpa<<endl<<endl;
}	
	return 0;
}