//Queues
#include<iostream>
#include<stack>
using namespace std;
void print_stack(stack<int> s)
{
    while(!s.empty())
    {
        cout<<s.top()<<"  ";
        s.pop();
    }
    cout<<endl;
}
class Queue{
    int * arr; //Dynamic array 
    int rear;
    int frt;
    int cs ; //Current size of the queue;
    int ms ; //Max size of the queue ;
public:
    Queue(int ds = 5)
    {
        arr = new int[ds];
        cs = 0;
        ms = ds;
        frt = 0;
        rear = ms -1;
    }
    void push(int data)
    {
        if(!isFull())
        {
            rear = (rear+1) % ms;
            arr[rear] = data;
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
    int front()
    {
        if(!isEmpty())
        {
            return arr[frt];
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
    
};
// reverse of queue
void reverse_queue(Queue &q)
    {
        stack<int> s;
        cout<<endl<<"Inside func"<<endl;

        // while(!q.isEmpty())
        // {
        //     cout<<q.front()<<"  ";
        //     q.pop();

        // }

        while(!q.isEmpty())
        {   cout<<q.front()<<" ";
            s.push(q.front()); 
            q.pop();
        }
        cout<<"Elements done in stack";
        print_stack(s);
        while(!s.empty())
        {
            q.push(s.top());
            s.pop();
        }
    }
int main()
{
    Queue q1;
    // q1.push(4);
    for(int i=1;i<6;i++)
        q1.push(i);
    // while(!q1.isEmpty())
    //     {
    //         cout<<q1.front()<<"  ";
    //         q1.pop();

    //     }

    // cout<<q1.front()<<endl;
    // q1.push(9);
    cout<<"elemnts pushed";
   reverse_queue(q1);
    cout<<"func run succ \n";
    while(!q1.isEmpty())
        {
            cout<<q1.front()<<"  ";
            q1.pop();
        }

    return 0;
}