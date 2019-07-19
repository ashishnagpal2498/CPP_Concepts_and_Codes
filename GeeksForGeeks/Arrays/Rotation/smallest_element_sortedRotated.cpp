//Minimum Element in Sorted Rotated Array
#include<iostream>
using namespace std;
int smallestElement(int*arr,int n)
{
    int start = 0,end =n-1;
    while(start<end)
    {   int mid = (start+end)/2;
        if(arr[mid]<arr[mid-1])
        {
            return arr[mid];
        }
        if(arr[mid+1]<arr[mid])
        {
            return arr[mid+1];
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
    return arr[0];
}
int main(int argc, char const *argv[])
{
    int n;
    int arr[10005];
    cin>>n;
    for(int i=0;i<n;i++) cin>>arr[i];
    cout<<smallestElement(arr,n);    
    return 0;
}