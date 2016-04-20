//
//  practice1.cpp
//  Graphs
//
//  Created by sushil on 09/04/16.
//  Copyright © 2016 rishabh. All rights reserved.
//
/*
//#include <stdio.h>
#include<iostream>
#include<list>
using namespace std;
struct graphnode{
    int position[10];
    string color[10];
    int parent[10];
};

void BFS(list<int> (&Graph)[],int n,int s)
{
    string color[10];
    int parent[10];
    int distance[10];
    for(int i=0;i<n;i++)
    {
        color[i]="WHITE";
        parent[i]=-1;
        distance[i]=-1;
    }
    int Q[10];
    int i=0,j=1;
    Q[i]=s;
    
}
*//*
int main()
{
    //int graph[10];
    
    list<int> Graph[10];
    
    char namingReference[26];
    for(int i=0;i<26;i++)
        namingReference[i]=(char)(97+i);
    
    cout<<"Enter the number of vertices\n";
    int n;
    cin>>n;
    cout<<"Now enter the edges\n";
    for(int i=0;i<n;i++)
        for(int j=0;j<n;j++)
        {
            cout<<"Does a connection exists b/w"<<namingReference[i]<<" and "<<namingReference[j];
            cout<<" (1-yes,0-no)\n";
            int choice;
            cin>>choice;
            if(choice!=0)
                Graph[i].push_back(j);
        }
    BFS(Graph,n,0);
    return 0;
}*/
