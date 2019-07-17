//Implementation of Queue using two stacks
#include<iostream>
#include<stack>
using namespace std;
class Queue{
    stack<int> f;
    stack<int> rear;
    bool active;
public:
    Queue(){
        active = false;
    }
    void push(int d)
    {   rear.push(d);
        
    }
    void pop()
    {
       
        if(f.empty())
        {
            while(!rear.empty())
            {
                f.push(rear.top());
                rear.pop();
            }
            // Poping the element from Queue;
            f.pop();
            return;
        }
        f.pop();
    }
    int front()
    {
        if(f.empty())
        {
            while(!rear.empty())
            {
                f.push(rear.top());
                rear.pop();
            }
            // Poping the element from Queue;
            return f.top();
            
        }
       return f.top();
    }
    bool isEmpty()
    {
        return rear.empty()&&f.empty();
    }

};
void print(Queue q1)
{
    while(!q1.isEmpty())
    {
        cout<<q1.front()<<" ";
        q1.pop();
    }
}
int main()
{
    Queue q1;
    for(int i=0;i<5;i++)
        q1.push(i);
    print(q1);
    q1.pop();
    cout<<endl;
    print(q1);
    return 0;
}