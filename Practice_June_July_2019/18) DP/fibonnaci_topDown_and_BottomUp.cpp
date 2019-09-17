//DP - Top-Down Approach 
//DP - Bottom Up
#include<iostream>
#include<bits/stdc++.h>
using namespace std;

int topDown(int n,int* dp)
{
    if(n<0) return 0;
    if(n==0||n==1)
    {   dp[n] = n;
        return dp[n];
    }
    if(dp[n]!=-1)
    {
        return dp[n];
    }
    dp[n] = topDown(n-1,dp)+ topDown(n-2,dp);
    return dp[n];
}
int bottomUp(int n)
{
    int* dp = new int[n+1];
    dp[0] = 0; dp[1]= 1;
    for(int i=2;i<=n;i++)
    {
        dp[i] = dp[i-1]+dp[i-2];
    }
    return dp[n];
}
int main(int argc, char const *argv[])
{
    int n = 5;
    int* dp = new int[n+1];

    memset(dp,-1,(n+1)*sizeof(int));
    cout<<"Top Down - "<<topDown(n,dp)<<endl;
    cout<<"Bottom Up - "<<bottomUp(n)<<endl;
    return 0;
}
