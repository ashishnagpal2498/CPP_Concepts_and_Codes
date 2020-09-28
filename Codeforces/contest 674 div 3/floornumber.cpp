#include<bits/stdc++.h>
#define endl "\n"
#define ll long long int
using namespace std;
ll t, n,k;
ll arr[200005];
int main()
{           ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin>>t;
    while(t--){
        cin>>n>>k;
        ll i=0;
        while(n> ((k*i)+2)) i++;
        cout<<i+1<<endl;
    }
    return 0;
}