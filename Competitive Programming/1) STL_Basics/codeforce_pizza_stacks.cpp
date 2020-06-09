//Give me this pizza - codeForce
#include<iostream>
#include<stack>
#include<deque>
#define ll long long
using namespace std;
ll arr[100005];
int n;
int main()
{
    cin>>n;
    for(int i=0;i<n;i++) cin>>arr[i];
    deque<ll> d;    
    stack<ll> s;
    for(int i=n-1;i>= 0;i--)
    {   
        if(s.empty()) {
            s.push(i);
            d.push_front(-1);
        }
        else if(!s.empty() && arr[s.top()]>arr[i]) {
            d.push_front(arr[s.top()]);
            s.push(i);
        }
        else{
            // cout<<"Else part "<<endl;
            while(!s.empty() && arr[s.top()]<=arr[i])
            {
                s.pop();
            }
            if(s.empty())
            {
                d.push_front(-1);
            }
            else{
                d.push_front(arr[s.top()]);
            }
            s.push(i);
        }
        // cout<<d.front()<<" ";

    }
    for(auto a: d)
    {
        cout<<a<<" ";
    }

}
