// Spoj - QCJ3 -> pile of coins
#include<bits/stdc++.h>
#define ll long long int
#define endl "\n"
#define ArrIn(n) for(int i=1;i<=n;i++)
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
        ll ans = 0;
        ArrIn(n){
            cin>>arr[i];
            // Using property of Zor value -> 
            // Consider every stone as game of nymp ->
            if(arr[i]&1) ans^=i;
        }
        if(ans == 0) cout<<"Hanks Wins\n";
        else cout<<"Tom Wins\n";
    }    
    return 0;
}    