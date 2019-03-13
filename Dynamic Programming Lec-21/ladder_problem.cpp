//Ladder Problem - Recursion and Dp
#include<iostream>
using namespace std;
int ways(int n)
{
    if(n<0)
    {
        return 0;
        // No case when 
    }
    if(n==1||n==0)
    {
        return 1;
    }
    int waysby1 = ways(n-1);
    int waysby2 = ways(n-2);
    int waysby3 = ways(n-3);
    // return ways(n-1) + ways(n-2) + ways(n-3);
    return waysby1+waysby2+waysby3;
}
//Top-Down Dp
int waysTopDownDp(int n,int *dp)
{
    if(n<0)
    {
        return 0;
    }
    if(n==0)
    {
        dp[0] = 1;
        return 1;
    }
    if(!dp[n]==-1)
    {
        return dp[n];
    }
    dp[n] = waysTopDownDp(n-1,dp) + waysTopDownDp(n-2,dp) + waysTopDownDp(n-3,dp);

    return dp[n];
}
// Bottom -up DP
// -0 
int wayskBottomUpDp(int n,int k)
{   int *dp = new int[n];
    if(n<0)
    {
        return 0;
    }
    // Steps to reach 0 is 1 way
    dp[0] = 1;
    for(int step=1;step<=n;step++)
    {   dp[step] = 0;
        for(int jump=1;jump<=k;jump++)
        {
            // step - jump - pichhe se aa rha h;
            //also this value can be -ve as- 1 ke liye nikalta hu-
            //to it will go to [step- jump ] 1-1 , 1-2 , 1-3 
            if(step-jump>=0)
            dp[step]+=dp[step-jump];
        }
    }
    return dp[n];
}

int main()
{
    int n;
    cin>>n;
    cout<<"no of ways"<<ways(n);
    int *arr;
    arr = new int[n+1];
    for(int i=0;i<=n;i++)
    {
        arr[i] = -1;
    }
    cout<<endl<<"Top-Down DP "<<waysTopDownDp(n,arr)<<endl;
    cout<<"Bottom up - "<<wayskBottomUpDp(n,3);
    return 0;
}
