//Multiple k times rotation
//
#include<iostream>
using namespace std;
int max_k_rotations(int *arr,int k,int n)
{
    for(int i=k;i<n+k;i++)
    {
        cout<<arr[i%n]<<" ";
    }
}
int main()
{
    int n;
    int k;
    cin>>n;
    int arr[10005];
    for(int i=0;i<n;i++)
        cin>>arr[i];
    cin>>k;
    max_k_rotations(arr,k,n);
    return 0; 
}