//Dynamic Programming Webinar - 
//Optimal Substructure and Overlapping Subproblem - Two basic needs of DP
//
// Fibonacci Series
//Dynamic Prog V/s Divide and Conquer - In D&C subproblems may or maynot overlap
//DP v/s Greedy - Coin change problem - Indian and USA currency
//Top down Or Bottom Up - 
//
#include<iostream>
using namespace std;
int fib(int n)
{
    // Base case
    if(n<=0)
    {
        return 0;
    }
    if(n==1)
    {
        return 1;
    }
    int ans = fib(n-1) + fib(n-2);
    return ans;

}
int fibTopDownDP(int n,int *dp)
{
    if(n==0||n==1)
    {
        dp[n] = n;
        // dp[1] = 1;
        return n;
    }

    // If the value is already present in dparray -
    if(dp[n]!=-1)
    {
        return dp[n];
    }
    else
    {
        dp[n] = fibTopDownDP(n-1,dp)+ fibTopDownDP(n-2,dp);
        return dp[n];
    }
}
//Bottom -UP approach
// Iterative method to find the solution - starting from smallest problem
int fibBottomUp(int n)
{   int *dp = new int[n+1];
    dp[0] = 0;
    dp[1] = 1;
    for(int i=2;i<=n;i++)
    {
        //previous two states already computed
        dp[i]= dp[i-1] + dp[i-2];
    }
    return dp[n];
}
// Space and Time Complexity in All the three cases
int main()
{

    int n;
    cin>>n;
    int *arr;
    arr = new int[n+1];
    // initialize array with -1 all values
    for(int i=0;i<=n;i++)
    {
        arr[i] = -1;
    }

    cout<<fib(n)<<endl;
    cout<<"Fibonacci using DP  "<<fibTopDownDP(n,arr);
    cout<<endl<<"Fib using bottom up "<<fibBottomUp(n);
    return 0;
}