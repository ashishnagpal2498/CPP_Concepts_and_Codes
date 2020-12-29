//Byte Race 
//
#include<bits/stdc++.h>
#define endl "\n"
#define ll long long int
using namespace std;
ll t, n, k, m;
ll arr[200005];
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> t;
    while (t--) {
        cin>>n>>k;
        if(k<n){
            cout<<0<<endl;
        }
        else if(k==n){
            cout<<1<<endl;
        }
        else{
            ll ans = k/n;
            cout<<ans<<endl;
        }
    }
    return 0;
}