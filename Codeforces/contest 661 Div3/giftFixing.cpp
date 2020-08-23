// Gift fixing 
#include<bits/stdc++.h>
#define ll long long int
#define endl "\n"
#define ArrIn(n) for(int i=0;i<n;i++)
#define ArrOut for(int i=0;i<n;i++) {cout<<arr[i]<<" "; }
#define mod 1e9+7
using namespace std;
ll t,n;
ll arr1[52],arr2[52];
ll solve(ll minCandies,ll minOranges){
    ll ans =0;
    for(int i=0;i<n;i++){

        if(arr1[i] != minCandies && arr2[i] != minOranges) {
            int minVal = min(arr1[i]-minCandies,arr2[i]-minOranges);
            arr1[i]-=minVal; arr2[i]-=minVal; ans+=minVal;
        }
        if(arr1[i] != minCandies) {
            ans+=(arr1[i]-minCandies);
        }
        if(arr2[i] !=minOranges){
            ans+=(arr2[i]- minOranges);
        }
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
        ll minCandies= INT_MAX,minOranges= INT_MAX;
        ArrIn(n) {
            cin>>arr1[i];
            minCandies = min(arr1[i],minCandies);
        }
        ArrIn(n) {
            cin>>arr2[i];
            minOranges = min(minOranges,arr2[i]);
        }     
        ll ans = solve(minCandies,minOranges);
        cout<<ans<<endl;
    }
    return 0;
}    