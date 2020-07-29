// Coin change problem 
#include<iostream>
using namespace std;
int minCoins(int coins[],int amount, int n)
{
    if(amount == 0) return 0;

    int coinsNeeded = INT_MAX;
    for(int i=0;i<n;i++)
    {   
        if(amount - coins[i]>=0){
            // Coins required to make - (amount - coins[i]) - value -
         int coinsReq = minCoins(coins,amount-coins[i],n);
           if(coinsReq !=INT_MAX)
           {
                 coinsNeeded = min(coinsReq+1,coinsNeeded);
           }
        }
       
    }
    return coinsNeeded;
}
int coinsNeededBU(int coins[],int amount,int n)
{
    int* dp = new int[amount+1];
    // starting from amount 1 -
    dp[0] = 0;
    for(int rupay = 1; rupay<=amount;rupay++)
    {   // iterate over each coin value -
        dp[rupay] = INT_MAX;
        for(int i=0;i<n;i++)
        {   
            if(rupay - coins[i]>=0)
            {
                int smallerAns = dp[rupay - coins[i]];
                if(smallerAns != INT_MAX)
                {
                    dp[rupay] = min(dp[rupay],smallerAns+1);
                }
            }
        }
    }
    return dp[amount];
}
int main(){
    int coins[] = {1,7,10};
    int n = 3;
    int amount = 15;
    cout<<minCoins(coins,amount,n)<<endl;
    cout<<coinsNeededBU(coins,amount,n)<<endl;
}