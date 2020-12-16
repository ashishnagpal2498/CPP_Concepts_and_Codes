// Ugly Numbers -> DP
#include <iostream>
#include<algorithm>
using namespace std;

int nthUglyNumber(int n){
    int i2=0,i3=0,i5=0;
    int dp[n+1];
    dp[0] = 1;
    long long int next_multiple_2 = dp[i2]*2, next_multiple_3 = dp[i3]*3, next_multiple_5 =dp[i5]*5;
    
    for(int i=1;i<=n;i++){
        int next_num = min({next_multiple_2,next_multiple_3,next_multiple_5});
        dp[i] = next_num;
        if(next_num == next_multiple_2){
            i2++;
            next_multiple_2 = dp[i2]*2;
        }
        if(next_num == next_multiple_3){
            i3++;
            next_multiple_3 = dp[i3]*3;
        }
        if(next_num == next_multiple_5){
            i5++;
            next_multiple_5 = dp[i5]*5;
        }
    }
    return dp[n];
}

int main(){
    int n;
    cin>>n;
    cout<<"Nth -> ugly number is "<<nthUglyNumber(n);
    return 0;
}