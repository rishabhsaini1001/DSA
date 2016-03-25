#include <stdio.h>
#include <iostream>
#include <algorithm>
#include <string>
using namespace std;
int top1=-1;
int top2=-1;
void push1(char **A,char *B)
{
    if(top1<100000)
    {
       strcpy(A[++top1],B);  
    }
}
char* pop1(char **A)
    {
    if(top1>-1)
        return A[top1--];
    else
        return "oops";
}
void push2(char **A,char *B)
{
    if(top2<100000)
    {
       strcpy(A[++top2],B);  
    }
}
char* pop2(char **A)
    {
    if(top2>-1)
        return A[top2--];
    else
        return "oops";
}
void strrev1(char * A,char *B)
{
    int len=strlen(A);
   // char B[50];
    int j=len-1;
    int i=0;
    while(j>=0)
    {
        B[i++]=A[j--];
    }
    B[i]='\0';
    //return B;
}    
char compare(char *A,char *B){
    int a=strlen(A);
    int b=strlen(B);
    //int i=0,j=0;
    int flag=0;
    if(a!=b)
        return 'n';
    else
     {
        for(int i=0;i<a;i++)
           {
             if(A[i]==B[i] || ((int)(A[i])+32)==(int)B[i] || ((int)(B[i])+32)==(int)A[i])
               {
                 flag=1;
             }
            else
                { 
                    flag=0;
                    break;
                }
        }    
        
    if(flag==0)
        return 'n';
    else if(flag==1)
        return 'y';
    }
}
int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */
    /*char a;
    a='A';
    cout<<(int)a;*/
    char A[50];
    gets(A);
    if(A[0]=='\0')
        cout<<"INPUT IS NULL";
    else{
    int len=strlen(A);
    int i=0,j=len-1;
    char **stack1,**stack2;
    int flag1=0;
    while(i<len && j>=0 && i<j)
    {
        char B[50],C[50];
        int k1=0,k2=0;
        while(A[i]!=' ' && i<len)
            {
            B[k1++]=A[i++];
        }
        B[k1]='\0';
        i++;
        while(A[j]!=' ' && j>=0)
            {
            C[k2++]=A[j--];
        }
        C[k2]='\0';
        j--;
        char C1[50]="\0";
        strrev1(C,C1);
        push1(stack1,B);
        push2(stack2,C);
        //////////////////////////////////////////////////////direct approach/////////////////*
        //char c=compare(B,C1);
        //cout<<endl<<B<<c<<C1<<endl;
        ///
        /*
        if(c=='n')
            {
                flag1=0;
                break;
            }
        else if(c=='y'||i>j)
            {flag1=1;}
        *////
    }
    //cout<<compare("tHiS","Thin");
    /*
    while(top1>-1)
    {
        char *A=pop1(stack1);
        char *B=pop2(stack2);
        char c=compare(B,A);
        //cout<<endl<<B<<c<<C1<<endl;
        ///
        int flag1=0;
        if(c=='n')
            {
                flag1=0;
                break;
            }
        else if(c=='y'||i>j)
            {flag1=1;}
    }*/
    if(flag1==0)
        {
        cout<<"SENTENCE IS NOT A PALLINDROME";
    }
    else
        cout<<"SENTENCE IS A PALLINDROME";
    }
    return 0;
}