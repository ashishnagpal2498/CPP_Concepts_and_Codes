// Count of Subset Sum ->

#include<iostream>
using namespace std;

int countSubsetRecursion(int* arr,int n,int sum){

    if(sum == 0) return 1; 

    // No element presetn and SUM > 0;
    if(n==0) return 0;

    int smallAns = 0;
    if(sum-arr[n-1]>=0){
        smallAns = countSubsetRecursion(arr,n-1,sum-arr[n-1]);
    }

    int without = countSubsetRecursion(arr,n-1,sum);

    return smallAns + without; 
}

// Memoization ->
// int t[100][100]

// int countSubsetRecursion(int* arr,int n,int sum){

//     if(sum == 0) return 1; 

//     // No element presetn and SUM > 0;
//     if(n==0) return 0;

//     if(t[n][sum] != -1) return t[n][sum];

//     int smallAns = 0;
//     if(sum-arr[n-1]>=0){
//         smallAns = countSubsetRecursion(arr,n-1,sum-arr[n-1]);
//     }

//     int without = countSubsetRecursion(arr,n-1,sum);

//     return smallAns + without; 
// }

int main(){
    
    int arr[] = {2,3,4,5,6,8,10};
    int n = sizeof(arr)/sizeof(int);
    int sum = 10;

    cout<<"Count subSet Sum Recursion -> "<<countSubsetRecursion(arr,n,sum);
    return 0;
}