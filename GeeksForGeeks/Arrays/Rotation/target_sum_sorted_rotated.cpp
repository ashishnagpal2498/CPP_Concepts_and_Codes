//target sum in sorted Rotated Array
#include<iostream>
using namespace std;
int main(int argc, char const *argv[])
{
    int n;
    cin>>n;
    int arr[10005];
    for(int i=0;i<n;i++) cin>>arr[i];
    bool flag = false;
    int key;
    cin>>key;
    int sm,lg;
    int i;
    for( i=0;i<n;i++)
    {
        if(arr[i]>arr[i+1]) break;
    }    
    lg = i;
    sm = (i+1)%n;
    while(sm!=lg)
    {
        if(arr[sm]+arr[lg]==key)
        {
            flag = true;
            cout<<arr[sm]<<" "<<arr[lg];
            break;
        }
        else if(arr[sm]+arr[lg]>key)
        {
            --lg;
            if(lg<0)
            {
                lg =n-1;
            }
        }
        else
        {
            sm = (sm+1)%n;
        }
    }
    if(!flag)
    {
        cout<<"No pair found";
    }
    return 0;
}