// Chef and Wedding Arrangement
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
    //  solving for k = 1
    while(t--){
        cin>>n>>k;
        int Fi[101]={0};
        ArrIn(n) {
            cin>>arr[i];
            Fi[arr[i]]++;
        }
        // vector<pair<ll,ll> > dp; // cost and last index -> // cost of first table;
        ll cost = k;
        for(int i=0;i<n;i++){
           if(Fi[arr[i]]>1){
            cost+=(Fi[arr[i]]-1);
            Fi[arr[i]] = -1;
           } 
        }
        cout<<cost<<endl;
    }
    return 0;
}    