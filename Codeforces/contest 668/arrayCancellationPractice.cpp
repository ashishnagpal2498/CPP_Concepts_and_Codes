// Array Cancellation - Editorial
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
        ll curr = 0;
        ArrIn(n){
            cin>>arr[i];
            curr = max(0LL,curr+arr[i]);
        }
        cout<<curr<<endl;
    }    
    return 0;
}    