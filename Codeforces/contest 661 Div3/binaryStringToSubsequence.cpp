//Binary String to Subsequence
#include<bits/stdc++.h>
#define ll long long int
#define endl "\n"
#define ArrIn(n) for(int i=0;i<n;i++)
#define ArrOut for(int i=0;i<n;i++) {cout<<arr[i]<<" "; }
#define mod 1e9+7
using namespace std;
ll t,n;
// ll arr[200005];
void solve(string s){
    ll ans = 0,stringNo=1;
    map<ll,ll> positions;
    for(int i=0;i<n;i++){
        if(positions.find(i) == positions.end()){
            int j=i+1;
            // for 1 its true
            bool flag = s[i] == '1';
            string small = "";
            small+=s[i];
            positions[i] = stringNo;
            while(j<n){
                if(flag && s[j] == '0' && positions.find(j) == positions.end()){
                    // put 0 in the subsequence
                    positions[j] = stringNo;
                    flag = !flag;
                }
                else if(!flag && s[j] == '1' && positions.find(j) == positions.end()){
                    positions[j] = stringNo;
                    flag = !flag;
                }
                j++;
            }
            ans++;
            stringNo++;
        }
    }
    cout<<ans<<endl;
    for(int i=0;i<n;i++){
        cout<<positions[i]<<" ";
    }
    cout<<endl;
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin>>t;
    while(t--){
        string s;
        cin>>n;
        cin>>s;
        solve(s);
    }
    return 0;
}    