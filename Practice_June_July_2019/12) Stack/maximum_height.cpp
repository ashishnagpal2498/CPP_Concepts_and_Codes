//maximum height -
#include<iostream>
#include<stack>
using namespace std;
bool equalHeight(stack<int> s1,stack<int> s2,stack<int>s3)
{
    int h1=0,h2=0,h3=0;
    while(!s1.empty())
    {
        h1+=s1.top();
        s1.pop(); 
    }
    while(!s2.empty())
    {
        h2+=s2.top();
        s2.pop(); 
    }
    while(!s3.empty())
    {
        h3+=s3.top();
        s3.pop(); 
    }
    bool ans = (h1 == h2);
    return ans == h3;
}
int calHeight(stack<int>copy)
{
     int h =0;
        // stack<int> copy = s1;
        while(!copy.empty())
        {
            h+=copy.top();
            copy.pop();
        }
        return h;
}
int maxHeight(stack<int>&s1,stack<int>&s2,stack<int>&s3,int n,int m,int p,int sum1,int sum2,int sum3)
{   int h=0;
    int d1=0,d2=0,d3=0;
   while(1)
   {
    if(d1==n||d2==m||d3==p)
    {
        h =0;
        return h;
    }
    if(sum1==sum2&&sum2==sum3)
    {   //cout<<sum1<<" "<<sum2<<"  "<<sum3<<endl;
        return sum1;
    }
    if(sum1>=sum2&&sum1>=sum3)
    {
        d1++;
       // cout<<sum1<<" "<<sum2<<"  "<<sum3<<" Reducing sum1 "<<endl;
        sum1-=s1.top();
        s1.pop();
    }
    else if(sum2>=sum1&&sum2>=sum3)
    {
        d2++;
     //cout<<sum1<<" "<<sum2<<"  "<<sum3<<" Reducing sum2 "<<endl;
        sum2-=s2.top();
        s2.pop();
    }
    else
    {
        d3++;
        sum3-=s3.top();
     //   cout<<sum1<<" "<<sum2<<"  "<<sum3<<" Reducing sum3 "<<endl;
        s3.pop();
    }
   }
    return 0;
}
void pushAtBack(stack<int>&s,int topElement)
{
    if(s.empty())
    {
        s.push(topElement);
        return;
    }
    int t = s.top();
    s.pop();
    pushAtBack(s,topElement);
    s.push(t);
    return;
}
void reverseStack(stack<int>&s)
{
    if(s.empty())
    {
        return;
    }
    int topElement = s.top();
    s.pop();
    reverseStack(s);
    pushAtBack(s,topElement);
}
int main()
{    int n,m,p;
    cin>>n>>m>>p;
    int sum1=0,sum2=0,sum3=0;
    stack<int> s1,s2,s3;
    int d;

    for(int i=0;i<n;i++)
    {
        cin>>d;
        sum1+=d;
        s1.push(d);
    }
    for(int i=0;i<m;i++)
    {
        cin>>d;
        sum2+=d;
        s2.push(d);
    }
    for(int i=0;i<p;i++)
    {
        cin>>d;
        sum3+=d;
        s3.push(d);
    }
    reverseStack(s1);
    reverseStack(s2);
    reverseStack(s3);
    cout<<maxHeight(s1,s2,s3,n,m,p,sum1,sum2,sum3);
    return 0;
}