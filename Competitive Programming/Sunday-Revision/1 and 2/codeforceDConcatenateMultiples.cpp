//Codeforce D-concatenate multiples
//Concatenation of Ai and Aj should be divisible by k
#include<bits/stdc++.h>
#define ll long long int
using namespace std;
ll t,n;
map<ll,ll> modules[10];
ll arr[200005];
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    ll k;
    cin>>n>>k;
    for(int i=0;i<n;i++)
    {
        cin>>arr[i];
        ll p=10;
        // Pre-Computation - creating 10 maps of power 10 to 10^9 for each number -
        for(int j=0;j<10;j++)
        {   ll val = (p*arr[i])% k;
            modules[j][val]++;
            p*=10;
        }
    }
    ll ans = 0;
    for(int i=0;i<n;i++)
    {
        //Find the length of number
        ll noOfZeros = -1;
        ll num = arr[i];
        while(num,noOfZeros++,num/=10);

        //find the value
        ll val;
        val = (k - arr[i]%k) % k;
        ans += modules[noOfZeros][val];

        // Now subtract for same values -
        ll a = 1;
        for(int j=0;j<=noOfZeros;j++) a*=10;
         a%=k;
        ll value = ((arr[i]%k )*(a%k))%k;
         if(value == val) ans--;

    }
    cout<<ans<<endl;
    return 0;
}    