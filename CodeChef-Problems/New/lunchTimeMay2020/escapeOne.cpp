//Escape One - Lunchtime
#include<bits/stdc++.h>
#define endl "\n"
#define ll long long int
using namespace std;
ll t,n;
ll arr[200005];
int main()
{   
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin>>t;
    while(t--)
    {   cin>>n;
        vector<ll> val;
        ll count = 0;
        for(int i=0;i<n;i++) {
            cin>>arr[i];
            if(arr[i]==1){
                val.push_back(i);
            }
        }
        ll ans = 0;
        if(val.size()==0) cout<<0<<endl;
        else if(val.size()==1) cout<<-1<<endl;
        else if(val.size()==2) cout<<val[1]-val[0]<<endl;
        else{
            for(int i=0;i<val.size()-1;i+=2)
            {
                ans+=(val[i+1]-val[i]);
            }
            if(val.size()&1)
            {
                ans+=(val[val.size()-1] - val[val.size()-2]);
            }
            cout<<ans<<endl;
        }

    }
    return 0;
}    