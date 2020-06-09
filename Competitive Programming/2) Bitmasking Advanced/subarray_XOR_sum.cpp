// Sum of XOR of subarrays
#include<bits/stdc++.h>
#define ll long long int
using namespace std;
ll t,n;
ll arr[200005];
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin>>n;
    for(int i=1;i<=n;i++) cin>>arr[i];
    ll ans = 0;
    for(int i=0;i<32;i++)
    {
        ll o=0,e=1,tot=0,ansOfBit = 0;
        for(int j=1 ; j<=n;j++)
        {
            if((1<<i)&arr[j]) tot++;
            if(tot&1) {
              o++;
              ansOfBit+=e;
            }
            else{
            e++;
            ansOfBit+=o;              
            }
        }

        ans+= (ansOfBit* (1<<i));
    }
    cout<<ans<<endl;    
    return 0;
}    