// String similarity
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
        string s;
        cin>>s;
        string ans="";
            int m=0;
            for(int i=n-1;i<2*n-1;i++,m++){
                // cout<<"loop call -> here\n";
                ans+=s[i+m+1-n];
    }
        cout<<ans<<endl;    
    }
    return 0;
}    