// Substrings given , find string
#include<bits/stdc++.h>
#define ll long long int
#define endl "\n"
#define ArrIn(n) for(int i=0;i<n;i++)
#define ArrOut for(int i=0;i<n;i++) {cout<<arr[i]<<" "; }
#define mod 1e9+7
using namespace std;
ll t,n;
string s;
void solve(){
    for(int i=0;i<s.size();i+=2){
        cout<<s[i];
    }
    cout<<s[s.size()-1];
    cout<<endl;
    return;
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin>>t;
    while(t--){
        cin>>s;
        solve();
    }
    return 0;
}    