// Min Cost Path ->
#include<iostream>
using namespace std;

int ans[100][100];
int minCostRecursion(int arr[10][10],int n,int m,int i,int j){
    if(i == n-1 && j == m-1){
        // Reached at the last cell;
        return arr[i][j];
    }
    //INT_MAX,y = INT_MAX,z = INT_MAX;
    if(ans[i][j] != INT_MAX){
        return ans[i][j];
    }
    if(j+1<m){
        ans[i][j+1] = minCostRecursion(arr,n,m,i,j+1);
    }
    if(i+1<n && j+1<m) ans[i+1][j+1] = minCostRecursion(arr,n,m,i+1,j+1);

    if(i+1<n) ans[i+1][j] = minCostRecursion(arr,n,m,i+1,j);

    ans[i][j] = arr[i][j] + min(ans[i][j+1],min(ans[i+1][j+1],ans[i+1][j]));

    return ans[i][j];
}

// Bottom up ->
int minCostBottomUp(int arr[10][10],int n,int m){
    int** dp = new int*[n];
    for(int i=0;i<m;i++){
        dp[i] = new int[m];
    }

    // Last Cell Fill ->
    dp[n-1][m-1] = arr[n-1][m-1];

    // Last row filling
    for(int i = m-2;i>=0;i--){
        dp[n-1][i] = arr[n-1][i] + dp[n-1][i+1];
    }

    // Last Column filling
    for(int i = n-2;i>=0;i--){
        dp[i][m-1] = arr[i][m-1] + dp[i+1][m-1];
    }

    // Row wise filling
    // Start from second last row and second last column
    for(int i=n-2;i>=0;i--){

        for(int j=m-2;j>=0;j--){
            dp[i][j] = arr[i][j] + min(dp[i+1][j],min(dp[i+1][j+1],dp[i][j+1]));
        }
    }
    return dp[0][0];
}

int main(){

    int arr[10][10] = {
    {5,3,4,7},
    {4,5,9,2},
    {1,2,6,10}};
    int n = 3,m=4;
    for(int i=0;i<=n;i++){
        for(int j=0;j<=m;j++){
            ans[i][j] = INT_MAX;
        }
    }
    int result = minCostRecursion(arr,n,m,0,0);
    cout<<"Min cost -> "<<result<<endl;
    result = minCostBottomUp(arr,n,m);
    cout<<"Min Cost from Bottom up DP -> "<<result<<"\n";
    return 0;
}