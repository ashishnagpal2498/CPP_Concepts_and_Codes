// LCM Problem ->
#include<bits/stdc++.h>
#define ll long long int
#define endl "\n"
#define ArrIn(n) for(int i=0;i<n;i++)
#define ArrOut for(int i=0;i<n;i++) {cout<<arr[i]<<" "; }
#define mod 1e9+7
using namespace std;
ll t,n,l,r;
ll arr[200005];
ll gcd(ll a,ll b){
    if(a==0) return b;
    return gcd(b%a,a);
}
ll findLCM(ll a,ll b){
    ll hcf = gcd(a,b);
    // cout<<hcf<<endl;
    return (a*b)/hcf;
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin>>t;
    while(t--){
         cin>>l>>r;
         ll a;
         a = l;
         if(2*a <= r){
            cout<<a<<" "<<2*a<<endl;
         }
         else{
            cout<<-1<<" "<<-1<<endl;
         }
    }
    return 0;
}    