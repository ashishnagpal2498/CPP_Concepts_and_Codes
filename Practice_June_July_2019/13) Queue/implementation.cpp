//Queue Implementation
#include<iostream>
using namespace std;
class Queue{
    int f;
    int rear;
    int *arr;
    int cs ;
    int ms;
public:
    Queue(int ds =5)
    {
        f = 0;
        rear = ds-1;
        arr = new int[ds];
        cs =0;
        ms = ds;
    }
    void push(int d)
    {
        if(!isFull())
        {
            rear = (rear+1)%ms;
            arr[rear] = d;
            cs++;
        }
    }
    void pop()
    {
        if(!isEmpty())
        {
            f= (f+1)%ms;
            cs--;
        }
    }
    int front()
    {
        if(!isEmpty())
        {
            return arr[f];
        }
    }
    bool isFull()
    {
        return cs==ms;
    }
    bool isEmpty()
    {
        return cs ==0;
    }
};
void print(Queue q)
{
    while(!q.isEmpty())
    {
        cout<<q.front()<<" ";
        q.pop();
    }

}
int main()
{
    Queue q;
    for(int i=1;i<7;i++)
    {
        q.push(i);
    }
    print(q);
return 0;
}