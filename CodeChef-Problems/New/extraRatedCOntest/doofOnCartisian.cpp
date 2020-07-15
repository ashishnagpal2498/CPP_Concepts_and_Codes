//Doof on Cartisian
#include<bits/stdc++.h>
#define ll long long int
#define endl "\n"
#define ArrIn(n) for(int i=0;i<n;i++)
#define ArrOut for(int i=0;i<n;i++) {cout<<arr[i]<<" "; }
#define mod 1e9+7
using namespace std;
ll t,n,q,a,b;
ll arr[200005];
map<pair<ll,ll>,bool> InvalidPoint;
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin>>t;
    while(t--){
        cin>>n;
        ArrIn(n) {
            cin>>arr[i];
            ll temp = arr[i];
            ll j=0;
            // InvalidPoint[make_pair(0,0)] = true;
            while(temp>=0){
                InvalidPoint[make_pair(j,temp)] = true;
                temp--; j++;
            }
        }
        // for(auto a: InvalidPoint){
        //     cout<<a.first.first<<" -> "<<a.first.second<<endl;
        // }
        cin>>q;
        for(int i=0;i<q;i++){
            cin>>a>>b;
            pair<ll,ll> m(a,b);
            if(InvalidPoint.find(m) != InvalidPoint.end()){
                cout<<-1<<endl;
            }
            else{
                ll p=0;
                ll v = max(a,b);
                ll wall = 0;
                while(arr[p++]<=v && p<=n) wall++;
                cout<<wall<<endl;
            }
        }
    }    
    return 0;
}    