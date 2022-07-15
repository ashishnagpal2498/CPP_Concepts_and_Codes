// Reduce the number to 1 

#include<bits/stdc++.h>
using namespace std;

int minStepsRecursion(int n){
    if(n <= 1) return 0;

    int divide3 = INT_MAX, divide2 = INT_MAX, decrement1= INT_MAX;
    if(n%3 == 0){
        divide3 = 1 + minStepsRecursion(n/3);
    }

    if(n%2 == 0){
        divide2 = 1 + minStepsRecursion(n/2);
    }
        decrement1 =  1 + minStepsRecursion(n-1);

    return min(divide3,min(divide2,decrement1));

}

int memDp[100] = {0};
int minStepsMemoization(int n){
    if(n <= 1) return 0;

    if(memDp[n] != 0){
        return memDp[n];
    }

    int divide3 = INT_MAX, divide2 = INT_MAX, decrement1= INT_MAX;
    if(n%3 == 0){
        divide3 = 1 + minStepsRecursion(n/3);
    }

    if(n%2 == 0){
        divide2 = 1 + minStepsRecursion(n/2);
    }
        decrement1 =  1 + minStepsRecursion(n-1);

    memDp[n] = min(divide3,min(divide2,decrement1));

    return memDp[n];
}

int minStepsBottomUp(int n){
    int *dp = new int[n+1];

    dp[0] = 0;
    dp[1] = 0;
    dp[2] = 1;
    dp[3] = 1;

    for(int i=4;i<=n;i++){
        dp[i] = dp[i-1] + 1;
        if(i%2 == 0){
            dp[i] = min(dp[i],dp[i/2]+1);
        }
        if(i%3 == 0){
            dp[i] = min(dp[i],dp[i/3]+1);
        }
    }
    return dp[n];
}

// Squares Sum
int minWaySquaresRecursion(int n){
    if(n == 0) return 0;

    int ans = INT_MAX;
    for(int i=1;i*i<=n;i++){
        int smallAns = minWaySquaresRecursion(n-(i*i));
        ans = min(ans,1+smallAns);
    }
    return ans;
}

int minWaySquaresRecursionBottomUp(int n){
    int* dp = new int[n+1];

   
     memset(dp,INT_MAX,sizeof(dp));
      dp[0] = 0;
    dp[1] = 1;
    for(int num=2;num<=n;num++){
            // dp[num] = INT_MAX;
        for(int i=1; i*i<=num;i++){
            dp[num] = min(dp[num],1+dp[num - i*i]); 
        }
    }
    return dp[n];
}

int main(){
    int n;
    cin>>n;
    int ans = minStepsRecursion(n);
    int ans2 = minStepsMemoization(n);
    cout<<"Min steps "<<ans<<"  -> ans2 "<<ans2<<endl;
    cout<<"Bottom Up approach -> "<<minStepsBottomUp(n);
    cout<<"\n min ways Squares Sum - "<<minWaySquaresRecursion(n);
    cout<<"\n min Ways Squares Sum - Bottom up "<<minWaySquaresRecursionBottomUp(n);
    return 0;
}