//maximum element - Stacks
#include<iostream>
#include<stack>
using namespace std;
int main()
{
    int n;
    cin>>n;
    int q;
    stack<int> s;
    stack<int> ms;
    while(n--)
    {
        cin>>q;
        int data;
        int ele ;
        switch(q)
        {
            case 1 : //push the element onto stack
                        cin>>data;
                        s.push(data);
                        if(ms.empty()||ms.top()<data)
                           ms.push(data);
                           break;
             case 2:  //delete the element
                        ele = s.top();
                        s.pop();
                        if(ms.top()==ele)
                        {
                            ms.pop();
                        }            
                        break;
              case 3 : //Show maximum element -
                        cout<<ms.top()<<endl;
                        break;             
        }
    }
    return 0;
}