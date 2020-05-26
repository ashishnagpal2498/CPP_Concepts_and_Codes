//Baised - Spoj Greedy
#include<bits/stdc++.h>
#define ll long long int
using namespace std;
ll t,n;
ll arr[200005];
ll calBadness(){
    ll rank = 1;
    ll ans = 0;
    for(int i=0;i<n;i++)
    {
        ans+= abs(rank - arr[i]);
        rank++;
    }
    return ans;
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin>>t;
    while(t--)
    {
        cin>>n;
        char s[100005];
        for(int i=0;i<n;i++){
        cin>>s;   
        cin>>arr[i];
        }
        sort(arr,arr+n);
        cout<<calBadness()<<endl;
    }
    return 0;
}    