//Implementing of queues using stack
#include<iostream>
#include<stack>
using namespace std;
class queue_2_stack{
    stack<int> s1;
    stack<int> s2;
    int active_stack ;
public:
    queue_2_stack()
    {
        active_stack =1;
    }
    void Enqueue(int data)
    {
        if(active_stack==1)
        {
            s1.push(data);
        }
        else{
           while(!s2.empty())
           {
            s1.push(s2.top());
            s2.pop();
           }
            s1.push(data);
            active_stack = 1;
         }
    }
    void dequeue()
    {
        // If stack 1 has values then stack 2 will be empty;
        if(active_stack==1)
        {   
            //stack 1 ko khali karna hai and put elements in stack two
           while(!s1.empty())
           {
                if(s1.size()==1)
                {
                // remove the last element , which was entered 1st
                s1.pop(); break;
                }
                s2.push(s1.top());
                s1.pop();
           }
           active_stack =2;      
        }
        else{
            s2.pop();
        }
    }
    void print()
    {   if(active_stack==1)
            { while(!s1.empty())
                {   if(s1.size()==1)
                    {
                        cout<<s1.top();
                    }
                    s2.push(s1.top());
                    s1.pop();
                   
                }
             active_stack =2;
        }
        else
        {
            cout<<s2.top();
        }
    }
};
// void pop_queue(stack<int>&s)
// {
//     stack<int> s2;
//     while(!s.empty())
//     {    if(s.size()==1)
//             {
//                 // remove the last element , which was entered 1st
//                 s.pop(); break;
//             }
//         s2.push(s.top());
//         s.pop();
//     }
//     while(!s2.empty())
//     {
//         s.push(s2.top());
//         s2.pop();
//     }
//     // time out -
//     return;
// }
// void print_queue(stack<int> s1)
// {
//     // while(!s1.empty())
//     // Recursion
//     //Base case
//     if(s1.empty())
//     {
//         return;
//     }

//     // recursive case

//     int topele = s1.top();
//     s1.pop();
//     print_queue(s1);
//     cout<<topele<<" ";
// }
// void print_top(stack<int>s1)
// {
//     stack<int>s2;
//     while(!s1.empty())
//     {
//         if(s1.size==1)
//         {
//             cout<<s1.top();
//                 return;
//         }
//         s2.push(s1.top())
//         s1.pop();
//     }

// }

int main()
{   queue_2_stack q1;

    // stack<int>  s1;
    int query,n,value;
    cin>>n;
    while(n>0)
    {
        cin>>query;
        switch(query)
        {
            case 1 : cin>>value;
                        q1.Enqueue(value);
                        break;
            case 2 : q1.dequeue();
                        break;
            case 3 : q1.print();
                        break;
        }
        n--;
    }
    return 0;
}