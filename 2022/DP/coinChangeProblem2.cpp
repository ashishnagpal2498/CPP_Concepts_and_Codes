// Coin Change II

#include<iostream>
using namespace std;

int minCoinWaysRecursion(int* coins, int n, int sum){
    // 
    if(sum == 0) return 0;
    if(n == 0 ) return INT_MAX - 1;

    if(sum-coins[n-1]>=0){
        return min(1+minCoinWaysRecursion(coins,n,sum-coins[n-1]), minCoinWaysRecursion(coins,n-1,sum));
    }

    return minCoinWaysRecursion(coins,n-1,sum);
}

int minCoinWaysBottomUp(int* coins, int n, int sum){

        int** dp = new int*[n+1];

    for(int i=0;i<=n;i++){
        dp[i] = new int[sum+1];
    }

    for(int i=0;i<=n;i++){
        for(int j=0;j<=sum;j++){
            // When there are no coins in back
            if(i == 0){
                dp[i][j] = INT_MAX -1;
            }
            if(j == 0){
                dp[i][j] = 0;
            }
            else if(i == 1){
                // I only have 1 coin -> and if the SUM is divisible ->
                // then return the quotient else infinite -
                if(j%coins[i] == 0){
                    dp[i][j] = j/coins[i];
                }
                else dp[i][j] = INT_MAX - 1;
            }
            else if(i != 0 && i!= 1 && j!=0){
                
                if(j-coins[i-1]>=0){
                    dp[i][j] = min (1 + dp[i][j-coins[i-1]], dp[i-1][j]);
                }
                else
                    dp[i][j] = dp[i-1][j];
            }
        }
    }
    return dp[n][sum];
}

int main(){
    int coins[] = {3,6,5};
    int n = sizeof(coins)/sizeof(int);
    int sum = 4;
    cout<<" MIN COINS required -> Recursion = "<<minCoinWaysRecursion(coins,n,sum)<<endl;
    cout<<" MIN COINS required -> BottomUp DP = "<<minCoinWaysBottomUp(coins,n,sum)<<endl;
    
    return 0;
}