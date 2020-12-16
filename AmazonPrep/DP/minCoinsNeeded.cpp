// Min coins Needed
#include<iostream>
using namespace std;
int minCoins(int amount,int coins[],int n){
    if(amount == 0){
        return 0;
    }

    int ans = INT_MAX-1;

    for(int i=0;i<n;i++){
        if(amount-coins[i]>=0){
            int smallAns = minCoins(amount-coins[i],coins,n);
            ans = min(ans,smallAns+1);
        }
    }
    return ans;
}
int minCoinsDP(int amount,int coins[],int n){

    int* dp = new int[amount+1];
    dp[0] = 0;

    for(int paise=1;paise<=amount;paise++){
        dp[paise] = INT_MAX;
        for(int i=0;i<n;i++){
            int reducedAmtUsingIthCoin = paise-coins[i];
            if(reducedAmtUsingIthCoin>=0){
                dp[paise] = min(dp[reducedAmtUsingIthCoin]+1,dp[paise]);
            }
        }
    }
    return dp[n];
}
int main(int argc, char const *argv[])
{
    int coins[] = {1,7,10}; int n= 3;
    cout<<"Min coins needed "<<minCoins(15,coins,n)<<endl;   
    cout<<"Min coins DP -> "<<minCoinsDP(15,coins,n);
    return 0;
}