//Codeforce Prepare olympiad
#include<bits/stdc++.h>
#define ll long long int
using namespace std;
ll n,l,r,x;
ll arr[100005]={0};
ll problemSet()
{   ll noOfSets = 1<<n,count =0;
    for(ll mask = 0; mask <noOfSets; mask++)
    {   if(__builtin_popcount(mask) >= 2)
        {
            ll sum=0;
            ll minVal = INT_MAX, maxVal = INT_MIN;
        for(ll j = 0 ; j<n ; j++)
        {
            if( (1<<j)&mask){
            sum+=arr[j];
            minVal = min(minVal,arr[j]);
            maxVal = max(maxVal,arr[j]);
            }
            
        }
        if(sum>=l && sum<=r && ((maxVal-minVal)>=x)) count++;
        }
    }
    return count;
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin>>n>>l>>r>>x;
    for(int i=0;i<n;i++) cin>>arr[i];
    cout<<problemSet();
    return 0;
}