#include<iostream>
#include<stdio.h>
#include<algorithm>
#include<bits/stdc++.h>
using namespace std;
int profit[100][100];
// int MaxProfit_TopDOwn(int *arr,int beg,int end,int year)
// {
//      if(beg>end) return 0;
//     if(profit[beg][end]!=-1) return profit[beg][end];
//     int ans1 = arr[beg]*year + MaxProfit_TopDOwn(arr,beg+1,end,year+1);
//     int ans2 = arr[end]*year + MaxProfit_TopDOwn(arr,beg,end-1,year+1);
//     profit[beg][end] = max(ans1,ans2);
//     return profit[beg][end];
// }

//Bottom Up approach -
int Maxprofit_Bottom_Up(int *arr,int n)
{
    int year = n;
    int dp[100][100]={};
    for(int i=0;i<n;i++)
    {
        dp[i][i] = arr[i]*year;
    }
    --year;
    for(int len=2;len<=n;len++)
    {
        //length of dp 2-D array 
        int srt=0;
        int end = n-len;

        while(srt<=end)
        {
            int endofwindow = srt + len;
            dp[srt][endofwindow] = max(
                arr[srt]*year + dp[srt+1][endofwindow],
                arr[end]*year + dp[srt][endofwindow-1]

                );
            srt++;
        }
        --year;
    }
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<n;j++)
           { cout<<dp[i][j]<<" ";}
       cout<<endl;
    }
    return dp[0][n-1];
}


//This is not the optimal solution as COmplexity is 2^n - 
int MaxProfit(int * arr, int beg,int end,int year)
{   //Beg > end
    //base case- 
    if(beg>end) return 0;
    // if(profit[beg][end]!=-1) return profit[beg][end];
    int ans1 = arr[beg]*year + MaxProfit(arr,beg+1,end,year+1);
    int ans2 = arr[end]*year + MaxProfit(arr,beg,end-1,year+1);
    return max(ans1,ans2);
     
}


int main()
{
    int arr [] = {2,3,5,1,4};
    int n = sizeof(arr)/sizeof(int);
    // memset(profit,n,-1);
    int ans = Maxprofit_Bottom_Up(arr,n);
    cout<<ans;
}