// Coin Change Problem ->

#include<iostream>
using namespace std;

int coinChangeWaysRecursion(int* coins,int n, int sum){
    if(sum == 0) return 1;

    if(n==0) return 0;
    if(sum - coins[n-1]>=0){
        // Unbounded KnapSack
        return coinChangeWaysRecursion(coins,n,sum-coins[n-1]) + coinChangeWaysRecursion(coins,n-1,sum);
    }

    return coinChangeWaysRecursion(coins,n-1,sum);
}

int coinChangeWaysBottomUp(int* coins,int n,int sum){

    int** dp = new int*[n+1];

    for(int i=0;i<=n;i++){
        dp[i] = new int[sum+1];
    }

    // INITIALIZATION

    for(int i=0;i<=n;i++){
        for(int j=0;j<=sum;j++){
            if(i == 0){
                dp[i][j] = 0;
            }
            if(j == 0){
                dp[i][j] = 1;
            }
            else if(i != 0 && j != 0) {
                dp[i][j] = dp[i-1][j];
                if(j-coins[i-1]>=0){
                     dp[i][j]+= dp[i][j-coins[i-1]];
                }
            }
        }
    }
    return dp[n][sum];
}

int main(){
    int coins[] = {1,2,3};
    int n = sizeof(coins)/sizeof(int);
    int val = 7;
    cout<<"COIN Change recursion -> "<<coinChangeWaysRecursion(coins,n,val)<<"\n";
    cout<<"Coin change Bottom Up Dp -> "<<coinChangeWaysBottomUp(coins,n,val)<<"\n";
    return 0;
}