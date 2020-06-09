//Strange numbers
#include<bits/stdc++.h>
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
    {   ll k;
        cin>>n>>k;
        ll cnt =0;
        for(int i=2;i*i<=n;i++)
        {
            while(!(n%i))
                {cnt++; n/=i;}
        }
        if(n>1) cnt++;
        if(cnt>=k) {cout<<1<<"\n";}
        else {cout<<0<<"\n";}
    }
    return 0;
}    