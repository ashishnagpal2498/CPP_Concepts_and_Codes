//Codeforce - 550B - Preparing Olympiad
#include<bits/stdc++.h>
#define ll long long int
using namespace std;
ll n,l,r,x;
ll arr[100005]={0};
ll problemSet()
{   ll noOfSets = 1<<n,count =0;
    for(int i=0;i<noOfSets;i++)
    {
        int j =i,m=0;
        vector<ll> s;
        while(j)
        {
            int digit = j&1;
            if(digit) s.push_back(arr[m]);
            m++;
            j>>=1;
        }
        ll minVal = INT_MAX, maxVal = INT_MIN;
        ll sum=0;
        for(j=0;j<s.size();j++)
        {  
            sum+= s[j];
            if(minVal > s[j]) minVal = s[j];
            if(maxVal < s[j]) maxVal = s[j];
        }
        if(s.size() >= 2 && sum>=l && sum<=r && ((maxVal-minVal)>=x)) count++;
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