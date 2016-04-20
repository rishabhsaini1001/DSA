//
//  trial.cpp
//  Graphs
//
//  Created by sushil on 08/04/16.
//  Copyright © 2016 rishabh. All rights reserved.
//

#include <iostream>
#include<string>
#include<list>
using namespace std;
void BFS(list<int> (&Ilist)[10],int s,int n,char *nodename)
{
    
    //maintaining a circular queue of indeces
    int i=0,j=1;
    int Q[26];
    Q[0]=s;
    
    //color maintains either WHITE or GRAY for each node
    string color[26];
    
    //array to maintain pointer to parent
    int parent[26];
    
    //
    int distance[26];
    
    //initialising......
    for(int i=0;i<n;i++)
    {
        color[i]="WHITE";
        parent[i]=-1;
        distance[i]=0;
    }
    //transversal loop
    color[s]="GRAY";
    //list<int>::iterator list_iter = Ilist[i].begin();
    cout<<nodename[s]<<endl;
    while(i!=j)
    {
        color[Q[i]]="GRAY";
        for(list<int>::iterator list_iter = Ilist[Q[i]].begin();
            list_iter != Ilist[Q[i]].end(); list_iter++)
        {
            //cout<<nodename[*list_iter]<<endl;
            int j1=*list_iter;
            if(color[j1]=="WHITE")
            {
                cout<<nodename[*list_iter]<<endl;
                color[j1]="GRAY";
                parent[j1]=i;
                Q[j]=j1;
                j=(j+1)%26;
                distance[j1]=distance[Q[i]]+1;
            }
        }
        i=(i+1)%26;
//        color[Q[i]]="GRAY";
    }
    cout<<"HI";
}/*
int main()
{
    //initialising the array of lists to maintain connections of each node
    list<int> Ilist[10];
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
                Ilist[i].push_back(j);
        }
    BFS(Ilist,1,n,nodename);
    /*displaying the graph
    for(int i=0;i<n;i++)
    {
        //transversing vertices
        for(list<int>::iterator list_iter = Ilist[i].begin();
            list_iter != Ilist[i].end(); list_iter++)
        {
            cout<<nodename[*list_iter]<<endl;
        }
    }*//*
    
    return 0;
}*/