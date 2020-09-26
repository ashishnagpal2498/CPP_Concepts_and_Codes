// CookOff August
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
        ll ans =0;
        ll i = n-1;
        bool flag = true;
        while(true){
            ll weightPick =0;
            ans++;
            while(i>=0){
                if(arr[i]+weightPick<=k){
                    weightPick+=arr[i];
                }
                else{
                    break;
                }
                i--;
            }
            if(weightPick == 0){
                flag = false;
                break;
            }
            else if(i==-1){
                break;
            }
        }
        if(!flag){
            cout<<-1<<endl;
        }
        else{
            cout<<ans<<endl;
        }
    }    
    return 0;
}    