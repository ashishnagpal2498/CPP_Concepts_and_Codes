//Minimum Coin Change Problem
#include<iostream>
#include<cstring>
using namespace std;
int minCoins(int coins[],int amount,int n)
{
    if(amount==0) return 0;

    int coinsNeeded = INT_MAX;

    for(int i=0;i<n;i++)
    {
        if(amount-coins[i]>=0)
        {
            int smallAns = minCoins(coins,amount-coins[i],n);
            if(smallAns!=INT_MAX)
            {
                coinsNeeded = min(coinsNeeded,smallAns+1);
            }
        }
    }
    return coinsNeeded;
}
int minCoinsDP(int*coins,int amount,int n)
{
    int*dp = new int[amount+1];
    
    //memset(dp,INT_MAX,(amount+1)*sizeof(int));
    dp[0]=0;
    for(int rupay=1;rupay<=amount;rupay++)
    {   dp[rupay] = INT_MAX;
        for(int i=0;i<n;i++)
        {
            if(coins[i]<=rupay)
            {
                int smallAns = dp[rupay-coins[i]];
                if(smallAns!=INT_MAX)
                {
                    dp[rupay] = min(dp[rupay],smallAns+1);
                }
            }
        }
    }
    return dp[amount];
}
int main(int argc, char const *argv[])
{
    int coins[] = {1,7,10};
    int n = sizeof(coins)/sizeof(int);
    int amount = 15;
    cout<<"MIN COINS "<<minCoins(coins,amount,n);
    cout<<endl<<"Min "<<minCoinsDP(coins,amount,n);
    return 0;
}