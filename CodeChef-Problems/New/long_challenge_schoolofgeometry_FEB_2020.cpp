//CodeChef - school of geometry
#include<iostream>
#include<algorithm>
#define ArrIn(arr,n) for(int i=0;i<n;i++) cin>>arr[i]
using namespace std;
int main()
{
    int T,n,arr1[10005],arr2[10005];
    cin>>T;
    while(T--)
    {
        cin>>n;
        ArrIn(arr1,n);
        ArrIn(arr2,n);
        sort(arr1,arr1+n);
        sort(arr2,arr2+n);
        int sum=0;
        for(int i=0;i<n;i++) sum+= min(arr1[i],arr2[i]);
        cout<<sum<<endl;    
    }
    return 0;
}