//
//  Project_Main_v1.cpp
//  hashing
//
//  Created by sushil on 20/04/16.
//  Copyright © 2016 rishabh. All rights reserved.
//


/* rand example: guess the number */
#include <stdio.h>      /* printf, scanf, puts, NULL */
#include <stdlib.h>     /* srand, rand*/
#include <time.h>       /* time */
#include<iostream>
#include<string>
#include<fstream>
#include<list>

using namespace std;

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
    
    return hash%1000;
}
void insertH(list<string> (&H)[1000],string v)
{
    H[FNVHash(v)].push_back(v);
}
int searchH(list<string> (&H)[1000],string v)
{
    for(list<string>::iterator i = H[FNVHash(v)].begin();i!=H[FNVHash(v)].end();i++)
    {
        if(*i == v)
        {
            //cout<<"found\n";
            return 1;
        }
    }
    //cout<<"not found\n";
    return 0;
}
void deleteH(list<string> (&H)[1000],string v)
{
    H[FNVHash(v)].remove(v);
}

int main ()
{
    int iSecret;
    
    // initialize random seed:
    srand (time(NULL));
    
    //the main thing !!!:D
    char matrix[4][4];
    string S[268];
    int n=0;
    for (int i=0;i<4;i++)
    {
        for(int j=0;j<4;j++)
        {
            iSecret = rand() % 25 ;
            matrix[i][j]=(char)(iSecret + 97);
            //..testing purposes only__________________________-------<<<>>>
            cout<<matrix[i][j]<<" ";
        }
        cout<<endl;
    }
    /*
    matrix[0][0]='b';
    matrix[0][1]='a';
    matrix[0][2]='l';
    matrix[0][3]='l';
    
    for (int i=0;i<4;i++)
    {for(int j=0;j<4;j++)
    {
        //iSecret = rand() % 25 ;
        // matrix[i][j]=(char)(iSecret + 97);
        cout<<matrix[i][j]<<" ";
    }cout<<endl;}
    */
    //

    for(int r=0;r<4;r++)
        for(int i=0;i<4;i++)
        {
            S[n++] = matrix[r][i];
            //horizontal options
            for(int j=0;j<4;j++)
            {
                if(j<i)
                {
                    for(int k=i;k>=j;k--)
                        S[n]+=matrix[r][k];
                    n++;
                }
                else if(j>i)
                {
                    for(int k=i;k<=j;k++)
                        S[n]+=matrix[r][k];
                    n++;
                }
            }
            //vertical options
            for(int j=0;j<4;j++)
            {
                //S[n]+=matrix[k][i];
                if(j<r)
                {
                    for(int k=r;k>=j;k--)
                        S[n]+=matrix[k][i];
                    n++;
                }
                else if(j>r)
                {
                    for(int k=r;k<=j;k++)
                        S[n]+=matrix[k][i];
                    n++;
                }
            }
            //diagonal options
            for(int j=0;j<4;j++)
            {
                if(j<r)
                {
                    for(int k=0;k<4;k++)
                    {
                        if(k<i)
                        {if(i-k<=r)
                        {
                            for(int z=i;z>=k;z--)
                                S[n]+=matrix[r-(i-z)][z];
                            n++;
                        }}
                        else if(k>i)
                            if(k-i<=r)
                            {
                                for(int z=i;z<=k;z++)
                                    S[n]+=matrix[r-(z-i)][z];
                                n++;
                            }
                        
                    }
                }
                else if(j>r)
                {
                    for(int k=0;k<4;k++)
                    {
                        if(k<i)
                        {if(i-k<=3-r)
                        {
                            for(int z=i;z>=k;z--)
                                S[n]+=matrix[r+(i-z)][z];
                            n++;
                        }}
                        else if(k>i)
                            if(k-i<=3-r)
                            {
                                for(int z=i;z<=k;z++)
                                    S[n]+=matrix[r+(z-i)][z];
                                n++;
                            }
                        
                    }
                }
                
            }
        }
    
    //
    //hashing
    
    //list<string> HashTable[1000];
    
    fstream file;
    file.open("wordList4.txt",ios::in);
    int count=0;
    string temp;
    int k=0;
a:
    list<string> HashTable[1000];
    while(!file.eof() && k<1000)
    {
        k++;
        count++;
        file >> temp;
        //if(temp == "a")
        //cout<<hash1(temp)<<"***********\n";
        insertH(HashTable,temp);
    }
    k=0;
    //if(!file.eof())
    //    goto a;
    //cout<<count<<endl;
    ///
    string s = "ball";
    //cout<<searchH(HashTable,s)<<" "<<hash1(s) <<s<<"WEWEWEEW\n";
    //cout<<searchH(HashTable,S[3])<<" "<<hash1(s) <<s<<"WEWEWEEW\n";
    //cout<<searchH(HashTable,S[3]);
    for(int i=0;i<n;i++)
    {
        int value = searchH(HashTable,S[i]);
        while(searchH(HashTable,S[i])==1)
            deleteH(HashTable,S[i]);
        //cout<<value<< S[i]<<endl;
        if(value==1)
            cout<<S[i]<<endl;
        
    }
    if(!file.eof())
    {
        k=0;
        //cout<<"*****\n";
        goto a;
    }
    file.close();
    return 0;
}