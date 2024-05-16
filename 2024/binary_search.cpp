// Binary Search - Pivot Element
#include <bits/stdc++.h>
using namespace std;

int binarySearch(vector<int> &arr, int key){
    int start =0, end = arr.size()-1,mid;
    
    mid = (start+end)/2;
    while(start<=end){
        if(arr[mid] == key) return mid;
        else if(arr[mid] > key ){
            end = mid-1;
        }
        else{
            start = mid+1;
        }
        mid = (start+end)/2;
    }
    return -1;
}

// Pivot element in sorted rotated array
int pivotElement(vector<int>&arr){
    int start =0,end = arr.size()-1,mid;
    mid = start + (end-start)/2;
    
    while(start <end){
        if(arr[mid]>= arr[0]){
            start = mid +1;
        }
        else{
            end = mid;
        }
         mid = start + (end-start)/2;
    }
    return start;
}

int main() {
    
    // Initialize Vector
    vector<int> arr{3,4,22,45,1,6};
    
    for(int i=0;i<arr.size();i++){
        cout<<arr[i]<<" ";
    }
    cout<<endl;
    cout<<pivotElement(arr);
    sort(arr.begin(),arr.end());
    
    int bSearch = binarySearch(arr,45);
    cout<<"BSearch own --> "<<bSearch<<endl;

    return 0;

}