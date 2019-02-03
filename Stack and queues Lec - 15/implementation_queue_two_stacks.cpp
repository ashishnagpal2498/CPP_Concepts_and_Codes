//implementation of queue using two stack;
#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include<stack>
using namespace std;


int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */   
    stack<int> front,rear;
    int testcase;
    cin>>testcase;
    while(testcase--)
    {
        int type,val;
        cin>>type;
        if(type==1)
        {   cin>>val;
            rear.push(val);
        }
        else{
            if(front.empty())
            {
                while(!rear.empty())
                {
                    front.push(rear.top());
                    rear.pop();
                }
                //front.pop();
            }
            if(!front.empty())
            {
                if(type==2) front.pop();
                if(type==3) cout<<front.top()<<endl;
            }
        }
    }
    return 0;
}