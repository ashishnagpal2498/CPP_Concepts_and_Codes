//Implementation of queues
#include<iostream>
using namespace std;
class Queue{
    int frt;
    int rear;
    int *arr;
    int cs; //current size
    int ms; //maximum size;
public:
    Queue(int d=5)
    {   arr = new int[d];
         frt = 0;
        ms = d;
        cs=0;
        rear = ms-1;
    }
    void push(int ele)
    {
        if(!isFull())
        {
            rear = (rear+1) % ms;
            //This is done becoz if the array goes out of the address ;
            //it comes back to zeroth position if empty;
            arr[rear] = ele;
            cs++;
        }
    }
    void pop()
    {
        if(!isEmpty())
        {
            frt = (frt+1) % ms;
            cs--;
        }
    }
    bool isEmpty()
    {
        return cs==0;
    }
    bool isFull()
    {
        return cs==ms;
    }
    int front()
    {
        return arr[frt];
    }
    int size()
    {
        return cs;
    }
};
void print(Queue q1)
{
    int sz=q1.size();
    for(int i=0;i<sz;i++)
    {
        cout<<q1.front()<<"  ";
        q1.pop();
    }
}
int main()
{
    Queue q1;
    for(int i=0;i<4;i++)
    {
        q1.push(i);
    }
    print(q1);
    return 0;
}