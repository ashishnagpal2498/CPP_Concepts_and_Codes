// Catalan's Numnber -
// Given height of tree - Calculate number of Balancer Binary trees
#include<iostream>
using namespace std;
#include<cmath>
#define mod 1000000007

int catalanRecursion(int h){
    if(h <= 1) return 1;

    int x = catalanRecursion(h-1);
    int y = catalanRecursion(h-2);

    // int mod = (int)(pow(10,9) + 7);
    int temp1 = (int)(((long)(x)*x) % mod);
    int temp2 = (int)((2*(long)(x)*y)% mod);

    int ans = (temp1 + temp2) % mod;

    return ans;
}

int catalanNumberBottomUp(int n){

    int* dp = new int[n+1];

    dp[0] = 1;
    dp[1] = 1;

    for(int i=2;i<=n;i++){
        for (int j = 0; j < i; j++)
            dp[i] += dp[j] * dp[i - j - 1];
        //dp[i] = (int)(((long)dp[i-1] * dp[i-1]) % mod) + (int)((2* (long)(dp[i-1])*dp[i-2])% mod);
    }
    return dp[n];
}

int main(){
    int h;
    cin>>h;
    // cout<<mod<<endl;
    cout<<catalanRecursion(h)<<"\n";
    cout<<"Using Dp "<<catalanNumberBottomUp(h);
    return 0;
}