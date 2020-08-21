//Google online challenge practice
#include<bits/stdc++.h>
#define ll long long int
#define endl "\n"
#define ArrIn(n) for(int i=0;i<n;i++)
#define ArrOut for(int i=0;i<n;i++) {cout<<arr[i]<<" "; }
#define mod 1e9+7
using namespace std;
ll t,n;
ll arr[200005];
bool myComp(ll A, ll B){
    return __builtin_popcount(A)>__builtin_popcount(B);
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin>>t;
    while(t--){
        cin>>n;
        ArrIn(n) cin>>arr[i];
        sort(arr,arr+n,myComp);
    ll ans =1;
    ll prevVal = arr[0];
    ArrIn(n-1){
        ll orVal =  prevVal | arr[i+1];
        if(orVal>prevVal) {prevVal = orVal; ans++;}
    }
    cout<<ans<<endl;
    }

    return 0;
}    