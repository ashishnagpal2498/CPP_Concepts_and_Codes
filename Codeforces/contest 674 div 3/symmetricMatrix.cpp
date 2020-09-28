// Symmetric matrix
#include<bits/stdc++.h>
#define endl "\n"
#define ll long long int
using namespace std;
ll t, n,m;
ll arr[2][2];
int main()
{           ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin>>t;
    while(t--){
        cin>>n>>m;
        bool ans = false;
        for(int i=0;i<n;i++){
            cin>>arr[0][0]>>arr[0][1]>>arr[1][0]>>arr[1][1];
            if(arr[1][0] == arr[0][1]){
                ans = true;
            }
        }
        if(m&1){
            cout<<"NO"<<endl;
        }
        else if(ans){
        
            cout<<"YES"<<endl;
        }
        else{
            cout<<"NO"<<endl;
        }
    }
    return 0;
}