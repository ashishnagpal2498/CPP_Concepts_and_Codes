// Omkar and waterSlide
#include<bits/stdc++.h>
#define ll long long int
#define endl "\n"
#define ArrIn(n) for(int i=0;i<n;i++)
#define ArrOut for(int i=0;i<n;i++) {cout<<arr[i]<<" "; }
#define mod 1e9+7
using namespace std;
ll t,n;
ll arr[200005];
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin>>t;
    while(t--){
        cin>>n;
        ArrIn(n) cin>>arr[i];
        ll operation = 0;
        ll d = 0;
        for(int i=1;i<n;i++)
        {
            ll currElem = arr[i-1]+d;
            if((arr[i] + d)>=currElem) continue;
            // int j = i;
            ll diff = currElem - (arr[i]+d);
            operation+=diff;
            d+=diff;
            // while(j<n) arr[j++]+=diff;
        }    
        cout<<operation<<endl;
    }
    return 0;
}    