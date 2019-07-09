//count Rotation 
#include<iostream>
using namespace std;
int count_Rotations(int *arr,int n)
{
    int ans =0;
    int start=0,end=n-1;
    while(start<end)
    {   int mid = (start+end)/2;
        if(arr[mid-1]>arr[mid]&&mid>0)
        {
            ans = mid-1;
            break;
        }
        if(arr[mid]>arr[mid+1]&&mid<n)
        {
            ans=mid;
            break;
        }
        else if(arr[mid]>arr[end])
        {
            start = mid+1;
        }
        else
        {
            end = mid-1;
        }
    }
    return ans!=0 ? ans +1: ans;
}

int main()
{
    int n;
    cin>>n;
    int arr[10005];
    for(int i=0;i<n;i++) cin>>arr[i];
    cout<<count_Rotations(arr,n);
    return 0;    
}