// Unbounded KnapSack -

// Difference from KnapSack ->

// If the item is picked once -> then we cannot include it again
//

#include<iostream>
using namespace std;

//

int unBoundedKnapsackRecursion(int* prices,int * weights,int n, int W){
    if(n== 0 or W == 0) return 0;

    int smallAns = 0;
    if(W-weights[n-1]>=0){
        smallAns = prices[n-1] + unBoundedKnapsackRecursion(prices,weights,n,W-weights[n-1]);
    }
    // return max( prices[n-1] + unBoundedKnapsack(n,W-weight), uBKS(n-1,W))

    int withoutIncluding = unBoundedKnapsackRecursion(prices,weights,n-1,W);
    // return -> unBound(n-1,W)
    return max(smallAns,withoutIncluding);
}

int unBoundedKnapsackBottomUp(int* prices, int* weights, int n, int W){
    // DP Array and Initialization
    
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
                dp[i][j] = max(prices[i-1] +dp[i][j-weights[i-1]],dp[i-1][j]);
            }
            else{
                dp[i][j] = dp[i-1][j];
            }
        }
    }


    for(int i=0;i<=n;i++){
        for(int j=0;j<=W;j++){
            cout<<dp[i][j]<<" ";
        }
        cout<<endl;
    }

    return dp[n][W];
}

int main(){
     int prices[] = {1,5,4,7};
    int weights[] = {1,3,4,5};
    int n = sizeof(prices)/sizeof(int);
    int W = 7;
    // memset(ansDP,-1,sizeof(ansDP));
    cout<<"KnapSack - Max Profit ->"<<unBoundedKnapsackRecursion(prices,weights,n,W)<<"\n";
    // cout<<"KnapSack Memoization -> "<<knapsackMemoisation(prices,weights,n,W)<<"\n";
    cout<<"KnapSack BottomUp ->"<<unBoundedKnapsackBottomUp(prices,weights,n,W);
    return 0;
}