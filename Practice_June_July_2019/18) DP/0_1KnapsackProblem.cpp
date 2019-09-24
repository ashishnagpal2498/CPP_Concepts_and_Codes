//0-1 KnapSack Problem - 
//HackerEarth Questions _ circuits -

#include<iostream>
using namespace std;
//Recursion - max( inclusive , profit - price[n] + f(n-1,w-wt) || exclusive - f(n-1,w))
int knapSack(int wts[],int prices[],int N,int W)
{
    if(N==0||W==0)
    {   //Either the area is empty or the weight in bag is no more
        return 0;
    }
    int incl = 0,excl =0;
    if(wts[N-1]<=W)
    incl = prices[N-1] + knapSack(wts,prices,N-1,W-wts[N-1]);
    excl = knapSack(wts,prices,N-1,W);
    return max(incl,excl);
}

int knapSackDP(int wts[],int prices[],int N,int W)
{
    int dp[100][100]={0};

    for(int i=0;i<=N;i++)
    {
        for(int w=0;w<=W;w++)
        {
            if(w==0||i==0) dp[i][w] = 0;
            else
            {
                int incl=0,excl=0;
                if(wts[i-1]<=w)
                {
                    incl = prices[i-1] + dp[i-1][w-wts[i-1]];
                }
                excl = dp[i-1][w];
                
                dp[i][w] = max(incl,excl);
            }
        }
    }
    for(int i=0;i<=N;i++)
    {
        for(int j=0;j<=W;j++)
        {
            cout<<dp[i][j]<<" ";
        }
        cout<<endl;
    }
    return dp[N][W];
}

int main(int argc, char const *argv[])
{   int wts[] = {2,2,3,1};
    int prices[] = {5,20,20,10};
    int N = 4;
    int W =5;

    int maxProfit = knapSack(wts,prices,N,W);
    cout<<"MAX PROFIT   "<<maxProfit<<endl;
    cout<<"DP KnapSack - "<<knapSackDP(wts,prices,N,W);
    return 0;
}

