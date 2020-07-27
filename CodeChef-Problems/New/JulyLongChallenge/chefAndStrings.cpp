// CodeChef Long July
#include<bits/stdc++.h>
#define ll long long int
#define endl "\n"
#define ArrIn(n) for(int i=0;i<n;i++) cin>>arr[i];
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
        ArrIn(n);
        ll diff = 0,sum=0;
        for(int i=0;i<n-1;i++){
            diff = abs(arr[i] - arr[i+1]);
            sum+= (diff-1);
        }    
        cout<<sum<<endl;
    }
    return 0;
}    