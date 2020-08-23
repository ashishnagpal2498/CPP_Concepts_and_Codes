// Greedy Activity Selection
#include<bits/stdc++.h>
#define ll long long int
#define endl "\n"
#define ArrIn(n) for(int i=0;i<n;i++)
#define ArrOut for(int i=0;i<n;i++) {cout<<arr[i]<<" "; }
#define mod 1e9+7
using namespace std;
ll t,n;
// ll arr[200005];
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin>>t;
    while(t--){
        ll a;
        cin>>n;
        vector<pair<ll,ll> > activities;
        // First End time , second start time;
        ArrIn(n) { cin>>a; activities.push_back(make_pair(0,a)); }
        ArrIn(n) {
            cin>>a;
            activities[i].first = a;
        }    
        sort(activities.begin(),activities.end());
        ll endTime =0;
        ll ans=0;
        ArrIn(n){
            if(activities[i].second > endTime){
                endTime = activities[i].first;
                ans++;
            }
        }
        cout<<ans<<endl;
    }
    return 0;
}    