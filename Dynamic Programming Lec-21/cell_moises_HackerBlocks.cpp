//cell moises HackerBlocks
#include<iostream>
using namespace std;

long long int BuildCells(int n,int x,int y,int z)
{
    long long int *dp = new long long int[n+1];
    //there will be no cost to construct 0, 1 cells
    dp[0] =0;
    dp[1] =0;
    for(int i=2;i<=n;i++)
    {
        if(i%2==0)
        {
            //then the position is even-
            dp[i] = min(dp[i/2]+x,dp[i-1]+y);
        }
        else
        {
            dp[i] = min(dp[i-1]+y,dp[(i+1)/2]+x+z);
        }
    }
    return dp[n];
}


int main()
{
    int n,x,y,z;
    cin>>n>>x>>y>>z;
    cout<<BuildCells(n,x,y,z);
    return 0;
}