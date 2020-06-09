// Number of twos - Tom and Jerry Game
#include<bits/stdc++.h>
#define ll long long int
using namespace std;
ll t,n;
// ll arr[200005];
vector<ll> numbers[500];
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    ll count = 0;
    for(ll i=4;i<100000005;i+=2)
    {   ll n = i;
        count=0;
        while(n%2 == 0)
        {   
        count++;
        n/=2;
        }
        if(count>1){
            numbers[count].push_back(i);
        }
    }
    cin>>t;
    while(t--)
    {
        cin>>n;
        ll ans =0;
        ll i;
        if(n&1){
            cout<<(n/2)<<endl;
        }
        else{
            count = 0;
            i = n;
            while(i%2 == 0)
            {   
            count++;
            i/=2;
            }
        i=count+1;
        ll ans =0;
        while(numbers[i][0]<=n){
            for(ll j=0;j<numbers[i].size();j++)
            {   
                if(numbers[i][j]<=n) {ans++;}
                else break;
            }
            i++;
        }
        cout<<ans<<endl;
        }
        
    }
    return 0;
}    