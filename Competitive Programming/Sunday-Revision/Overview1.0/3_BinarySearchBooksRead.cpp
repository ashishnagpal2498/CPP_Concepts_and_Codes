// No. of books that can be read in T time
// Given n books wehre ith is the time to read that book ->
#include<bits/stdc++.h>
#define ll long long int
#define endl "\n"
#define ArrIn(n) for(int i=0;i<n;i++)
#define ArrOut for(int i=0;i<n;i++) {cout<<arr[i]<<" "; }
#define mod 1e9+7
ll modExp(ll a,ll j,ll m){
    ll ans=1;
    while(j)
    {   if(j&1)
        {
            ans = (ans * a) % m;
        }
        a = (a*a)% m;   
        j>>=1;
    }
    return ans;
}
using namespace std;
ll t,n;
ll arr[200005];
// Check function -> which satisfy the subArray ->
bool check(ll v){
    // cout<<v<<endl;
    ll i=0,sum=0;
    for(i;i<v;i++) sum+=arr[i];
    if(sum<=t) return true;
    while(i<n){
        sum-=arr[i-v];
        sum+=arr[i];
        if(sum<=t) return true;
        i++;
    } 
    return false;
}

ll solve(){
    ll l=0,h=n;
    while(l<h){
        ll mid = (l+h)/2;
        if(check(mid)) l = mid+1;
        else h= mid -1;
    }
    if(check(l)) return l;
    return l-1;
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin>>t>>n;
    ArrIn(n) cin>>arr[i];
    cout<<" No of books read :- "<<solve()<<endl;
    return 0;
}    