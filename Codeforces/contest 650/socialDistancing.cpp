// social distancing 
#include<bits/stdc++.h>
#define ll long long int
#define endl "\n"
#define ArrIn(n) for(int i=0;i<n;i++)
#define ArrOut for(int i=0;i<n;i++) {cout<<arr[i]<<" "; }
#define mod 1e9+7
using namespace std;
ll t,n,k;
string s;
ll solve(){
    ll ans =0,prevPos = -1;
    // cout<<"s "<<s<<" "<<n<<" k -> "<<k<<endl;
    for(int i=0;i<n;i++){
        if(s[i] == '1') {
            prevPos = i;
            // cout<<"PrevPos "<<i<<endl;
            continue;
        }
        else if(prevPos != -1 && (i-prevPos)<=k) continue;
        else if(s[i] == '0'){
            int j = -1;
            bool flag = true;
            // cout<<"Here "<<i<<endl;
            // check only for forward -
            // store prev position of 1 -
            for(j=0;j<k && j<n;j++){
                if(s[j+i+1] == '1'){
                    flag = false;
                    break;
                }
            }
            if(flag == true && j == k ){
                prevPos = i;
                i+=(j-1);
                ans++;
            }
            else{
                continue;
            }
        }
    }
    return ans;
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin>>t;
    while(t--){
        cin>>n>>k;
        cin.get();
        cin>>s;    
        cout<<solve()<<endl;
    }
    return 0;
}    