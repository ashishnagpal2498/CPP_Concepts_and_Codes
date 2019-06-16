//Arrays and Functions -
//Binary Search 
#include<iostream>
using namespace std;
int binary_search(int arr[],int s,int e,int key)
{
    int mid;
    int ans =-1;
    while(s<=e)
    {   int mid = (s+e)/2;
        if(arr[mid]==key)  {    ans = mid ;s = mid +1;}
        else if(arr[mid]>key) e=mid-1;
        else s = mid+1;
    }
    return ans;
}
int main()
{   int arr [] {1,2,2,3,3,3,5,5,7,7,7,9,9,11};
    int n = sizeof(arr)/sizeof(int);
    int ele;
    cout<<"Enter element to be searched "; cin>>ele;
    cout<<endl<<binary_search(arr,0,n,ele);
    return 0;
}