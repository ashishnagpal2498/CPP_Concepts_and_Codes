// Fractional KnapSack 
#include<bits/stdc++.h>
#define ll long long int
#define endl "\n"
#define ArrIn(n) for(int i=0;i<n;i++)
#define ArrOut for(int i=0;i<n;i++) {cout<<arr[i]<<" "; }
#define mod 1e9+7
using namespace std;
ll t,n,W;
ll arr[200005];
bool myComp(pair<ll,ll> A, pair<ll,ll> B){
    double ratio1 = (double)A.second/A.first;
    double ratio2 = (double) B.second/ B.first;
    return ratio1>ratio2;
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin>>t;
    while(t--){
        ll a;
        cin>>W>>n;
        vector<pair<ll,ll> > items;
        // First - weight , second Value
        ArrIn(n) {
            cin>>a;
            items.push_back(make_pair(a,0));
        }    
        ArrIn(n){
            cin>>a;
            items[i].second = a;
        }
        sort(items.begin(),items.end(),myComp);
        ArrIn(n){
            cout<<items[i].first<<" -> "<<items[i].second<<endl;
        }
        ll profit =0;
        ArrIn(n){
            if(W-items[i].first>=0){
                W-=items[i].first;
                profit+=items[i].second;
            }
            else{
                // fraction -> 
                double fraction = (double)W/items[i].first;
                W -= fraction;
                profit+=(fraction*items[i].second);
            }
        }
        cout<<profit<<endl;
    }
    return 0;
}    