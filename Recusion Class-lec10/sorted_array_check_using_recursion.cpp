//Check if an array is sorted or not using recursion
#include<iostream>
using namespace std;
int arr[100];
bool sorted(int n)
{
    if(n==0)
    {

     return true;   
    }
    if(arr[n]>arr[n-1]) 
    {
        sorted(n-1);
    }
    else{
        return false;
    }
    return true;
}
int main()
{
    int n;
    cin>>n;
    for(int i=0;i<n;i++)
    {
        cin>>arr[i];
    }
    cout<<sorted(n-1);
    return 0;
}