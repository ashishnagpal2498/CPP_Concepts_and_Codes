//0-1 Knapsack Problem - 
//2-D dynamic programming -
#include<iostream>
using namespace std;

int knapSack(int *wt,int *prices,int n,int w)
{
    //showroom is empty or remaining capacity of back
    if(n==0||w==0)
    {
        return 0;
    }
    int incl=0 , excl = 0;

    // check if the capicity of bag is greater or equal to curr item
    if(w>=wt[n-1]) //array has indexing - 0 n-1
    {
        incl = prices[n-1] + knapSack(wt,prices,n-1,w-wt[n-1]);
    }
    excl = 0 + knapSack(wt,prices,n-1,w);

    return max(incl,excl);
}

// Bottom - Up approach - 
int knapsack_BottomUP(int *weights,int *prices,int n ,int w)
{
    int dp[100][100]={0};
    for(int i=0;i<=n;i++)
    {
        for(int wt = 0;wt<=w;wt++)
        {    
            if(i==0||wt==0)
            {
                dp[i][wt] = 0;
            }
            else
            {  int incl=0,excl = 0;
                if(weights[i-1]<=wt)
                { 
                    incl = prices[i-1] + dp[i-1][wt - weights[i-1]];
                }
                excl = 0 + dp[i-1][wt];
                 dp[i][wt] = max(incl,excl);
            }
           
        }
    }
    for(int i=0;i<=n;i++)
    {
        for(int j=0;j<=w;j++)
        {
            cout<<dp[i][j]<<"  ";
        }
        cout<<endl;
    }
    return dp[n][w];
}
int main()
{   int wts[] = {2,2,3,1};
    int prices[] = {5,20,20,10};
    int N=4;
    int W = 5;
    int maxProfit = knapSack(wts,prices,N,W);
    cout<<maxProfit<<endl;
    cout<<endl<<"bottom up approach "<<knapsack_BottomUP(wts,prices,N,W);
    return 0;
}