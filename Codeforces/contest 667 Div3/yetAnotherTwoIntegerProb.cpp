// Yet another two intergers problem
#include<bits/stdc++.h>
#define ll long long int
#define endl "\n"
#define ArrIn(n) for(int i=0;i<n;i++)
#define ArrOut for(int i=0;i<n;i++) {cout<<arr[i]<<" "; }
#define mod 1e9+7
using namespace std;
ll t,n,a,b;
ll arr[200005];
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin>>t;
    while(t--){
        cin>>a>>b;
        ll diff = abs(a-b);
        ll ans = 0;
        if(diff == 0){
            cout<<ans<<endl;
        }
        else{
            for(int i=10;i>=1;i--){
                if(diff>=i){
                    ll v = diff/i;
                    ans+=v;
                    diff-=(v*i);
                }
            }
            cout<<ans<<endl;
        }
    }    
    return 0;
}    