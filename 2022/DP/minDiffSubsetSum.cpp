#include<iostream>
#include<vector>
using namespace std;

void subsetSum(int* arr, int n, int sum,bool**dp){
    
    for(int i=0;i<=n;i++){
        for(int j=0;j<=sum;j++){
            if(i == 0){
                dp[i][j] = false;
            }
            if(j == 0){
                dp[i][j] = true;
            }
            else if(i != 0 && j!=0){
                if(j-arr[i-1] >= 0){
                    dp[i][j] = dp[i-1][j] || dp[i-1][j-arr[i-1]];
                }
                else{
                    dp[i][j] = dp[i-1][j];
                }
            }
        }
    }
}

int minSubsetSumDiff(int* arr,int n){

    // 2 Partition - of s1 and S2
    // Range -> 0 to sum of elements
    int arraySum = 0;
    for(int i=0;i<n;i++) arraySum+=arr[i];

    bool** dp = new bool*[n+1];

    for(int i=0;i<=n;i++){
        dp[i] = new bool[arraySum/2+1];
    }

    subsetSum(arr,n,arraySum,dp);    

    // LAST ROW OF DP ARRAY ->
    // ALLL the elements present -> SUBSET Sum possible ?
    vector<int> possibleS1;
    for(int i=0;i<arraySum/2 +1;i++){
        if(dp[n][i])
            possibleS1.push_back(i);
    }

    int minVal = INT_MAX;

    for(int i=0;i<possibleS1.size();i++){
        cout<<"\n"<<possibleS1[i]<<" -> ";
        minVal = min(minVal,arraySum - 2*possibleS1[i]);
    }
    cout<<"\n";
    return minVal;
}

int main(){

    int arr[] = {1,2,7};
    int n = sizeof(arr)/sizeof(int);

    cout<<"Minimum Subset sum difference = "<<minSubsetSumDiff(arr,n);

    return 0;
}