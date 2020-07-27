//01 Game
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
    string s;
    while(t--)
    {
        cin>>s;
        ll count =0;
        int i=0;
        while(i<s.size() && s[i]!='\0')
        {
            if(s[i] == '0' && i+1< s.size() && s[i+1] == '1'){
                count++;
                i++;
            }
            else if(s[i] == '1' && i+1 < s.size() && s[i+1] == '0'){
                count++;
                i++;
            }
            i++;
        }
        if(count&1) cout<<"DA\n";
        else cout<<"NET\n";
    }
    return 0;
}    