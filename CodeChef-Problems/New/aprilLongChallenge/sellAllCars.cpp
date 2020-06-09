//Long Challenge - Sell all cars -
#include<iostream>
#include<algorithm>
#define mod 1000000007
#define ArrIn for(int i=0;i<n;i++) cin>>arr[i]
using namespace std;
int main()
{
    int T;
    cin>>T;
    while(T--)
    {
        int n,arr[100005];
        cin>>n;
        ArrIn;
        sort(arr,arr+n);
        int year = 0,sum=0;
        for(int i=n-1;i>=0;i--,year++) { 
        int val = arr[i] - 1*year;
        if(val>0)
        {
            arr[i] = val; 
        }
        else{
            arr[i] = 0;
        }

        sum+=arr[i];
        sum%=mod;
        }
        cout<<sum<<endl;
    }
    return 0;
}