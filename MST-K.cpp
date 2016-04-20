//
//  MST-K.cpp
//  Graphs
//
//  Created by sushil on 14/04/16.
//  Copyright © 2016 rishabh. All rights reserved.
//

#include <iostream>
#include<string>
#include<list>
#include <functional>
#include <queue>
#include <vector>

using namespace std;
struct weight{
    int u;
    int v;
    int w;
};

struct node{
    int data;
    int rank;
    node* p;
};

node* find(node* a)
{
    
    while(a->data!=a->p->data)
        a=a->p;
    return a;
}
void link(node *a,node* b)
{
    if(a->rank>b->rank)
    {
        cout<<a->data<<" is connected to "<<b->data<<endl;
        b->p=a;
    }
    else
    {
        a->p=b;
        cout<<b->data<<" is connected to "<<a->data<<endl;
    }
    if(a->rank==b->rank)
        b->rank++;
}
void Union(node* a,node* b)
{
    link(find(a),find(b));
}

template<typename T> void print_queue(T& q) {
    while(!q.empty()) {
        cout << (q.top()).w << " "<<(q.top()).u << " "<<(q.top()).v << " \n";
        q.pop();
    }
    std::cout << '\n';
}

template<typename T> void MST_K(list<int>(&A)[10],int n,T& W)
{
    node *N[10];
    for(int i=0;i<n;i++)
    {
        N[i]=new node;
        N[i]->data=i;
        N[i]->rank=0;
        N[i]->p=N[i];
    }
    
    while(!W.empty())
    {
        weight W1=W.top();
        W.pop();
        //if(find(&(N[W1.u]))!=find(&(N[W1.v])))
            //if(find(N+W1.u)!=(find(N+W1.v)))
        if(find(N[W1.u])!=find(N[W1.v]))
        {
            
            Union(N[W1.u],N[W1.v]);
        }
    }
}
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
   // weight W[100];
    auto cmp = [](weight left, weight right) { return (left.w) > (right.w);};
    priority_queue<weight, std::vector<weight>, decltype(cmp)> We(cmp);
    int k=0;

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
                cout<<"What's the weight of this edge\n";
                int ww;
                cin>>ww;
                weight W;
                W.u=i;
                W.v=j;
                W.w=ww;
                k++;
                We.push(W);
                if(i!=j)
                {
                    Ilist[j].push_back(i);
                   /* W[k].u=j;
                    W[k].v=i;
                    W[k].w=ww;
                    k++;*/
                }
            }
        }
    MST_K(Ilist,n,We);
       return 0;
}