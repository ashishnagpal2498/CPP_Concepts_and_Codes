// Boats COmpetition 
#include<bits/stdc++.h>
#define ll long long int
#define endl "\n"
#define ArrIn(n) for(int i=0;i<n;i++)
#define ArrOut for(int i=0;i<n;i++) {cout<<arr[i]<<" "; }
#define mod 1e9+7
using namespace std;
ll t,n;
ll arr[52];
ll solve(){
    ll ans = INT_MIN;
    for(int val=2;val<=100;val++){
        ll smallAns=0,i=0,j=n-1;
        while(i<j){
            ll sum = arr[i]+arr[j];
            if(sum == val) {
                smallAns++;
                i++; j--;
            }
            else if(sum > val) j--;
            else i++;
        }
        ans = max(ans,smallAns);
    }
    return ans;
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin>>t;
    while(t--){
        cin>>n;
        ArrIn(n) cin>>arr[i];
        sort(arr,arr+n);
        ll ans = solve();
        cout<<ans<<endl;
    }    
    return 0;
}    