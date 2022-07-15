// Binary Search 
#include<iostream>
using namespace std;

int binarySearch(int* arr,int n, int target){
    int start = 0, end = n-1,mid;
    while(start<=end){

        mid = (start+end)/2;

        if(arr[mid] == target){
            return mid;
        }
        else if(arr[mid]> target){
            end = mid-1;
        }
        else start = mid+1;
    }

    return -1;
}

// Pivot Element ->
//

int pivotIdx(int*arr,int n){
    int start = 0,end=n-1,mid;

    while(start<=end){
        mid = (start+end)/2;

        // 2 Conditions
        if(mid+1 <n && arr[mid]> arr[mid+1]) return mid;

        if(mid-1>-1 && arr[mid-1] > arr[mid]) return mid-1;

        else if(arr[mid]> arr[end]){
            start = mid+1;
        }
        else end = mid-1;
    }

    return -1;
}

// Searching in sorted Rotated -> Combining both the Logics ->



int main(){

    int arr[] = {-3,-1,0,2,4,7,9,14};
    int arrSR[] = {4,5,6,9,12,-1,0,3,7};
    int n = sizeof(arr)/sizeof(int);
    int n2 = sizeof(arrSR)/sizeof(int);
    int target;
    cin>>target;
    int indexBSearch = binarySearch(arr,n,target);
    cout<<"Binary Search Index = "<<indexBSearch;
    int pivotIndex = pivotIdx(arrSR,n2); 
    int pivotIndex2 = pivotIdx(arr,n);
    cout<<"\n Binary search Pivot index "<<"arrSr "<<pivotIndex<<" arr "<<pivotIndex2;   
    return 0;
}