//
//  DFS_topologicalSort.cpp
//  Graphs
//
//  Created by sushil on 14/04/16.
//  Copyright © 2016 rishabh. All rights reserved.
//

#include <iostream>
#include<list>
using namespace std;
struct dfsvalues{
    int parent;
    string color;
    int d;
    int f;
};
void dfsvisit(list<int> (&A)[10],int n,int i,dfsvalues *V,int* time,list<int> *L)
{
    V[i].d=++*time;
    V[i].color="GREY";
    for(list<int>::iterator j=A[i].begin();j!=A[i].end();j++)
        if(V[*j].color=="WHITE")
        {
            V[*j].parent=i;
            dfsvisit(A,n,*j,V,time,L);
        }
    V[i].f=++*time;
    (*L).push_front(i);
}
void DFS(list<int> (&A)[10],int n,list<int> *L)
{
    dfsvalues V[10];
    int time=0;
    for(int i=0;i<n;i++)
    {
        V[i].color="WHITE";
        V[i].parent=-1;
        V[i].f=V[i].d=-1;
    }
    for(int i=0;i<n;i++)
        if(V[i].color=="WHITE")
            dfsvisit(A,n,i,V,&time,L);
}
/*
  int main()
  {
  list<int> A[10];
  int n;
  //nodename references integers indexes to character(0->a , 1->b ....)
  char nodename[26];
  for(int i=0;i<26;i++)
  {
  nodename[i]=(char)(i+97);
  cout<<nodename[i];
  }
  //entering the edges.....................
  cout<<"Enter the number of vertices\n";
  cin>>n;
  cout<<"Choose which all egdes exist\n";
  for(int i=0;i<n;i++)
  for(int j=0;j<n;j++)
  {
  cout<<"does "<<nodename[i]<<"join to "<<nodename[j]<<"? (1-yes,0-no)";
  int choice;
  cin>>choice;
  if(choice!=0)
  A[i].push_back(j);
  }
  list<int> L;
  DFS(A,n,&L);
      for(list<int>::iterator i=L.begin();i!=L.end();i++)
          cout<<nodename[*i];
      //list<int> L[10];
      //topologicalSort(A,n,L);
  return 0;
  }*/
