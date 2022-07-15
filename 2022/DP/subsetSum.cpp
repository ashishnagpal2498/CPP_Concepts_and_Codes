// Subset Sum Problem - DP

#include<iostream>
using namespace std;

// Either include or Exclude ->
bool subsetSumRecursion(int* arr, int n, int sum){
    if(sum == 0) return true;

    if(n == 0) return false;

    bool smallAns = false;
    if(sum-arr[n-1]>=0){
        smallAns = subsetSumRecursion(arr,n-1,sum-arr[n-1]);
    }

    bool without = subsetSumRecursion(arr,n-1,sum);

    return smallAns || without;
}

// Memoization
bool t[100][100];

bool subsetSumMemoization(int* arr, int n, int sum){
    if(sum == 0) return true;

    if(n == 0) return false;

    //bool smallAns = false;
    if(sum-arr[n-1]>=0){
        t[n-1][sum-arr[n-1]] = subsetSumMemoization(arr,n-1,sum-arr[n-1]);
    }

    t[n-1][sum]= subsetSumMemoization(arr,n-1,sum);

    t[n][sum] = t[n-1][sum] || t[n-1][sum-arr[n-1]];
    return t[n][sum];
}

bool subsetSumBottomUp(int* arr, int n, int sum){

     int** dp = new int*[n+1];

    for(int i=0;i<=n;i++){
        dp[i] = new int[sum+1];
    }

    for(int i=0;i<=n;i++){
        for(int j=0;j<=sum;j++){
            if(i == 0){
                // There is no element in the Array
                dp[i][j] = false;
            }
            if(j == 0){
                // Empty Subset is also a Valid Solution
                dp[i][j] = true;
            }
            else if(i != 0 && j!=0){
              //  cout<<"\nHERE ->"<<i<<" ->"<<j;
            if(j-arr[i-1]>=0){
                dp[i][j] = dp[i-1][j-arr[i-1]] || dp[i-1][j];
            }
            else
                dp[i][j] = dp[i-1][j];
            }
            //
        }
    }
    return dp[n][sum];
}

int main(){
    int arr[] = {2,3,7,8,10};
    int n = sizeof(arr)/sizeof(int);
    int sum = 14;
    cout<<"Subset Sum Recursion -> "<<subsetSumRecursion(arr,n,sum);
    cout<<"\n Subset Sum Memoization -> "<<subsetSumMemoization(arr,n,sum);
    cout<<"\n Subset Sum Bottom Up Soln -> "<<subsetSumBottomUp(arr,n,sum);
    
    return 0;
}