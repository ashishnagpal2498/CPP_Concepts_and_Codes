// Sum of Xor of subArrays
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
    cin>>n;
    ArrIn(n) cin>>arr[i];
    ll ans = 0;
    for(int i=0;i<32;i++)
    {
        ll oddVal = 0, evenVal = 1;
        ll ansOfBit=0;
        ll tot=0;
        for(int j=0;j<n;j++){
            if((1<<i)&arr[j]) {
                oddVal++;
                ansOfBit+=evenVal;
            }
            else{
                evenVal++;
                ansOfBit+=oddVal;
            }
        }
        ans+=(ansOfBit*(1<<i));
    }
    cout<<ans<<endl;
    return 0;
}    