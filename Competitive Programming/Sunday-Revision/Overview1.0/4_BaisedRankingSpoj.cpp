// Baised Ranking Spoj
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
        cin>>n;
        string s;
        vector<ll> rankings;
        cin.get();
        ArrIn(n){
            cin>>s;
            ll num;
            cin>>num;
            // cout<<num<<" ";
            rankings.push_back(num);
        }
        sort(rankings.begin(),rankings.end());
        ll rank = 1;
        ll diff = 0;
        ArrIn(n){
            diff+= abs(rankings[i]-rank);
            rank++;
        }
        cout<<diff<<endl;
    }    
    return 0;
}    