//Largest divisble pair subset
#include<iostream>
#include <algorithm>
using namespace std;
int largetSubset(int*arr,int n){
    if(n==0 || n==1)return n;
    int* dp = new int[n];
    dp[n-1] = 1;
    for(int i=n-2;i>=0;i--){

        int mxm=0;
        // Elements traversed from back
        for(int j=i+1;j<n;j++){
            if(arr[j]%arr[i] == 0 || arr[j]%arr[i]==0) 
                mxm = max(mxm,dp[j]);
        }
        dp[i] = 1 + mxm;
    }

    int mxm = INT_MIN;
    for(int i=0;i<n;i++){
        mxm = max(mxm,dp[i]);
    }
    return mxm;
}

int main(){

    int arr[] = {3,10,5,20,15};
    
    int n = sizeof(arr)/sizeof(arr[0]);
    sort(arr,arr+n);
    cout<<"largetSubset -> length  "<<largetSubset(arr,n);
    return 0;
}