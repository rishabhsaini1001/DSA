#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include<string.h>
using namespace std;

int main(){
    char time[10];
    cin >> time;
            int n=0;
    if(time[0]=='1' && time[1]=='2' && time[8]=='A')
    {
        time[8]=time[9]=32;
        time[0]=time[1]='0';
    } 
    else if(time[8]=='A' || (time[8]=='P' && time[0]=='1' && time[1]=='2'))
        {
        /*char time1[10];
        int i=0;
        while(i<8)
            time1[i]=time[i++];
        strcpy(time,time1);*/
        time[8]=time[9]=32;
    }
    else if(time[8]=='P')
        {
        n+=(int)time[1]-48;
        n+=((int)time[0]-48)*10;
        n+=12;
        time[0]=(char)(n/10+48);
    	time[1]=(char)(n%10+48);
                 time[8]=time[9]=32;

        //time[0]=(char)n/10;
        //cout<<n;
    }
    //int n=0;
    //n+=(int)time[0]-48;
    //cout<<(char)(n/10+48);
    //cout<<(char)(n%10+48);
    cout<<time;
    return 0;
}
