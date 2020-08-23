// Spoj DCEPC11B
#include<bits/stdc++.h>
#define ll long long int
#define endl "\n"
#define ArrIn(n) for(int i=0;i<n;i++)
#define ArrOut for(int i=0;i<n;i++) {cout<<arr[i]<<" "; }
#define mod 1e9+7
ll modExp(ll a,ll x,ll m){ ll ans=1; while(x){   if(x&1){ ans = (ans * a) % m;}a = (a*a)% m;x>>=1;} return ans; }
using namespace std;
ll t,n,p;
ll arr[200005];
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin>>t;
    while(t--){
        cin>>n>>p;    
        if(n>=p) {
            cout<<0<<endl;
        }
        else{
            ll ans = 1;
            ans*=(p-1);
            while(n<(p-1)){
                n++;
                ll a = modExp(n,p-2,p);
                ans = (ans* a)%p;
            }
            cout<<ans<<endl;
        }
    }
    return 0;
}    