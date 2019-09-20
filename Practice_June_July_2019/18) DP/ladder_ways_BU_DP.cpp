//Ladder Problem Using Dp
#include<iostream>
using namespace std;

int waysBottomUp_DP(int n,int k)
{
    int* dp = new int[n+1];
    dp[0] = 1;
    for(int step=1;step<=n;step++)
    {
        //for each step - previous k se jumps
        dp[step]=0;
        for(int i=1;i<=k;i++)
        {
            if((step-i)>=0)
            {
                dp[step]+=dp[step-i];
            } 
        }
    }
    return dp[n];
}

//complexity reduced Bottom Up
int reducedBU_DP(int n,int k)
{
    int*dp = new int[n+1];
    dp[0] = 0;
    dp[1]=1;
    for(int i=2;i<=n;i++)
    {   if((i-k)>=0)
        dp[i] = 2*dp[i-1] - dp[i-k];
        else dp[i] = 2*dp[i-1];  
    }
    return dp[n];
}

int main(int argc, char const *argv[])
{
    int n=5,k=3;
    cout<<"NO.OF WAYS "<<waysBottomUp_DP(n,k)<<endl;
    cout<<"Dp Optimised - "<<reducedBU_DP(n,k);
    return 0;
}