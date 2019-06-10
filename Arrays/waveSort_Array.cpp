//Wave Sort array
#include<iostream>
using namespace std;
int main()
{   int n,arr[100];
    cin>>n;
    for(int i=0;i<n;i++) cin>>arr[i];
        for(int i=0;i<n;i=i+2)
        {
            if(arr[i-1]>arr[i]&&i>0) swap(arr[i-1],arr[i]);
            if(arr[i+1]>arr[i]&&i<n-1) swap(arr[i+1],arr[i]);
        }
        for(int i=0;i<n;i++) cout<<arr[i]<<"  ";
    return 0;
}