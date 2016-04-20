//
//  collisionMethod.cpp
//  hashing
//
//  Created by sushil on 16/04/16.
//  Copyright © 2016 rishabh. All rights reserved.
//
/*
#include <iostream>
#include<list>
using namespace std;

int hash1(int n)
{
    return n%100;
}
void insertH(list<int> (&H)[100],int v)
{
    H[hash1(v)].push_back(v);
}
void searchH(list<int> (&H)[100],int v)
{
    for(list<int>::iterator i = H[hash1(v)].begin();i!=H[hash1(v)].end();i++)
    {
        if(*i == v)
        {
            cout<<"found\n";
            return;
        }
    }
    cout<<"not found\n";
    return;
}
void deleteH(list<int> (&H)[100],int v)
{
    H[hash1(v)].remove(v);
}
int main()
{
    //hashing type: division hash k % m
    list<int> HashTable[100];
    int A[10];
    //for(int i=0;i<10;i++)
      //  A[i]=i;
    int choice = 1,value;
    do{
        cout<<"Enter 1 to insert\n";
        cout<<"Enter 2 to search\n";
        cout<<"Enter 3 to delete\n";
        cout<<"Enter 0 to exit\n";
        cin>>choice;
        switch(choice)
        {
            case 1:
                cout<<"Enter the value to be inserted\n";
                cin>>value;
                insertH(HashTable,value);
                break;
            case 2:
                cout<<"Enter the value to be searched\n";
                cin>>value;
                searchH(HashTable,value);
                break;
            case 3:
                cout<<"Enter value to be deleted\n";
                cin>>value;
                deleteH(HashTable,value);
                break;
        }
    }while(choice != 0);
    return 0;
}
*/