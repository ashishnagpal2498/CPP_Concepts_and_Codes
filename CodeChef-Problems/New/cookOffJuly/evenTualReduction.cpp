//Frequency Substrings
#include<bits/stdc++.h>
#define ll long long int
#define endl "\n"
#define ArrIn(n) for(int i=0;i<n;i++)
#define ArrOut for(int i=0;i<n;i++) {cout<<arr[i]<<" "; }
#define mod 1e9+7
using namespace std;
ll t,n;
ll arr[200005];
string s;
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin>>t;
    while(t--){
        cin>>n;
        int freq[26] = {0};
        cin>>s;
        if(n&1){
            cout<<"NO"<<endl;
        }
        else{
            for(int i=0;i<n;i++){
                int digit = (int)(s[i] - 'a');
                freq[digit]++;
            }
            bool ans= true;
            for(int i=0;i<26;i++){
                if(freq[i]&1){
                    ans = false;
                    break;
                }
            }
            if(ans){
                cout<<"YES"<<endl;
            }
            else{
                cout<<"NO"<<endl;
            }
        }
    }    
    return 0;
}    