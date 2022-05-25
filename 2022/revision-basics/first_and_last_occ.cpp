// First Occurrance and last occurence of a number in Sorted Array
#include<iostream>
using namespace std;
int last_occ(int arr[],int n,int key){
    int start=0,mid=0,end=n-1;
        int ans = -1;
    while(start<=end){
        mid = (start+end)/2;
        if(key == arr[mid]) {
            ans = mid;
            // first occurrence
            start = mid+1;
        }
        else if(key > arr[mid]){
            start = mid +1;
        }
        else end = mid -1;
    }
        return ans;
}

int first_occ(int arr[],int n,int key){
    int start=0,mid=0,end=n-1;
        int ans = -1;
    while(start<=end){
        mid = (start+end)/2;
        if(key == arr[mid]) {
            ans = mid;
            // first occurrence
            end = mid-1;
        }
        else if(key > arr[mid]){
            start = mid +1;
        }
        else end = mid -1;
    }
        return ans;
}
int main(){
     int arr[] = {1,2,2,5,5,5,7,7,9,9,11,11,11,11,11,14,14};
        int n = sizeof(arr)/sizeof(int);
        cout<<"Size is "<<n<<endl;
        int key;
        cin>>key;
        int ans1 = first_occ(arr,n,key);
        int ans2 = last_occ(arr,n,key);
        cout<<"First Occurrance of number "<<key<<" is "<<ans1<<endl;

        cout<<"Last Occurrance of number "<<key<<" is "<<ans2;
    return 0;
}