// Friends Pairing Problem
#include<iostream>
using namespace std;
int friendsPair(int n){
    if(n==0 || n==1) return n;

    int opt1 = friendsPair(n-1);
    int opt2 = (n-1)*friendsPair(n-2);

    return opt1+ opt2;
}
int friendsPairDP(int n){

    int* dp = new int[n+1];

    for(int i=0;i<=n;i++){
        //Base case ->
        if(i<=2) dp[i] = i;
        else
            dp[i] = dp[i-1] + (i-1)* dp[i-2];
    }
    return dp[n];
}
int main(){

    return 0;
}