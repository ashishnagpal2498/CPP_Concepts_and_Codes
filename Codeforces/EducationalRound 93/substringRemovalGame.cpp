//Substring removal Game
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
        string s;
        cin>>s;
        n = s.size();
        bool f= false;
        ll conseOnes = 0;
        priority_queue<ll> values;
        for(int i=0;i<n;i++)
        {
            if(s[i] == '1'){
                conseOnes++;
            }
            else if(conseOnes != 0){
                values.push(conseOnes);
                conseOnes=0;
            }
        }
        if(conseOnes!=0) values.push(conseOnes);
        ll ans=0;
        while(!values.empty())
        {
            if(!f){
                ans+= values.top();
            }
            f = !f;
            values.pop();
        }
        cout<<ans<<endl;
    }    
    return 0;
}    