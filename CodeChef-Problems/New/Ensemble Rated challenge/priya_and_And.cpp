// Priya and And
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
    while(t--){
        // int freq[101] = {0};
        cin>>n;
        ArrIn(n) {cin>>arr[i];
            // freq[arr[i]]++;
        }
        // sort(arr,arr+n);
        ll ans = 0;
        ArrIn(n){
            for(int j=i+1;j<n;j++){
                ll andVal = arr[i] & arr[j];
                if(andVal == arr[i]) ans++;
            }    
        }
        cout<<ans<<endl;
        
    }
    return 0;
}    