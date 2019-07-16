//reverse A stack
#include<iostream>
#include<stack>
using namespace std;

void insertAtBottom(stack<int>&s,int topElement)
{
    stack<int> temp;
    while(!s.empty())
    {
        temp.push(s.top());
        s.pop();
    }
    s.push(topElement);
    while(!temp.empty())
    {
        s.push(temp.top());
        temp.pop();
    }
}
void reverseStack(stack<int> &s)
{
    if(s.empty())
    {
        return;
    }
    int topElement = s.top();
    s.pop();
    reverseStack(s);
    insertAtBottom(s,topElement);
}
ostream& operator<<(ostream& ob,stack<int> s)
{
    while(!s.empty())
    {
        ob<<s.top()<<" ";
        s.pop();
    }
    return ob;
}

int main(int argc, char const *argv[])
{
    stack<int> s;
    int n;
    cin>>n;
    int d;
    for(int i=0;i<n;i++)
    {
        cin>>d;
        s.push(d);
    }
    cout<<s;
    reverseStack(s);
    cout<<endl<<s;
    return 0;
}