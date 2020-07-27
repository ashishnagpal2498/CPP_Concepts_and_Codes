// Bitmasking Subset Array
// Preparing Olympiad
#include<bits/stdc++.h>
#define ll long long int
#define endl "\n"
#define ArrIn(n) for(int i=0;i<n;i++)
#define ArrOut for(int i=0;i<n;i++) {cout<<arr[i]<<" "; }
#define mod 1e9+7
using namespace std;
ll t,n,l,r,x;
ll arr[200005];
ll solve(){
    ll ans=0;
    for(int mask=0;mask<(1<<n);mask++){
        ll minVal = INT_MAX,maxVal = INT_MIN;
        if(__builtin_popcount(mask)>1){
            ll sum =0;
            for(int j=0;j<n;j++){
                if((1<<j)&mask){
                    sum+= arr[j];
                    minVal = min(minVal,arr[j]);
                    maxVal = max(maxVal,arr[j]);
                }
            }
            if(sum>=l && sum<=r && (maxVal-minVal)>=x) ans++;
        }
    }
    return ans;
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin>>n>>l>>r>>x;
    ArrIn(n) cin>>arr[i];
    cout<<solve()<<endl;
    return 0;
}    