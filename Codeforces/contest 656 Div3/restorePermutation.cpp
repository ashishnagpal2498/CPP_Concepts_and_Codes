// restore permutation
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
        bool arrFreq[51] = {false};
        cin>>n;
        ll sz = 2*n;
        for(int i=0;i<sz;i++) cin>>arr[i];      
        for(int i=0;i<sz;i++){
            if(!(arrFreq[arr[i]])){
                cout<<arr[i]<<" ";
                arrFreq[arr[i]] = true;
            }
        }
        cout<<endl;
    }
    return 0;
}    