// Maximum SubArray Sum
#include<iostream>
using namespace std;

int kadaneAlgo(int arr[],int n){
    // A number will always contribute to the sum
    int max_sum_so_far =0,maxSum=INT_MIN;
    for(int i=0;i<n;i++){
        max_sum_so_far += arr[i];
        if(max_sum_so_far < 0) max_sum_so_far = 0;
        maxSum= max(maxSum,max_sum_so_far);
    }
    return maxSum;
}

int main(){

    int arr[] = {-2,-3,4,-1,-2,1,5,-3};
    int n = sizeof(arr)/sizeof(int);
    cout<<kadaneAlgo(arr,n);
    return 0;

}