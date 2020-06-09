// Wilson's Theorem - Spoj - DCEPC11B
#include<bits/stdc++.h>
#define ll long long int
using namespace std;
ll t,n;
ll arr[200005];
ll mod_exp(ll a,ll x, ll mod)
{   ll ans = 1;
    while(x)
    {
        if(x&1)
        {
            ans = (ans*a) % mod;
        }
        x>>=1;
        a = (a*a) % mod;
    }
    return ans;
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    ll p;
    cin>>t;
    while(t--)
    {   
        cin>>n>>p;
        if(n>=p) cout<<0<<endl;
        else{
        ll ans = 1;
        ans *= (p-1); 
        while(n<p-1)
        {   n++;
            ans= (ans* mod_exp(n,p-2,p))% p;
        }
        cout<<ans<<endl;
    }
    }
    return 0;
}    