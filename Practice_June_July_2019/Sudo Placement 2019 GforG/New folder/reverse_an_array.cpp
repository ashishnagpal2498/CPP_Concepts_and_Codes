//Reverse an Array
#include<iostream>
using namespace std;
int main()
{   int T;
    cin>>T;
    while(T--)
    {   int n;
    cin>>n;
    int arr[100005];
    for(int i=0;i<n;i++) cin>>arr[i];

    int i=0,j=n-1;
    while(i<j)
    {
        swap(arr[i++],arr[j--]);
    }    
    for(int i=0;i<n;i++)
    {
        cout<<arr[i]<<" ";
    }
    cout<<endl;
    }
    return 0;
}