// Expedi - Spoj Cows -
#include<bits/stdc++.h>
#define ll long long int
using namespace std;
ll t,n;
vector<pair<ll,ll> > values;
int willReach(ll L,ll P){
    int count=0;
    int i=0;
    while(i<n&& P<L){
            // Currently P units of fuel find max fuel tank within this range
            ll maxVal = INT_MIN;
            int maxIndex = -1;
            while(values[i].first<=P){
                if(maxVal<values[i].second) {
                   maxVal =  values[i].second;
                   maxIndex = i;
                }
                i++;
            }
            if(maxVal == INT_MIN && i<n) return -1;
            P+=values[maxIndex].second;
            count++;
            
        }
        return count;
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin>>t;
    ll L,P;
    while(t--)
    {
        cin>>n;
        int a,b;
        for(int i=0;i<n;i++) {
            cin>>a>>b;
            values.push_back(make_pair(a,b));
        }
        cin>>L>>P;
        // Distance from truck
        for(int i=0;i<n;i++){
            values[i].first = L - values[i].first;
        }
        sort(values.begin(),values.end());
        int ans = willReach(L,P);
        cout<<ans<<endl;
    }
    
    return 0;
}    