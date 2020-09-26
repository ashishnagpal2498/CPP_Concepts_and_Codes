// polygon relationship
#include<bits/stdc++.h>
#define ll long long int
#define endl "\n"
#define ArrIn(n) for(int i=0;i<n;i++)
#define ArrOut for(int i=0;i<n;i++) {cout<<arr[i]<<" "; }
#define mod 1e9+7
using namespace std;
ll t,n;
ll arr[200005];
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin>>t;
    while(t--){
        ll ans =0;
        cin>>n;
        ans+=n;
        ArrIn(n){
            cin>>arr[0]>>arr[1];
        }
        while(n){
            bool f = false;
            ll num = n/2;
            if(num>=3) {f = true;ans+=num; n = num;} 
            if(!f) break;
        }    
        cout<<ans<<endl;
    }
    return 0;
}    