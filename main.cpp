//
//  main.cpp
//  hashing
//
//  Created by sushil on 03/04/16.
//  Copyright © 2016 rishabh. All rights reserved.
//
/*
#include <iostream>
#include<fstream>
using namespace std;
int main(int argc, const char * argv[]) {
    // insert code here...
    fstream file,outputfile;
    file.open("wordList.txt",ios::in);
    outputfile.open("wordList4.txt", ios::out | ios::trunc);
    int count=0;
    string temp;
    int k=0;
a:
        while(!file.eof())
        {
            k++;
            count++;
//            string temp;
            file >> temp;
            //outputfile>>temp;
            //dictionary.insert(pair<char,string>(temp[0],temp));
            if(temp.length()<=4)
            {
                //cout<<temp<<endl;
                temp+="\n";
                outputfile << temp;
            }
        }
    //cout<<temp<<endl;
    k=0;
    //if(!file.eof())
      //  goto a;
    cout<<count;
    file.close();
    outputfile.close();
        
        
    //
    return 0;
}*/
