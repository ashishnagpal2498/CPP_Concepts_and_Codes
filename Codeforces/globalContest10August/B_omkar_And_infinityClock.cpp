//Omkar and infinity clock
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
        cin>>n>>k;
        priority_queue<pair<ll,ll> > pq;
        vector<ll> ans(n);
        ArrIn(n){
            cin>>arr[i];
            pq.push(make_pair(arr[i],i));
        }
        if(n<k){
            for(int i=0;i<n;i++){
                cout<<0<<" ";
            }
            cout<<endl;
        }
        else{
            int i=0;
            while(!pq.empty() && i<k){
                pq.pop();
                
            }
        }
    }
    return 0;
}    