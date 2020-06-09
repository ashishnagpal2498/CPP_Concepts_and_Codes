// Preparing Olympiad - Subset
#include<bits/stdc++.h>
#define ll long long int
using namespace std;
ll n,l,r,x;
ll arr[200005];
ll olympiadSets(){
    ll ans = 0;
    for(int mask = 0; mask<(1<<n); mask++)
    {   ll sum =0,minVal = INT_MAX,maxVal = INT_MIN;
        if(__builtin_popcount(mask) > 1)
        { 
            for(int j=0;j<n;j++)
            {
                if(mask&(1<<j))
                {
                    sum+= arr[j];
                    minVal = min(minVal,arr[j]);
                    maxVal = max(maxVal,arr[j]);
                }
            }
        }
        if(sum>= l && sum<=r && (maxVal-minVal)>=x) ans++;
    }
    return ans;
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin>>n>>l>>r>>x;
    for(int i=0;i<n;i++) cin>>arr[i];
    cout<<olympiadSets();    
    return 0;
}    