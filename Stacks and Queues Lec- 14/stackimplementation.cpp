//Stack Implementation
#include<iostream>
//This file has the stack code , Header files created by user are included in " "
#include "stacks.h"
using namespace std;
void printS(Stack<int> s)
{   int sz = s.size();
    for(int i=0;i<sz;i++)
    {
        cout<<s.top()<<" ";
        s.pop();
    }
}
void print_stack_array(Stack_array s)
{   int sz = s.size();
    for(int i=0;i<sz;i++)
    {
        cout<<s.top_ele()<<" ";
        s.pop();
    }
}
int main()
{
    // Stack<int> s;
    // for(int i=0;i<5;i++)
    // {
    //     s.push(i);
    // }
    // printS(s);
    // cout<<endl;
    // printS(s);
    Stack_array S;
    for(int i=0;i<9;i++) {S.push(i);}
        print_stack_array(S);
    S.push(9);
    cout<<endl<<S.top_ele();
    S.push(10);

    return 0;
}