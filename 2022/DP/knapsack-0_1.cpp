// 0- 1 KnapSack Problem ->

#include<bits/stdc++.h>
using namespace std;

int knapsackRecursion(int n,int *prices,int *weights, int W){
    if(n == 0 || W == 0) return 0;

    int smallAns = 0;
    if(W-weights[n-1] >= 0 ){
        smallAns = prices[n-1] + knapsackRecursion(n-1,prices,weights,W-weights[n-1]);
    }

    int without = knapsackRecursion(n-1,prices,weights,W);

    int ans = max(smallAns,without);
    cout<<"ANS - >"<<ans<<endl;
    return ans;
}

// Memoization
int ansDP[100][100];

int knapsackMemoisation(int* prices,int * weights,int n, int W){
    if(n == 0 || W == 0) return 0;

    if(ansDP[n][W] != -1){
        return ansDP[n][W];
    }

    int smallAns = 0;
    if(W-weights[n-1] >= 0 ){
       ansDP[n-1][W-weights[n-1]] = prices[n-1] + knapsackMemoisation(prices,weights,n-1,W-weights[n-1]);
    }

    ansDP[n-1][W] = knapsackMemoisation(prices,weights,n-1,W);

    ansDP[n][W] = max(ansDP[n-1][W-weights[n-1]],ansDP[n-1][W]);
    //cout<<"ANS - >"<<ans<<endl;
    return ansDP[n][W];
}

// Bottom Up Approach ->
int knapsackBottomUp(int* prices,int* weights,int n,int W){

    int** dp = new int*[n+1];

    for(int i=0;i<=n;i++){
        dp[i] = new int[W+1];
    }

    for(int i=0;i<=max(n,W);i++){
        if(i<=W){
            dp[0][i] = 0;
        }
        if(i<=n){
            dp[i][0] = 0;
        }
    }

    for(int i=1;i<=n;i++){
        for(int j=1;j<=W;j++){
            if(j-weights[i-1]>=0){
                dp[i][j] = max(prices[i-1]+dp[i-1][j-weights[i-1]],dp[i-1][j]);
            }
            else{
                dp[i][j] = dp[i-1][j];
            }
        }
    }
    return dp[n][W];
}

int main(){

    int prices[] = {1,4,5,7};
    int weights[] = {1,3,4,5};
    int n = sizeof(prices)/sizeof(int);
    int W = 9;
    memset(ansDP,-1,sizeof(ansDP));
    cout<<"KnapSack - Max Profit ->"<<knapsackRecursion(n,prices,weights,W)<<"\n";
    cout<<"KnapSack Memoization -> "<<knapsackMemoisation(prices,weights,n,W)<<"\n";
    cout<<"KnapSack BottomUp ->"<<knapsackBottomUp(prices,weights,n,W);
    return 0;
}