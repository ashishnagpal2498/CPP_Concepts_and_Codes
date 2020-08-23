// global 
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
        cin>>n;
        // map<ll,ll> freq;
        ll prevEle = -1;
        bool ans = false;
        ArrIn(n){
            cin>>arr[i];
            // freq[arr[i]]++;
            if(prevEle == -1){
                prevEle = arr[i];
            }
            else if( prevEle != arr[i]){
                ans = true;
            }
        }
        if(ans){
            cout<<1<<endl;
        }
        else {
            cout<<n<<endl;
        }
    }    
    return 0;
}    