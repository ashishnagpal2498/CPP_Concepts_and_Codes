//Pivot Element -
#include<iostream>
using namespace std;
int pivot_search(int arr[],int n){
    if(n==1||n==0) return n;
    int start=0,end=n-1,mid;

    while(start<=end){
        int mid = (start+end)/2;
        if(mid-1>0 && arr[mid]<arr[mid-1]) return mid-1;
        else if(mid+1<=end && arr[mid]>arr[mid+1]) return mid;
        else if(arr[mid]<= arr[end]) end = mid -1;
        else start = mid+1;
    }
    return -1;
}

int main(){
     int arr[] = {5,6,7,8,9,11,14,1,2,3,4};
        int n = sizeof(arr)/sizeof(int);
        cout<<"Size is "<<n<<endl;
        int ans = pivot_search(arr,n);
        cout<<"Pivot element index is "<<ans<<" and element is "<<arr[ans];   
    return 0;
}