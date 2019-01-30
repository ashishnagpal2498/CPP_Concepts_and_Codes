//sorting check using recusion -PRateek sir method
#include<iostream>
using namespace std;
bool isSorted(int *a, int n)
{
    //Base case 
if(n==1)
{
    return true;
}
    //recursiv call
    if(a[0]<a[1] && isSorted(a+1,n-1))
    {
        return true;
    }
    else
    {
        return false;
    }
}
int main()
{
    int arr[1000];
    int n;
    cin>>n;
    for(int i=0;i<n;i++) cin>>arr[i];
        cout<<isSorted(arr,n);
    return 0;
}