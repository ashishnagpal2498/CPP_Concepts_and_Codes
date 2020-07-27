// Modulo Exponentiation
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
ll t,n,x;
ll arr[200005];
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin>>t;
    while(t--){
        cin>>n>>x;
        cout<<modExp(n,x,mod)<<endl;
    }
    return 0;
}    