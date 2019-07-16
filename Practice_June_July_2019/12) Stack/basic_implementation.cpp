//StackS Implementation
#include<iostream>
#include<vector>
using namespace std;
template<typename T>
class Stack{
    vector<T>arr;
public:
    void push(T d)
    {
        arr.push_back(d);
    }
    void pop()
    {
        arr.pop_back();
    }
    T top()
    {
        return arr[arr.size()-1];
    }
    bool isEmpty()
    {
        return arr.size();
    }
};
void print(Stack<int> s)
{   
    while(s.isEmpty())
    {
        cout<<s.top()<<"  ";
        s.pop();
    }
}
int main(int argc, char const *argv[])
{
    Stack<int> s;
    int n; cin>>n;
    for(int i=0;i<n;i++) {s.push(i*i);}
    print(s);
    return 0;
}
