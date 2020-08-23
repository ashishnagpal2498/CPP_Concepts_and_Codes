// Remove Array Elements
#include<bits/stdc++.h>
#define ll long long int
#define endl "\n"
#define ArrIn(n) for(int i=0;i<n;i++)
#define ArrOut for(int i=0;i<n;i++) {cout<<arr[i]<<" "; }
#define mod 1e9+7
using namespace std;
ll t,n;
ll arr[200005];
bool solve(){
    ll prevElement = arr[0];
    if(n == 1) return true;
    for(int i=1;i<n;i++)
    {
        if(abs(prevElement-arr[i])<=1){
            prevElement = max(prevElement,arr[i]);
        }
        else return false;
    }
    return true;
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
        bool ans = solve();
        ans ? cout<<"YES\n" : cout<<"NO\n";
    }    
    return 0;
}    