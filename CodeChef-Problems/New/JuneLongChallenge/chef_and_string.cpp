// Chef and String
#include<bits/stdc++.h>
#define endl "\n"
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
    {
        string s;
        cin>>s;
        ll count = 0;
        for(int i=0;i<s.size();i++)
        {
            if((i+1 < s.size()) && ((s[i]=='x' && s[i+1] == 'y')|| (s[i] == 'y' && s[i+1] == 'x'))) {
                count++;
                i++;
            }
        }
        cout<<count<<endl;
    }
    return 0;
}    