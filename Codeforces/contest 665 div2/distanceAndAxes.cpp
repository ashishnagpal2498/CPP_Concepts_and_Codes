//Distance and Axes
#include<bits/stdc++.h>
#define ll long long int
#define endl "\n"
#define ArrIn(n) for(int i=0;i<n;i++)
#define ArrOut for(int i=0;i<n;i++) {cout<<arr[i]<<" "; }
#define mod 1e9+7
using namespace std;
ll t,n,k;
ll arr[200005];
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin>>t;
    while(t--){
        ll ans=0;
        cin>>n>>k;
        if(n== k || (k== 0 && n%2==0));
        else if(n<k) ans+=(k-n);
        else if(k == 0 && n&1) ans+=1;
        else if((n&1 && !(k&1)) || (!(n&1) && k&1)){
            ans++;
            // ll a = n/2;
            // ll nearest = INT_MAX;
            // for(int i=1;i<=a;i++){
            //     ll nVal = abs((i) - (n-i));
            //     // cout<<nVal<<endl;
            //     if(nVal == k) break;
            //     else nearest = min(nearest,abs(k - nVal));
            //    // cout<<"Nearest -> "<<nearest<<endl;
            // }
            // if(nearest != INT_MAX) ans+=nearest;
        }
        cout<<ans<<endl;
    }    
    return 0;
}    