// Smallest possibvle subsequence
#include<bits/stdc++.h>
#define ll long long int
#define endl "\n"
#define ArrIn(n) for(int i=0;i<n;i++)
#define ArrOut for(int i=0;i<n;i++) {cout<<arr[i]<<" "; }
#define mod 1e9+7
using namespace std;
ll t,n,m;
ll arr1[200005],arr2[200005];
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin>>t;
    while(t--){
        cin>>n>>m;
        map<ll,bool> visited;
        ArrIn(n) {
            cin>>arr1[i];
            visited[arr1[i]] = true;
        }
        ArrIn(m) cin>>arr2[i];
        bool flag = false;
        for(int i=0;i<m;i++){
            if(visited[arr2[i]]){
                cout<<"YES"<<endl<<1<<" "<<arr2[i]<<endl;
                flag = true;
                break;
            }
        }
        if(!flag){
            cout<<"NO"<<endl;
        }
    }
    return 0;
}    