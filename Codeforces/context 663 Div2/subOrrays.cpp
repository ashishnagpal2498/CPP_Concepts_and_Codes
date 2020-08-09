//SubOrrays
#include<bits/stdc++.h>
#define ll long long int
#define endl "\n"
#define ArrIn(a,n) for(int i=a;i<n;i++)
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
        ArrIn(0,n) {
            cout<<i+1<<" ";
        }
        cout<<endl;
    }
    return 0;
}    