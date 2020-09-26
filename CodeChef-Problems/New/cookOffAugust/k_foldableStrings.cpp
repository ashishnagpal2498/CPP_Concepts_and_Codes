//K foldable strings
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
        map<char,int> freq;
        cin>>s;
        ArrIn(n){
            freq[s[i]]++;
        }
        if((freq['0'] != 0 && freq['0']<(2*k)) || (freq['1'] !=0 && freq['1']<(2*k))){
            // cout<<"Here"<<endl;
            cout<<"IMPOSSIBLE"<<endl;
        }
        else{
            // either equal // or ratio equal to k
            if(freq['1']==freq['0']){
                string ans = "";
                bool flag= false;
                for(int i=0;i<n;i++){
                    if(flag) ans+='1';
                    else ans+='0';
                    if((i+1)%k == 0 && k!=1) flag = !flag;
                     flag = !flag;
                }
                cout<<ans<<endl;
            }
            else if(freq['0'] != 0 && freq['1'] == 0){
               string ans(n,'0');
               cout<<ans<<endl;
            }
             else if(freq['1'] != 0 && freq['0'] == 0){
               string ans(n,'1');
               cout<<ans<<endl;
            }
            else if(freq['1']> freq['0'] && freq['1']%freq['0'] == 0){
                string ans ="";
                int m=0;
                int ratio = freq['1']/freq['0'];
                for(int i=0;i<n;i++,m++){
                    if(m == ratio-1){
                        ans+='0'; i++;
                        m = 0;
                    }
                    ans+='1';
                }
                cout<<ans<<endl;
            }
            else if(freq['0']>freq['1'] && freq['0']%freq['1'] == 0){
                string ans ="";
                int m=0;
                int ratio = freq['0']/freq['1'];

                for(int i=0;i<n;i++,m++){
                    if(m == ratio-1){
                        ans+='1'; i++;
                        m=0;
                    }
                    // else if(m==k-1) m=0;
                    ans+='0';
                }
                cout<<ans<<endl;
            }
            else{
                cout<<"IMPOSSIBLE"<<endl;
            }
        }    
    }
    return 0;
}    