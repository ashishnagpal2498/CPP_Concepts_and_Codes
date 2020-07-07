//D concatenate Multiples
// Given an array -> X and Y -> given X concatenate Y % K
// (Y*100 + 45)%k = 0

#include<bits/stdc++.h>
#define ll long long int
#define endl "\n"
#define ArrIn(n) for(int i=0;i<n;i++)
#define ArrOut for(int i=0;i<n;i++) {cout<<arr[i]<<" "; }
#define mod 1e9+7
using namespace std;
ll t,n,k;
ll arr[200005];
map<ll,ll> module[11];
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin>>n>>k;
    for(int i=0;i<n;i++){
        cin>>arr[i];
        ll val = arr[i]; 
        for(int j=1;j<=10;j++){
            val = (val*10) %k; // multiple by 10 in each loop -> 
            module[j][val]++;
        }
    }
    ll ans = 0;
    for(int i=0;i<n;i++){
        //1. FInd length of number ->
        ll length=0,val=arr[i];
        while(val) length++,val/=10;
        ll po = 1;
        for(int a=0;a<length;a++) po*=10;
        ll findOut = (k - (arr[i])%k) % k; // Imp to add % k at end as if arr[i] -> toh this becomes -> k
        ans += module[length][findOut];
        val = ((arr[i]%k)*(po%k))%k;
        if( val == findOut) ans--;
    }        
    cout<<ans;
    return 0;
}    