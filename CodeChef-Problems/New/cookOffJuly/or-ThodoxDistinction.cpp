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
     map<ll,bool> visited;
    for(int mask=0;mask<(1<<n);mask++){
        ll sumOr = 0;
        int j=0;
        while(j<n){
            if((1<<j)&mask){
                sumOr = sumOr|arr[j];
            }
            j++;
        }
        // cout<<sumOr<<endl;
        if(!visited[sumOr]){
            visited[sumOr] = true;
        }
        else{
            return false;
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