//Implementation of stack using two queues
//Stack uses LIFO technique , hence-
#include<iostream>
#include<queue>
using namespace std;



class TwoQueues{
    queue<int> q1;
    queue<int> q2;
    int active_queue;
public:
    //By default we say q1 is the active queue;
        TwoQueues()
        {
            active_queue=1;
        }
    void push(int data)
    {   //cout<<"element pushed is  "<<data<<endl;
        if(active_queue==1)
        {
            q1.push(data);
        }
        else
        {
            q2.push(data);
        }
    }
    void pop()
    {
        //popping as a stack , so last element to be entered will go
        if(active_queue==1)
        {
            while(!q1.empty())
            {
                if(q1.back()==q1.front())
                {   q1.pop();
                    break;
                }
                q2.push(q1.front());
                q1.pop();
            }
            active_queue=2;
        }
        else{
             while(!q2.empty())
            {
                if(q2.back()==q2.front())
                {   q2.pop();
                    break;
                }
                q1.push(q2.front());
                q2.pop();
            }
        }
        active_queue=1;
    }
    int top()
    {
        //popping as a stack , so last element to be entered will go
        if(active_queue==1)
        {
            while(!q1.empty())
            {   //cout<<"back element  "<<q1.back()<<"  front element"<<q1.front()<<endl;
                if(q1.back()==q1.front())
                {   int tp = q1.front();
                    q2.push(q1.front());
                    q1.pop();
                     active_queue=2;
                    return tp;
                }
                q2.push(q1.front());
                q1.pop();
            }
           
        }
        else{
             while(!q2.empty())
            {
                if(q2.back()==q2.front())
                {   int tp = q2.front();
                    q1.push(q2.front());
                    q2.pop(); 
                    active_queue=1;
                    return tp;
                }
                q1.push(q2.front());
                q2.pop();
            }
        }
        
    }
    bool empty_func()
    {   if(active_queue==1)
        {   //cout<<"active queue is  "<<active_queue;
            return q1.empty();}
        else{ //cout<<"it is  2";
            return q2.empty();
        }
    }
};

void print(TwoQueues s1)
{
     while(!s1.empty_func())
    {
        cout<<s1.top()<<" ";
        s1.pop();
    }
    cout<<endl;
}
int main()
{
    TwoQueues s1;
    for(int i=1;i<=5;i++)
    {
        s1.push(i);
    }
   // s1.pop();
    // cout<<s1.empty_func();
    print(s1);
    s1.push(99);
    print(s1);
    // Stack using two queue;
    return 0;
}