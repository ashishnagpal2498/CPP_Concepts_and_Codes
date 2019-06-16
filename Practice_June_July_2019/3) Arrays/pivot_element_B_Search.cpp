//Pivot element using Binary Search
#include<iostream>
using namespace std;
int pivot_element(int arr[],int s,int e)
{
    int mid;
    while(s<=e)
    {
        mid = (s+e)/2;
        if(arr[mid]>arr[mid+1]&&mid<e)
        {
            return mid;
        }
        else if(arr[mid]<arr[mid-1]&&mid>s)
        {
            return mid-1;
        }
        else if(arr[mid]>=arr[e])
        {
            // Right side is Unsorted array
            s = mid+1;
        }
        else {
            //
            e = mid-1;
        }
    }
    return -1;
}
int main()
{
    int arr[] = {5,6,7,8,9,10,4};
    int n = sizeof(arr)/sizeof(int);
    cout<<pivot_element(arr,0,n);

    return 0;
}