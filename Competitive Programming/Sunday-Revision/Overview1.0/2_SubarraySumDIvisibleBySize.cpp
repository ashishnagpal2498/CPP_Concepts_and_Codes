//Subarray sum divisible by the size of array
#include<bits/stdc++.h>
#define ll long long int
#define endl "\n"
#define ArrIn(n) for(int i=0;i<n;i++)
#define ArrOut for(int i=0;i<n;i++) {cout<<arr[i]<<" "; }
#define mod 1e9+7
using namespace std;
ll t,n;
ll arr[200005];
ll prefixSum[200005];
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin>>n;
    prefixSum[0] = 1; // Frequency ->
    ll sum =0;
    ArrIn(n) {cin>>arr[i];
        sum+=arr[i];
        sum%=n;
        sum = (sum+n)%n;
        prefixSum[sum]++;
    }
    ll ans=0;
    for(int i=0;i<n;i++)
    {
        ll m = prefixSum[i];
        ans+=(m*(m-1)/2);
    }

    return 0;
}    