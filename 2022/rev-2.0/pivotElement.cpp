// Pivot element in Array
// Find element in array jispar array break hua hai Increasing and Decreasing

#include<iostream>
using namespace std;

int binary_pivot(int *arr, int n){
    int start = 0, end=n-1,mid;
    while(start<=end){
        mid = (start+end)/2;

        if(arr[mid]>arr[mid+1]){
            return mid;
        }
        else if(mid-1>=0 && arr[mid-1]> arr[mid]){
            return mid-1;
        }
        else if(arr[mid] > arr[end]){
            end = mid-1;
        }
        else{
            start = mid+1;
        }
    }
    return -1;
}

int main(){
    int arr[] = {5,6,7,1,2,3,4};
    int n = sizeof(arr)/sizeof(int);
    int ans = binary_pivot(arr,n);
    cout<<"Pivot element Index - "<<ans;
    return 0;
}