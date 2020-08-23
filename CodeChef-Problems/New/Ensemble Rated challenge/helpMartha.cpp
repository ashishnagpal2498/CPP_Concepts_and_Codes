// Help Martha
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
        ll x1,x2,y1,y2,q;
        map<char,ll> freq;
        // cin.get();
        cin>>s;
        cin>>x1>>y1;
        cin>>q;
        n = s.size();
        for(int i=0;i<n;i++){
            switch(s[i]){
                case 'U' : freq['U']++; break; // y+1
                case 'D' : freq['D'] ++; break;
                case 'R' : freq['R']++; break;
                case 'L' : freq['L']++;  break;
            }
            // cout<<"Loop"<<endl;
        }
        while(q--){
            cin>>x2>>y2;
            //
            bool flag = true;
            ll ans =0;
            ll diff_x = x2- x1,diff_y = y2-y1;
            if(diff_x == 0);
            else if(diff_x>0){
                if(freq['R']>=diff_x) ans+=diff_x;
                else flag = false;
            } 
            else{
                diff_x*=-1;
                if(freq['L']>= diff_x) ans+= diff_x;
                else flag = false;
            }
            if(flag){
                    if(diff_y == 0);
                    else if(diff_y>0){
                        if(freq['U']>=diff_y) ans+=diff_y;
                        else flag = false;
                    } 
                    else{
                        diff_y*=-1;
                        if(freq['D']>= diff_y) ans+= diff_y;
                        else flag = false;
                    }
            }
            if(flag){
                cout<<"YES "<<ans<<endl;
            }
            else{
                cout<<"NO\n";
            }
        }
    }    
    return 0;
}    