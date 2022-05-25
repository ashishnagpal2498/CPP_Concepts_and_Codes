#include <bits/stdc++.h>
using namespace std;

// const int inf = (int)1e6;
int binary_search(int arr[],int n,int key){
    int start=0,mid=0,end=n-1;


    while(start<=end){
        mid = (start+end)/2;
        if(key == arr[mid]) return mid;
        else if(key > arr[mid]){
            start = mid +1;
        }
        else end = mid -1;
    }
        return -1;
}
int main(){
        int arr[] = {1,5,9,11,14};
        int n = sizeof(arr)/sizeof(int);
        cout<<"Size is "<<n<<endl;
        int key;
        cin>>key;
        int ans = binary_search(arr,n,key);
        cout<<"Index of element is "<<ans;    
}