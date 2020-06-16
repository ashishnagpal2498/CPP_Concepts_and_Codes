// SubArray XXXXX - sum not divisible by x
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
   
    while(t--)
        {    ll sum = 0,x,ans=0;
            cin>>n>>x;
            ArrIn(n) cin>>arr[i];
            for(ll i=0;i<n;i++){
                sum+=arr[i];
                if(sum %x) ans = max(ans,i+1);
            }
            sum =0;
            for(ll i=n-1;i>=0;i--){
                sum+=arr[i];
                if(sum % x) ans = max(ans,n-i);
            }
            if(ans == 0) { cout<<-1<<endl;}
            else cout<<ans<<endl;
        }
    return 0;
}    