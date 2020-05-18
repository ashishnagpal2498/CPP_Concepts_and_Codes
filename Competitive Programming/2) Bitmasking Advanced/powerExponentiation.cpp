//Exponentiation- (a)^n
#include<bits/stdc++.h>
#define ll long long int
#define mod 1000000007
using namespace std;
ll t,n;
ll arr[200005];
ll powExp(ll a, ll n)
{
    ll ans = 1;
    while(n)
    {
        if(n&1) ans*=a;
        a*=a;
        n>>=1;
    }
    return ans;
}
int main()
{   ll a;
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin>>a>>n;
    ll ans = 1;
    for(int i=0;i<n;i++){
        ans*=a;
    }
    cout<<ans<<endl;
    cout<<powExp(a,n);
    return 0;
}    