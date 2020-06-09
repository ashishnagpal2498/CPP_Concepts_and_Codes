//Weird Walk 
#include<bits/stdc++.h>
#define endl "\n"
#define ll long long int
using namespace std;
ll t,n;
ll a[200005];
ll b[200005];
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin>>t;
    while(t--)
    {
        ll posA = 0,posB=0,ans=0;
        cin>>n;
        for(int i=0;i<n;i++) cin>>a[i];
        for(int i=0;i<n;i++) cin>>b[i];
        for(int i=0;i<n;i++)
        {
            // calculate abs diff at that step
             if(posA == posB&& a[i]==b[i])
            {
                ans+=a[i];
            }
            posA += a[i];
            posB += b[i];
           
        }
        cout<<ans<<endl;
    }
    return 0;
}    