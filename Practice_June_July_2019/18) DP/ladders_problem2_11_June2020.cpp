// Ladders Problem
#include<iostream>
using namespace std;
int ways(int n ,int k)
{
    int * dp = new int[n];

    dp[0] = 1;

    for(int step=1;step<=n;step++)
    { dp[step] = 0;
        for(int i=1;i<=k;i++)
        {
            if((step-i)>=0)
            {
                dp[step]+=dp[step-i];
            }
        }
    }
    // cout<<"First -- \n";
    // for(int i=1;i<=n;i++){cout<<i<<" -> "<<dp[i]<<endl;}
    return dp[n];
}
int waysOptimised(int n,int k)
{
    int * dp = new int[n];
    dp[0] = 1;
    for(int step=1;step<=n;step++)
    {
        dp[step] =0;
        if(step-k>0)
        {
            dp[step] = 2*dp[step-1] - dp[step - k];
        }
        else{
            for(int i=0;i<step;i++)
            {
                dp[step]+=dp[i];
            } 
        }
    }
    // for(int i=1;i<=n;i++) {cout<<i<<" -> "<<dp[i]<<endl;}
    return dp[n];
}
int main()
{
    int n,k;
    cin>>n>>k;
    cout<<ways(n,k)<<endl;
    cout<<waysOptimised(n,k)<<endl;
}