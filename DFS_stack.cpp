//
//  DFS_srack.cpp
//  Graphs
//
//  Created by sushil on 13/04/16.
//  Copyright © 2016 rishabh. All rights reserved.
//

#include <iostream>
#include<list>
#include<stack>
using namespace std;
struct dfsvalues{
    int parent;
    string color;
    int d;
    int f;
};

void DFS_stack(list<int>(&A)[10],int n)
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
        {
            V[i].color="GREY";
            V[i].d=++time;
            stack<int> s;
            s.push(i);
        a:
            if(!s.empty())
            {
                int k=s.top();
                s.pop();
                for(list<int>::iterator j=A[k].begin();j!=A[k].end();j++)
                    if(V[*j].color=="WHITE")
                    {
                        V[*j].d=++time;
                        V[*j].color="GREY";
                        V[*j].parent=k;
                        s.push(k);
                        s.push(*j);
                        goto a;
                    }
                V[k].f=++time;
                goto a;
            }
        }
    cout<<"test";
}/*
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
    DFS_stack(A,n);
    return 0;
}*/
