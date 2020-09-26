// Minimum Product
#include<bits/stdc++.h>
#define ll long long int
#define endl "\n"
#define ArrIn(n) for(int i=0;i<n;i++)
#define ArrOut for(int i=0;i<n;i++) {cout<<arr[i]<<" "; }
#define mod 1e9+7
using namespace std;
ll t,n,a,b,x,y;
ll arr[200005];
ll value2(ll a,ll b,ll x, ll y, ll n){
    ll v2 = INT_MAX; 
     ll xValuesDiff = a-x, yValueDiff = b-y;
            if(n<=yValueDiff){
                b-=n;
                n =0;
            }
            else{
                b = y;
                n-=yValueDiff;
                if(xValuesDiff>=n){
                    a-=n;
                }
                else{
                    a-=xValuesDiff;
                }
            }
            v2 = a*b;
        return v2;
}
ll value1(ll a,ll b,ll x,ll y,ll n){
    ll v1 = INT_MAX;
     ll xValuesDiff = a-x, yValueDiff = b-y;
    if(n<=xValuesDiff){
                a-=n;
                n = 0;
            }
            else{
                a = x;
                n-=xValuesDiff;
                if(yValueDiff>=n){
                    b-=n;
                }
                else{
                    b-=yValueDiff;
                }
            }
            v1 = a*b;
            return v1;
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin>>t;
    while(t--){
        cin>>a>>b>>x>>y>>n;
       
        // cout<<xValuesDiff<<" -> "<<yValueDiff<<endl;
        ll v1= value1(a,b,x,y,n),v2 = value2(a,b,x,y,n);
        cout<<min(v1,v2)<<endl;
    }    
    return 0;
}    