//maximum _ wines - Price - 
#include<iostream>
#include <cstring>
using namespace std;
int maxPrice(int *wines,int i,int j,int day,int dp[100][100])
{
    //base case - 
    if(i>j)
    {
        return 0;
    }
    if(dp[i][j]!=-1)
    {
        return dp[i][j]; 
    }
    int opt1 = wines[i] *day +  maxPrice(wines,i+1,j,day+1,dp);
    int opt2 = wines[j] * day + maxPrice(wines,i,j-1,day+1,dp);
    dp[i][j] = max(opt1,opt2);
    return max(opt1,opt2);


}

// Bottom Up approach - 
//Diagonal array - filling -
//Diagonal iteration of a 2-D array
int max_Price_BU(int* wines,int i , int j , int day)
{
    //suppose there will be only 1 wine-
    int dp[100][100]={0};

    //only ith bottle is there-
    for(int i=0;i<j;i++)
    {
        dp[i][i] = wine[i] * j;
    }
    for(int n=0;n<j;n++)
    {                                                   
        for(int m=n+1;m<j;m++)
        {
            if(n<=m)
            {   int ans1 = wine[n]*
                dp[n][m] = max()
            }
        }
    }
}
int main()
{
    int wines[] = {2,3,5,1,4};
    int dp[100][100];
    memset(dp,-1,sizeof(dp));
    int n = 5;
    cout<<maxPrice(wines,0,n-1,1,dp);
    return 0;
}