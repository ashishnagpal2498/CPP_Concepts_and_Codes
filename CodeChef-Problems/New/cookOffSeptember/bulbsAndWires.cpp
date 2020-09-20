//Bulbs and Wires
#include<bits/stdc++.h>
#define ll long long int
#define endl "\n"
#define ArrIn(n) for(int i=0;i<n;i++)
#define ArrOut for(int i=0;i<n;i++) {cout<<arr[i]<<" "; }
#define mod 1e9+7
using namespace std;
ll t,n,k;
ll arr[200005];
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin>>t;
    while(t--){
        cin>>n>>k;
        string s;
        cin>>s;
        int i=0,n = s.size();
        string ans(n,'0');
        // cout<<ans<<endl;
         while(i<n&& k){
            if(s[i]=='1'){
                if(k && i-1>=0 && s[i-1] != '1'){
                    k--;
                    if(ans[i-1] != 'X')
                    ans[i-1] ='X';
                    else {
                        ans[i-1] = 'Y';
                    }
                    // wire Cut ->
                }
                if(k && i+1<n && s[i+1] != '1'){
                    k--;

                    ans[i+1] = 'X';

                    // If both condition will run ->
                    ans[i] = '1';
                }
                i++;
            }
            i++;
         }
         // cout<<ans<<endl;
         i=0;
         int count=0;
         while(i<n){

            if(s[i]==ans[i] || s[i] == '0' && (ans[i] =='Y' || ans[i] == 'X') );
            else{
                if(i-1>=0 && s[i-1] !='1' && ans[i-1] != 'Y') {
                    ans[i-1] == 'Y';
                    count++;
                }
                if(i+1<n && s[i+1] != '1' && (ans[i+1] != 'X' || ans[i+1] != 'Y')){
                    count++;
                    i++;
                    if(ans[i] == 'X')
                    ans[i] = 'Y';
                    else ans[i] = 'X';
                }
            }
            i++;
         }
         cout<<count<<endl;
    }    
    return 0;
}    