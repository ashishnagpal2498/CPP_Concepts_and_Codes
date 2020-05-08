//codeforce_D_concat practice 2
#include <bits/stdc++.h>
#define ll long long int
using namespace std;
ll n,k;
ll arr[100005];
ll ans = 0;
map<ll,ll> modules[10];
int main()
{   ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin>>n>>k;
    // 0th index - 10 *
     for(int i=0;i<n;i++) {
        cin>>arr[i];
        ll p = 10;
        for(int j=0;j<10;j++,p*=10)
        {   ll v = ((arr[i]%k) * (p%k))%k;
            modules[j][v]++; 
        }
    }
        // Find ans =
    for(int i=0;i<n;i++)
    {
            //no of zeros -
            ll zeros = -1;
            ll num = arr[i];
            while(num,zeros++,num/=10);
            //index -

            ll findOut = (k - (arr[i]%k))%k;
            ans += modules[zeros][findOut];
            ll po=10;
            for(int j=0;j<zeros;j++,po*=10);
            ll val = ((arr[i]%k )*(po%k))%k;
            if( val == findOut) {--ans;}    
        }
    cout<<ans;
      return 0;
}