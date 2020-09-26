// A.
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
        vector<int> ans;
        ArrIn(n) cin>>arr[i];
        int eleRemoved = 0;
        if(n == 2){
            if((arr[0] == 1 && arr[1] == 0 ) || (arr[0] == 0 && arr[1] == 1 )){
                cout<<1<<endl<<0<<endl;
            }
            else{
                cout<<2<<endl<<arr[0]<<" "<<arr[0]<<endl;
            }
        }
        else{
                ArrIn(n){
                    if(i+1<n && (arr[i]==0 && arr[i+1] == 0) || (arr[i]==1 && arr[i+1] == 1)) {
                        ans.push_back(arr[i]); ans.push_back(arr[i]); i++;
                        continue;
                    }
                    if(i+2<n && arr[i+1]!=arr[i]&& arr[i+2]!=arr[i]) eleRemoved++;
                    else if(i+2<n && arr[i+2]==arr[i]){
                        ans.push_back(arr[i]);
                        ans.push_back(arr[i]);
                        i+=2;
                    }
                }
                cout<<ans.size()<<endl;
                for(auto val: ans){
                    cout<<val<<" ";
                }
                cout<<endl;
            }
    }
    return 0;
}    