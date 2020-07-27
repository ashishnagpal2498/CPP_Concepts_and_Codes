// Or-Thodox DIstinction
#include<bits/stdc++.h>
#define ll long long int
#define endl "\n"
#define ArrIn(n) for(int i=0;i<n;i++)
#define ArrOut for(int i=0;i<n;i++) {cout<<arr[i]<<" "; }
#define mod 1e9+7
using namespace std;
ll t,n;
ll arr[200005];
bool solution(){
    ll* freq = new ll[n+1];
    map<ll,bool> visited;
    freq[0] = 0;
    for(ll i=0;i<n;i++){
        freq[i+1] = freq[i] | arr[i];
        visited[arr[i]] = true;
    }

    for(int i=0;i<=n;i++){
        if((visited[freq[i]]&& i>1)){
            return false;
        }
        else{
            visited[freq[i]] = true;
        }
    }
    return true;
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin>>t;
    while(t--){
        cin>>n;
        ArrIn(n) cin>>arr[i];
        bool ans = solution();  
        if(ans){
            cout<<"YES"<<endl;
        }
        else{
            cout<<"NO"<<endl;
        }
    }
    return 0;
}    