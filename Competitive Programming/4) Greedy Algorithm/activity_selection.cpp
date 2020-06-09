// Greedy Algorithm - 
// If start time of the activity is less than the end time - 
#include<bits/stdc++.h>
#define ll long long int
using namespace std;
ll t,n;
vector<pair<ll,ll> > activity;
bool comp(pair<ll,ll> A, pair<ll,ll> B)
{
    return A.second<B.second;
}
void activitySelection(ll s){
    set< pair<ll,ll> > ans;
    sort(activity.begin(),activity.end(),comp);
    for(int i=0;i<n;i++)
    {
        if(activity[i].first>=s)
        {
            //Select the activity -
            ans.insert(activity[i]);
            s = activity[i].second;
        }
    }
      for(auto i : ans)
    {
        cout<<"Activity with start "<<i.first<<" end "<<i.second<<endl;
    }
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin>>n;
    ll a;
    for(int i=0;i<n;i++) {
        cin>>a;
        activity.push_back(make_pair(a,0));
    }
    for(int j=0;j<n;j++) {cin>>a; activity[j].second = a;}
    activitySelection(0);
    return 0;
}    