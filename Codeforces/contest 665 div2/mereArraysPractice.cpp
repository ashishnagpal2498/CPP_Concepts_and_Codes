// Mere Arrays
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
        vector<ll> sortedArr;
        ll minEle = INT_MAX;
        ArrIn(n) {
            cin>>arr[i];
            sortedArr.push_back(arr[i]);
            minEle = min(minEle,arr[i]);
        }
        sort(sortedArr.begin(),sortedArr.end());
        // Elements same ->
        // map<ll,int> indexMap;
        // ArrIn(n){
        //     indexMap[sortedArr[i]] = i;
        // }
        bool ans= true;
        ArrIn(n){
            if(arr[i] != sortedArr[i] && arr[i]%minEle > 0) {
                ans = false;
                break;
            }
        }
        if(ans) {
            cout<<"YES"<<endl;
        }
        else{
            cout<<"NO"<<endl;
        }
    }    
    return 0;
}    