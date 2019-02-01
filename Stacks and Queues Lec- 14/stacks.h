//Stacks - Using Arrays
#include<iostream>
#include<vector>
using namespace std;
template<typename T>
class Stack{
public:
    vector<T> ab;
    void push(T d)
    {
        ab.push_back(d);
    }
    void pop()
    {   
        ab.pop_back();
    }
    T top()
    {
        return ab[ab.size()-1];
    }
    bool empty()
    {
        return ab.size()==0;
    }
    int size()
    {
        return ab.size();
    }
};
class Stack_array{
    int top;
    int sz;
    int arr[10];
public:
    Stack_array()
    {
        top=-1;
        sz=0;
    }
    void push(int val)
    {   
        if(top == sz-1&&sz==10)
        {
            //1st element;
            cout<<"Stack full \n";
        }
        else{
        top++;    
            arr[top]=val;
        sz++;
        }
    
    }
    void pop()
    {
        if(top==-1)
        {
            cout<<"UnderFlow \n";
            return;
        }
        top--;
        sz--;
    }
    int top_ele()
    {
        return arr[top];
    }
    bool isempty()
    {
        return top==-1;
    }
    int size()
    {
        return sz;
    }
};