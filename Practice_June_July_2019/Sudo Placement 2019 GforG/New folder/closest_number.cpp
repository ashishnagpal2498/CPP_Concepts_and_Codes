//closet number of a number
//Application of Binary Search 
#include<iostream>
#include<cmath>
using namespace std;
int closest_num(int *arr,int n,int k)
{
    int start =0,end = n-1;
    int ans = 10000;
    while(start<=end)
    {   int mid = (start+end)/2;
        if(arr[mid]==k)
        {
            return k;
        }
        else if(arr[mid]<k)
        {
            if(abs(arr[mid]-k)<abs(ans-k))
            ans = arr[mid];
       // cout<<ans<<"k is less Arr[mid]  "<<arr[mid]<<endl;

            start = mid+1;
        }
        else
        {
            // if(arr[mid+1]-k<arr[mid-1]-k)
            // {
            //     ans = arr[mid+1];
            // }
            if(abs(arr[mid]-k)<= abs(ans-k))
            ans = arr[mid];
        //cout<<ans<<"k is more Arr[mid]  "<<arr[mid]<<endl;

            // ans = arr[mid];
            end = mid-1;
        }
    }
    return ans;
}
int main()
{   int T;
    cin>>T;
    while(T--)
    {   int n,k;
    cin>>n>>k;
    int arr[100005];
    for(int i=0;i<n;i++) cin>>arr[i];

    cout<<closest_num(arr,n,k)<<endl;
    }
    return 0;    
}