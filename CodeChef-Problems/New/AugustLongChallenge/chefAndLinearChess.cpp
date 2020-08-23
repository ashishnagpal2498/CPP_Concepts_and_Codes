// Chef and Linear Chess
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
        ArrIn(n) cin>>arr[i];
        ll minElement = INT_MAX;
        ll pos = -1;
        ArrIn(n){
            if(k%arr[i] ==0){
                ll a = k/arr[i];
                minElement = min(minElement,a);
                pos = minElement == a ? arr[i] : pos;
            }
        }
        if(minElement == INT_MAX){
            cout<<-1<<endl;
        }
        else{
            cout<<pos<<endl;
        }
    }
    return 0;
}    