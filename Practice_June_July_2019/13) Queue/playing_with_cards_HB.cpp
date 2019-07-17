//Playing With Cards
#include<iostream>
#include <stack>
#include<queue>
using namespace std;
int prime[10005];
void primes ()
{
    prime[1] = 2;
    prime[2] = 3;
    int m=3;
    for(int i=5;i<10005;i+=2)
    {   bool flag = true;
        for(int j=2;j*j<=i;j++)
        {
            if(j%i==0)
            {
                flag = false;
                break;
            }
        }
        if(flag)
        {
            prime[m++] = i;
        }
    }
}
void casino_game(stack<int> s,int n,int q)
{   stack<int> B;
    queue<int> A;
    int i=1;

    while(i<=q)
    {   int sz = s.size();
        int j=0;
        while(j<sz)
        {   cout<<"Inner While  "<<endl;
            int top_ele = s.top();
            s.pop();
            if((top_ele%prime[i])==0)
            {
                B.push(top_ele);

            }
            else
            {
                A.push(top_ele);
            }
        j++;
        }
        while(!A.empty())
        {
            s.push(A.front());
            A.pop();
        }
        while(!B.empty())
        {
         cout<<B.top()<<endl;
            B.pop();
        }
        i++;
    }
    
    while(!s.empty())
    {
        cout<<s.top()<<endl;
        s.pop();
    }
}
int main()
{
    int n,q;
    stack<int>s;
    cin>>n>>q;
    int arr;
    primes();
    cout<<"Calculated Primess"<<endl;
    for(int i=0;i<n;i++)
    {
        cin>>arr;
        s.push(arr);
    }
    casino_game(s,n,q);
    return 0;
}