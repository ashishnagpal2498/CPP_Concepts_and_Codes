//implementation of stack using a single queue
// push , normal way , while poping and top , go till n-1 elements;
#include<iostream>
#include<queue>
using namespace std;
class Stack_1_queue{
    queue<int> q1;
public:
    void push(int ele)
    {
        q1.push(ele);
    }
    void pop()
    {   int last_ele = q1.back();
        //go till n-1
        while(!q1.empty())
        {
            if(last_ele==q1.front())
            {
                //reached the last element;
                q1.pop();
                return ;
            }
            int ele = q1.front();
            q1.pop();
            q1.push(ele);
        }
    }
    int top()
    {
        return q1.back();
    
    }
    bool empty()
    {
        return q1.empty();
    }
};
void print(Stack_1_queue s1)
{
    while(!s1.empty())
    {
        cout<<s1.top()<<"  ";
        s1.pop();
    }
    cout<<endl;

}
int main()
{
    Stack_1_queue s1;
    for(int i=1;i<6;i++)
    {
        s1.push(i);
    }
    print(s1);
return 0;
}