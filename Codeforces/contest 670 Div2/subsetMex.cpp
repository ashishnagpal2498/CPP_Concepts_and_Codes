// Mex(A) + Mex(B)
#include<bits/stdc++.h>
#define ll long long int
#define endl "\n"
#define ArrIn(n) for(int i=0;i<n;i++)
#define ArrOut for(int i=0;i<n;i++) {cout<<arr[i]<<" "; }
#define mod 1e9+7
using namespace std;
ll t,n;
// ll arr[200005];
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin>>t;
    while(t--){
        cin>>n;
        int a;
        bool arr1[101]={false},arr2[101]={false};
        ArrIn(n) {
            cin>>a;
            if(!arr1[a]) arr1[a] = true;
            else arr2[a] = true;
        }
        ll ans = 0;    
        ArrIn(101){
            if(!arr1[i]){
                ans+=i;
                break;
            }
        }
        ArrIn(101){
            if(!arr2[i]){
                ans+=i;
                break;
            }
        }
        cout<<ans<<endl;
    }
    return 0;
}    