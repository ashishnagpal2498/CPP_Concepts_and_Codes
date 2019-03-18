//Minimum coin change problem
#include<iostream>
using namespace std;
int minCoins(int coins[],int amount,int n)
{
    // Base case-
    if(amount==0)
    {
        return 0;
    }

    int CoinsNeeded = INT_MAX;
    // int ans = 0;
    for(int i=0;i<n;i++)
    {   
        if(amount-coins[i]>=0)
        {
           // amount=amount - coins[i];
            int smallercoins = minCoins(coins,amount-coins[i],n);
            if(smallercoins!=INT_MAX)
            {
                CoinsNeeded = min(CoinsNeeded,smallercoins+1);
            } 
            
        }

    }
    return CoinsNeeded;
}
// Dp - coins min change
int minChangeBottomUpDp(int coins[],int amount,int n)
{
    int *dp = new int[amount+1];
    dp[0] = 0;
    for(int i=1;i<=amount;i++)
    {
        dp[i] = INT_MAX;
    }
    for(int rupay = 1;rupay<=amount;rupay++)
    {   
        //starting from the initial to reach the final state;
        for(int i=0;i<n;i++)
        {
            //DP - check if the coin value is less-
            if(rupay>=coins[i])
            {
                int smallAns = dp[rupay - coins[i]];
                if(smallAns!=INT_MAX)
                {
                    dp[rupay] = min(dp[rupay],smallAns+1);
                }
            }
        }
    }
    return dp[amount];
}
int main()
{
    int coins[] = {1,7,10};
    int amount = 15;
    int n = 3;
    cout<<minCoins(coins,amount,n);
    cout<<endl<<minChangeBottomUpDp(coins,amount,n);
    return 0;
}