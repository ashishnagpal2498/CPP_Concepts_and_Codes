// 0-1 KnapSack 
#include<iostream>
using namespace std;
// Recursion 
int maxProfit(int W,int weights[],int prices[],int n){
    if(W == 0 || n == 0) return 0;
    int incl = INT_MIN;
    if(W- weights[n-1]>=0)
     incl = prices[n-1] + maxProfit(W-weights[n-1],weights,prices,n-1);
    int excl = maxProfit(W,weights,prices,n-1);
    return max(incl,excl);
}
int KnapSack2D_DP_BU(int W,int wts[],int prices[],int n){
    int dp[100][100] ={0};

    for(int i=0;i<=n;i++)
    {
        for(int w=0;w<=W;w++)
        {
            if(w == 0 || i == 0){
                dp[i][w] = 0;
            }
            else{
                int incl =0,excl = 0;
                if(wts[i-1]<=w)
                {   //Current weight of bag -
                    incl = prices[i-1] + dp[i-1][w-wts[i-1]];
                }
                excl = dp[i-1][w];
                dp[i][w] = max(incl,excl);
            }
        }
    }
    for(int i=0;i<=n;i++)
    {
        for(int w=0;w<=W;w++)
        {
            cout<<dp[i][w]<<" ";
        }
        cout<<endl;
    }
    return dp[n][W];
}
int main()
{   int wts[] = {2,2,3,1};
    int prices[] = {5,20,20,10};
    int W = 10;
    cout<<maxProfit(5,wts,prices,4)<<endl;
    cout<<KnapSack2D_DP_BU(5,wts,prices,4)<<endl;
    return 0;
}