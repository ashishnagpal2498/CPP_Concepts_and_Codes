// String similarity
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
        cin>>n;
        string s;
        cin>>s;
        char* ans = new char[n];
        for(int i=0;i<n;i++) ans[i] = '0';
        if(n == 1){
            ans[0] = s[0];
        }
        else{
            ans[0] = s[0];
            int pos = INT_MIN;
            for(int i=n;i<2*n-1;i++){
                // cout<<"loop call -> here\n";
                int m = 0,j=(i+1)-n;
                bool flag = false;
                while(m<n&&j<j+n){
                    if(ans[m] == s[j]) {
                    // Position matched ;
                         // cout<<"Position Matched\n";
                    pos = max(pos,j);
                    flag = true;
                    break;
                    }
                    m++; j++;
                }
            if(!flag){ 
                // make length of ans till j
                ans[pos+1] = s[pos+1];
                pos++;
            }
        }
    }
        cout<<ans<<endl;    
    }
    return 0;
}    