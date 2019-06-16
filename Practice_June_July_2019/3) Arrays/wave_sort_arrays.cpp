//wave Sort Array-
#include<iostream>
using namespace std;
int main()
{
    int arr[] ={1,3,2,0,7,8,9};
    int n = sizeof(arr)/sizeof(int);
    for(int i=0;i<n;i=i+2)
    {
        if(arr[i-1]>arr[i]&&i-1>0)
        {
            swap(arr[i],arr[i-1]);
        }
        if(arr[i]<arr[i+1]&&i+1<n)
        {
            swap(arr[i],arr[i+1]);
        }
    }
    for(int i=0;i<n;i++)
    {
        cout<<arr[i]<<" ";
    }
    return 0;
}