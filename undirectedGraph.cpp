//
//  undirectedGraph.cpp
//  Graphs
//
//  Created by sushil on 14/04/16.
//  Copyright © 2016 rishabh. All rights reserved.
//

#include <iostream>
#include<string>
#include<list>
using namespace std;
/*
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
        for(int j=i;j<n;j++)
        {
            cout<<"does "<<nodename[i]<<"join to "<<nodename[j]<<"? (1-yes,0-no)";
            int choice;
            cin>>choice;
            if(choice!=0)
            {
                Ilist[i].push_back(j);
                if(i!=j)
                    Ilist[j].push_back(i);
            }
        }
    //displaying the graph
     for(int i=0;i<n;i++)
     {
     //transversing vertices
     for(list<int>::iterator list_iter = Ilist[i].begin();
     list_iter != Ilist[i].end(); list_iter++)
     {
     cout<<nodename[*list_iter]<<endl;
     }
     }
    cout<<"hi";
    return 0;
}*/