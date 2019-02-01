//Stacks - Basics 
//Implementation of stacks by arrays
//Stacks are datastructures which use LIFO
//Last in first out
#include<iostream>
#include<string>
using namespace std;
template<typename T>
class Stack{
    int top;
    T arr[100];
public:
    Stack()
    {
    top=-1;
    }
    void push(T n)
    {   if(top==99)
        {
            cout<<"Stack Full , cannot insert "<<endl;
            return ;
        }
        top++;
        arr[top] = n;
    }
    void pop()
    {
        if(top==-1)
        {
            cout<<"Cannot Pop as underflow"<<endl;
            return;
        }
        top--;
    }
    T topval()
    {
        return arr[top];
    }
    bool empty()
    {
        return top==-1;
    }
    int size()
    {
        return top+1;
    }
    void print(Stack<T> s)
    {
        while(s.top!=-1)
        {
            cout<<arr[s.top]<<"  ";
            s.top--;
        }
    }
};
int main()
{
    Stack<char> S;
    for(int i=0;i<5;i++)
    {
        S.push('a'+i);
    }
    S.print(S);

    Stack<string> s3;
    s3.push("World");
    s3.push("Hello");
    s3.print(s3);
    return 0;
}