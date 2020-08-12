// Codeforces contest 664 Div 2
//Binoui likes to color balls
#include<bits/stdc++.h>
#define ll long long int
#define endl "\n"
#define ArrIn(n) for(int i=0;i<n;i++)
#define ArrOut for(int i=0;i<n;i++) {cout<<arr[i]<<" "; }
#define mod 1e9+7
using namespace std;
ll t,n,m,o,p;
ll arr[200005];
bool parity(){
            int oddVal = 1;
        if(n&1) oddVal--;
        if(m&1) oddVal--;
        if(o&1) oddVal--;
        if(p&1) oddVal--;
        return oddVal>=0;
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin>>t;
    while(t--){
        ll minVal = INT_MAX;
        cin>>n>>m>>o>>p;
        minVal = min(n,min(m,o));
        if(parity()) {cout<<"Yes"<<endl;}
        else {
            n--; m--; o--; p+=3;
        if(n>-1 && m>-1 && o>-1 && parity()) {cout<<"Yes"<<endl;}
        else cout<<"No\n";
        }
    }
    return 0;
}    