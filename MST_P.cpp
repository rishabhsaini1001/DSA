//
//  MST_P.cpp
//  Graphs
//
//  Created by sushil on 15/04/16.
//  Copyright © 2016 rishabh. All rights reserved.
//
/*
#include <iostream>
#include<string>
#include<list>
#include <functional>
#include <queue>
#include <vector>

using namespace std;
struct node{
    int data;
    int key;
    node* p;
};

template<typename T> void print_queue(T& q) {
    while(!q.empty()) {
        cout << (q.top()).w << " "<<(q.top()).u << " "<<(q.top()).v << " \n";
        q.pop();
    }
    std::cout << '\n';
}

void MST_P(list<int>(&A)[10], int n2,int* W,char *nodename)
{
    //priority_queue<node *> Q;
    auto cmp = [](node * left, node * right) { return (left->key) > (right->key);};
    priority_queue<node *, std::vector<node *>, decltype(cmp)> Q(cmp);
    
    node *maintainence[10];
    for(int k1=0;k1<n2;k1++)
    {
    maintainence[k1] = new node;
    maintainence[k1]->data = k1;
    maintainence[k1]->key = 99999;
    maintainence[k1]->p=NULL;
    //Q.push(newnode1);
    }
    int r=0;
    maintainence[r]->key=0;
    Q.push(maintainence[r]);
    while(!Q.empty())
    {
        node *n = Q.top();
        Q.pop();
        
        if(n->p!=NULL)
        {
            cout<<nodename[n->data]<<"  ";
            cout<<"is connected to "<<nodename[n->p->data]<<endl;
        }
        n->key*=-1;
        for(list<int>::iterator i1 = A[n->data].begin();i1!=A[n->data].end();i1++)
        {
            if((maintainence[*i1]->key>0)&&(*((W + 10*n->data ) + *i1 )<maintainence[*i1]->key))
            {
                maintainence[*i1]->p=maintainence[n->data];
                maintainence[*i1]->key = *((W + 10*n->data ) + *i1 );
                //
                int j=0;
                int i=*i1;
                int key =0;
                node *N[10];
                while(!Q.empty())
                {
                    key = 1;
                    N[j] =Q.top();
                    if(N[j]->data==i)
                    {
                        for(int i2=0;i2<j;i2++)
                            Q.push(N[i2]);
                        j=0;
                        //key=1;
                        break;
                    }
                    else
                    {
                        Q.pop();
                        j++;
                    }
                }
                if(j!=0 || key == 0)
                {
                    for(int i2=0;i2<j;i2++)
                        Q.push(N[i2]);
                    Q.push(maintainence[*i1]);
                }
                //
                //else
                  //  Q.push(maintainence[*i1]);
            }
        }
    }
    /*
    //
    for(int i=0;i<10;i++)
    {
    node *newnode2 = new node;
    newnode2->data = i;
    newnode2->key = i-1;
    newnode2->p=NULL;
    Q.push(newnode2);
    }
    node* N[10];
    int j=0;
    int i=8;
    while(!Q.empty())
    {
        N[j] =Q.top();
        if(N[j]->data==i)
        {
            for(int i=0;i<j;i++)
            Q.push(N[i]);
            j=0;
            //key=1;
            break;
        }
        else
        {
            Q.pop();
            j++;
        }
    }
    if(j!=0)
    {
        for(int i=0;i<j;i++)
            Q.push(N[i]);
    }
    cout<<"TEST!";
    //
 */
    //
    //node *root = newnode;
    /*
    int n1=n2;
    while(!Q.empty())
    {
        node *n = Q.top();
        Q.pop();
        for(list<int>::iterator i = A[n->data].begin();i!=A[n->data].end();i++)
        {
            //if *i doesn't exist in Q
            node* N[10];
            int j=0;
            int key =0;
            while(!Q.empty())
            {
                N[j] =Q.top();
                if(N[j]->data==*i)
                {
                    for(int i=0;i<j;i++)
                        Q.push(N[i]);
                    j=0;
                    key=1;
                    break;
                }
                else
                {
                    Q.pop();
                    j++;
                }
            }
            if(j!=0)
            {
                key =0;
                for(int i=0;i<j;i++)
                    Q.push(N[i]);
            }
            //
            if(key==0)
            {
                node *newnode = new node;
                newnode->data = *i;
                int temp1 = *i;
                int temp2 = *((W + 10*n->data ) + *i );
                newnode->key = *((W + 10*n->data ) + *i );
                newnode->p = n;
                Q.push(newnode);
            }
                //
            
            
            //
            else if( *((W + n->data ) + *i ) < N[j]->key)
            {
                N[j]->data = j;
                N[j]->key = *((W + n->data ) + *i );
                N[j]->p = n;
                Q.push(N[j]);
            }
            break;
            
        }
    }
    //return root;
     *//*
    cout<<"hi";
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
       // cout<<nodename[i];
    }
    //entering the edges.....................
    cout<<"Enter the number of vertices\n";
    cin>>n;
    // weight W[10][];
    int W[10][10];
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
                W[i][j]=ww;
                if(i!=j)
                {
                    W[j][i]=ww;
                    Ilist[j].push_back(i);
                    /* W[k].u=j;
                     W[k].v=i;
                     W[k].w=ww;
                     k++;*//*
                }
            }
        }
    */
    //print_queue(We);
/*
     MST_P(Ilist,n,(int *)W,nodename);
    cout<<"hi";*/
    //MST_K(Ilist, n, We);
    
    //displaying the graph
    /*
     for(int i=0;i<n;i++)
     {
     //transversing vertices
     for(list<int>::iterator list_iter = Ilist[i].begin();
     list_iter != Ilist[i].end(); list_iter++)
     {
     cout<<nodename[*list_iter]<<endl;
     }
     }*//*
    cout<<"hi";
    return 0;
}*/