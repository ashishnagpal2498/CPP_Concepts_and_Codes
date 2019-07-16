//maximum height -
#include<iostream>
#include<stack>
using namespace std;
bool equalHeight(stack<int> s1,stack<int> s2,stack<int>s3)
int main()
{    int n,m,p;
    stack<int> s1,s2,s3;
    int d;

    for(int i=0;i<n;i++)
    {
        cin>>d;
        s1.push(d);
    }
    for(int i=0;i<m;i++)
    {
        cin>>d;
        s2.push(d);
    }
    for(int i=0;i<p;i++)
    {
        cin>>d;
        s3.push(d);
    }


    return 0;
}