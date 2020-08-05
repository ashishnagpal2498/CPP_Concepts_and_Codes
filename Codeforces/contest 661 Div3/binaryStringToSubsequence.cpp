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
    vector<string> str;
    map<ll,ll> positions;
    string p = "";
    p+=s[0];
    positions[0] = 1;
    str.push_back(p);
    for(int i=1;i<n;i++){
        bool flag = false;
        for(int j=0;j<str.size(); j++){
            // it is a string
            if(str[j][str[j].size()-1] != s[i])
            {
                positions[i] = j+1;
                str[j]+=s[i];
                flag = true;
                break;
            }
        }
        if(!flag){
            string m = "";
            m+=s[i];
            positions[i] = str.size()+1;
            str.push_back(m);
        }
    }
    cout<<str.size()<<endl;
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