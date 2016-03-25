#include <map>
#include <set>
#include <list>
#include <cmath>
#include <ctime>
#include <deque>
#include <queue>
#include <stack>
#include <string>
#include <bitset>
#include <cstdio>
#include <limits>
#include <vector>
#include <climits>
#include <cstring>
#include <cstdlib>
#include <fstream>
#include <numeric>
#include <sstream>
#include <iostream>
#include <algorithm>
#include <unordered_map>
using namespace std;
struct node{
    int data;
    node *next;
};
void cyclicornot(node **head)
    {
    node *ptr=*head;
    node *fastptr=*head;
    if(*head!=NULL && (*head)->next!=NULL &&(*head)->next->next!=NULL)
    {    
        while(ptr!=fastptr)
            {
                if(ptr->next!=NULL)
                {
                ptr=ptr->next;
            }
            if(fastptr->next!=NULL && fastptr->next->next!=NULL)
                {
                fastptr=fastptr->next->next;
            }
        } 
        if(ptr==fastptr)
            cout<<"true";
        else
            cout<<"false";
    }
    cout<<"false";
}
using namespace std;
int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */
    node *head=NULL;
    int address;
    cin>>address;
    head=address;
    cyclicornot(&head);
    return 0;
}