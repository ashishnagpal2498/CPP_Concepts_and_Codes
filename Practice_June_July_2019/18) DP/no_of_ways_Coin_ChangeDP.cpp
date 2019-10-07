//No. of ways - Coin Change Problem
#include<iostream>
using namespace std;
int dp[100] ={0};
int noOfWaysTopDown(int amount,int coins[],int n)
{
    if(amount==0) 
    {   dp[0]=1;
        return 1;
    }

    int ans=0;
    if(dp[amount]!=0) return dp[amount];
    for(int i=0;i<n;i++)
    {
        if(amount-coins[i]>=0)
        ans+= noOfWaysTopDown(amount-coins[i],coins,n); 
    }
    dp[amount]= ans;
    return ans;   
}
int noofWays_CoinChange(int amount,int coins[],int n)
{
    if(amount==0) return 1;

    int ans=0;
    for(int i=0;i<n;i++)
    {
        if(amount-coins[i]>=0)
        ans+= noofWays_CoinChange(amount-coins[i],coins,n); 
    }
    return ans;
}
//Bottom Up-

int main()
{
    int coins[] ={1,7,10};
    int amount =15;
    int n = sizeof(coins)/sizeof(int);
    cout<<"No of ways - "<<noofWays_CoinChange(amount,coins,n);
    return 0;
}