//reverse a stack 
#include<iostream>
#include<stack>
using namespace std;
void print(stack<int> s)
{
    while(!s.empty())
    {
        cout<<s.top()<<endl;
        s.pop();
    }
    return ;
}

void insertAtBack(stack<int> &s,int element)
{
    stack<int> temp;
    while(!s.empty())
    {
        temp.push(s.top());
        s.pop();
    }
    s.push(element);
    while(!temp.empty())
    {
        s.push(temp.top());
        temp.pop();
    }
}

//Insert at bottom using recursion
void insertAtBack_Recursion(stack<int> &s,int element)
{
    //basecase 
    if(s.empty())
    {
        s.push(element);
        return;
    }
    int topval = s.top();
    s.pop();
    insertAtBack_Recursion(s,element);
    s.push(topval);
}

//Reverse a stack using recursion
void reverse_stack(stack<int> &s)
{
    //Base case -
    if(s.empty())
    {
        return;
    }

    //recursive case;
    int topElement = s.top();
    s.pop();
    reverse_stack(s);
    insertAtBack(s,topElement);
}

int main()
{
    stack<int> s;
    for(int i=1;i<=4;i++)
    {
        s.push(i);
    }
    print(s);
    reverse_stack(s);
    cout<<endl;
    print(s);
    return 0;
}