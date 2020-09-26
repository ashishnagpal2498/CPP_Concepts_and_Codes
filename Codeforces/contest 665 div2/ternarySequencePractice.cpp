// Ternary Sequence 
#include<bits/stdc++.h>
#define ll long long int
#define endl "\n"
#define ArrIn(n) for(int i=0;i<n;i++)
#define ArrOut for(int i=0;i<n;i++) {cout<<arr[i]<<" "; }
#define mod 1e9+7
using namespace std;
ll t,n,x1,y1,z1,x2,y2,z2;
ll arr[200005];
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin>>t;
    while(t--){
        cin>>x1>>y1>>z1;
        cin>>x2>>y2>>z2;
        ll ans=0;
        // 2,1 [pair]
        ll min21Pairs = min(z1,y2);
            // All two's consumed
            ans+=(2*min21Pairs);
            z1 -= min21Pairs;
            y2-=min21Pairs;

        // 0,2 pair ->
        ll leftTwosInB = min(z2,x1);
        z2-= leftTwosInB;
        x1-= leftTwosInB;

        // 1,0 Pair
        ll oneZeroPair = min(y1,x2);
        y1-=oneZeroPair;
        x2-=oneZeroPair;
        
        ans-=(2*min(z2,y1));
        cout<<ans<<endl;
    }    
    return 0;
}    