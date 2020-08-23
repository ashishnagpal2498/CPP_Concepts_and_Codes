//TACHSTCK - CodeChef maximum chopsticks
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
        cin>>n>>t;
        ArrIn(n) cin>>arr[i];
        sort(arr,arr+n);
        ll ans =0;
        for(int i=0;i<n-1;i++){
            if(arr[i+1] - arr[i]<=t) { ans++; i++;}
        }     
    cout<<ans<<endl;
    return 0;
}    