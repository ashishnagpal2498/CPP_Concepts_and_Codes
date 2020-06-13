// SubArray sum that is not divisible by x
#include<bits/stdc++.h>
#define endl "\n"
#define ll long long int
using namespace std;
ll t,n,x;
ll arr[200005];
ll countSubArrays()
{
    ll count = -1;
    for(int mask=0;mask<(1<<n);mask++)
    {   int i=0;
        ll sum =0;
        ll length=0;
        while(i<n)
        {
            if((1<<i)&mask){
                sum+=(arr[i]%x);
                length++;
            }
            i++;
        }
        if(sum%x != 0){
            count = max(count,length);
        }
    }
    return count;
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin>>t;
    while(t--)
    {
        cin>>n>>x;
        for(int i=0;i<n;i++) cin>>arr[i];
        ll ans = countSubArrays();
        cout<<ans<<endl;
    }
    return 0;
}    