//Price Ceiling
#include<bits/stdc++.h>
#define endl "\n"
#define ll long long int
using namespace std;
ll t,n;
ll arr[200005];
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin>>t;
    ll K;
    while(t--){
        cin>>n>>K;
        for(int i=0;i<n;i++) cin>>arr[i];
        ll sumLoss = 0;
        for(int i=0;i<n;i++){
            if(arr[i]>K) {
                sumLoss += (arr[i]-K);
            }
        }
        cout<<sumLoss<<endl;
    }
    return 0;
}    