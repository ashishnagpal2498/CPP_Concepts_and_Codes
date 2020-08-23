// Chef Wars - Return of Jedi
#include<bits/stdc++.h>
#define ll long long int
#define endl "\n"
#define ArrIn(n) for(int i=0;i<n;i++)
#define ArrOut for(int i=0;i<n;i++) {cout<<arr[i]<<" "; }
#define mod 1e9+7
using namespace std;
ll t,h,p;
// ll arr[200005];
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin>>t;
    while(t--){
        cin>>h>>p;
        while(h>0 && p>0){
            h-=p;
            p>>=1;
            // cout<<p<<h<<endl;
        }
        if(h<=0){
            cout<<1<<endl;
        }
        else {
            cout<<0<<endl;
        }
    }    
    return 0;
}    