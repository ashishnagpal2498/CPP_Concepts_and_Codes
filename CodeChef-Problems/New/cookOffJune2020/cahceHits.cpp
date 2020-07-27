// Cache Hits
#include<bits/stdc++.h>
#define ll long long int
#define endl "\n"
#define ArrIn(n) for(int i=0;i<n;i++)
#define ArrOut for(int i=0;i<n;i++) {cout<<arr[i]<<" "; }
#define mod 1e9+7
using namespace std;
ll t,n,start,e,m,B,i;
ll arr[200005];
bool bsearch(ll s,ll en){
    if(i>= s && i<=en) return true;
    return false;
}
pair<ll,ll> searchBlock(){
// i is the index ->
    pair<ll,ll> ans;
    ll endT = B;
    bool flag = false;
    ll s = 0,endIndex = B;
    for(int j=0;j<5001;j++)
    {   
         if(i == j){
            flag = true;
        }
        endT--;
        if(endT == 0)
        {   endT = B;
            ans.second = j;
            if(flag) return ans;
        }
        if(endT == B-1)
        {
            ans.first = j;
        }
    }
}
int main()
{
    // ios_base::sync_with_stdio(false);
    // cin.tie(NULL);
    cin>>t;
    while(t--)
    {  ll ans =0;
         start = -1;
        cin>>n>>B>>m;
        e = -1;    
        while(m--)
        {   cin>>i;
            // check if index exist in that limit
            bool check = bsearch(start,e);
            if(!check){
                // cout<<"Check "<<check<<endl;
                ans++;
                pair<ll,ll> indices = searchBlock();
                start = indices.first;
                e = indices.second; 
                 // cout<<"pair  "<<indices.first<<"  "<<indices.second<<endl;
            } 
        }
        cout<<ans<<endl;
    }
    return 0;
}    