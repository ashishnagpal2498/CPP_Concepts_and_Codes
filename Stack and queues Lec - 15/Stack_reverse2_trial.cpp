//Stack - Implementation
//Reverse a stack
#include<iostream>
#include<stack>
using namespace std;
void print(stack<int> S)
{
    while(!S.empty())
    {
        cout<<S.top()<<"  ";
        S.pop();
    }
    cout<<endl;
    return;
}
void insertatback(stack<int>& s , int topele)
{
    // Recursive case , or iterative case
    if(s.empty())
    {
        s.push(topele);
        return;
    }
    int ele = s.top();
    s.pop();
    insertatback(s,topele);
    s.push(ele);
}

void reverse_stack(stack<int> & s)
{
    if(s.empty())
    {
        return;
    }
    int topele = s.top();
    s.pop();
    reverse_stack(s);
    insertatback(s,topele);
}

int main()
{
    stack<int> S;
    //inserting elements into stack
    for(int i=1;i<=5;i++)
    {
        S.push(i);
    }
    print(S);
    reverse_stack(S);
    print(S);
    return 0;
}