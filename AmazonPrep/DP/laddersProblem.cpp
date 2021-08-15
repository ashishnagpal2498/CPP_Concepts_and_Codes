// Ladders Problem ->
#include<iostream>
using namespace std;

// Recursion ->
int noOfWays(int n,int k){
    if(n<0) return 0;
    if(n==0) return 1;
    int ans = 0;
    for(int i=1;i<=k;i++){
        ans+=noOfWays(n-i,k);
    }
    return ans;
}
int noOfWaysDP(int n,int k){

    int* dp = new int[n+1];
    dp[0] =1;
    for(int i=1;i<=n;i++){
        dp[i] = 0;
        for(int j=1;j<=k;j++){
            if(i-j>=0){
                dp[i] +=dp[i-j];
            }
        }
    }
    return dp[n];
}
int noOfWaysDP2(int n,int k){

    int* dp = new int[n+1];
    dp[0] =1;
    for(int i=1;i<=n;i++){
        dp[i] = 0;
        
        // for(int j=1;j<=k;j++){
        //     if(i-j>=0){
        //         dp[i] +=dp[i-j];
        //     }
        // }

    }
    return dp[n];
}
int main(){
    int n,k;
    cin>>n>>k;
    cout<<"noOfWays -> "<<noOfWays(n,k)<<endl;
    cout<<"noOfWays -> DP "<<noOfWaysDP(n,k);
    return 0;
}