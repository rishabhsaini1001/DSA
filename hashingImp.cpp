//
//  hashingImp.cpp
//  hashing
//
//  Created by sushil on 17/04/16.
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
int hash1(unsigned char *str)
{
    int hash = 5381;
    int c;
    
    while ((c = *str++))
        hash = ((hash << 5) + hash) + c; /* hash * 33 + c *//*
    
    return hash;
}
////
// hash: compute hash value of string
unsigned int hash2(char *str)
{
    unsigned int h;
    unsigned char *p;
    int MULTIPLIER = 37;
    h = 0;
    for (p = (unsigned char*)str; *p != '\0'; p++)
        h = MULTIPLIER * h + *p;
    return h; // or, h % ARRAY_SIZE;
}
////
//

static unsigned int FNVHash(string str) {
    const unsigned int fnv_prime = 0x811C9DC5;
    unsigned int hash = 0;
    unsigned int i = 0;
    unsigned int len = str.length();
    
    for (i = 0; i < len; i++)
    {
        hash *= fnv_prime;
        hash ^= (str[i]);
    }
    
    return hash;
}

//

void insertH(list<int> (&H)[100],unsigned char *v)
{
    H[hash(v)].push_back(*v);
}
void searchH(list<int> (&H)[100],unsigned char* v)
{
    for(list<int>::iterator i = H[hash1(v)].begin();i!=H[hash1(v)].end();i++)
    {
        if(*i == *v)
        {
            cout<<"found\n";
            return;
        }
    }
    cout<<"not found\n";
    return;
}
void deleteH(list<int> (&H)[100],unsigned char *v)
{
    H[hash1(v)].remove(*v);
}
/*
int main()
{
    //hashing type: division hash k % m
    list<int> HashTable[100];
    //int A[10];
    //for(int i=0;i<10;i++)
    //  A[i]=i;
    /*
    int choice = 1;
    unsigned char value[15];
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
    }while(choice != 0);*//*
    unsigned char c[10] ="ABc";
    string s = " Hellogbh ";
    cout<<FNVHash(s);
    return 0;
}
*/