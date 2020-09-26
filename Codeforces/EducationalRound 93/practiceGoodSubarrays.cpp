// Practice Good subarrays
#include<bits/stdc++.h>
#define ll long long int
#define endl "\n"
#define ArrIn(n) for(int i=0;i<n;i++)
#define ArrOut for(int i=0;i<n;i++) {cout<<arr[i]<<" "; }
#define mod 1e9+7
using namespace std;
ll t,n;
ll arr[200005];
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin>>t;
    while(t--){
        cin>>n;
        ll sum =0,ans=0;
        map<ll,ll> freq;
        // Array with 0 elements, 0 length --->
        freq[0] = 1;
        char c;
        ArrIn(n) {
            cin>>c;
            arr[i] = (int)(c - '0');
            // cout<<arr[i]<<" -> ";
            sum+=arr[i];
            ll x = sum - i -1;
            freq[x]++;
        }
        // cout<<endl;
        for(auto v: freq){
            ll arrays = v.second;
            ans+= (arrays*(arrays-1))/2;
        }
        cout<<ans<<endl;
    }    
    return 0;
}    