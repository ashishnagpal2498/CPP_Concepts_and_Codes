//leaders in an Array 
#include<iostream>
using namespace std;
int main()
{   //int T;
    // cin>>T;
    // while(T--)
    // {int n;
    // cin>>n;
    // int arr[100005];
    // for(int i=0;i<n;i++) cin>>arr[i];
    // for(int i=0;i<n;i++)
    // {   int ele = arr[i];
    //     bool flag = true;
    //     for(int j=i+1;j<n;j++)
    //     {
    //         if(ele<arr[j])
    //         {
    //             flag = false;
    //             break;
    //         }
    //     }
    //     if(flag)
    //     {
    //         cout<<ele<<" ";
    //     }
    // }
    // cout<<endl;
    // }
    //Optimised version
    int T;
    cin>>T;
    while(T--)
    {int n;
    cin>>n;
    int arr[10005];
    for(int i=0;i<n;i++) cin>>arr[i];
    int ans[10005];
    ans[0] = arr[n-1];
    int max_ele = ans[0];
    int j=1;
    for(int i=n-2;i>=0;i--)
    {
        if(arr[i]>=max_ele)
        {
            ans[j++] = arr[i];
            max_ele = arr[i];
        }
    }
    for(int m=j-1;m>=0;m--) {cout<<ans[m]<<" ";}    
    cout<<endl;
    }
    return 0;
}