#include<iostream>
#include<stack>
using namespace std;

void print(stack<int> S)
{
    while(!S.empty())
    {
        cout<<S.top()<<endl;
        S.pop();
    }
}

int main()
{
    stack<int> s;
    for(int i=0;i<5;i++)
    {
        s.push(i+1);
    }
    print(s);
    return 0;
}