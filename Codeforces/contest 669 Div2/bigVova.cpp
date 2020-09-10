// Big Vova Practice -> 

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
        ll maxVal = 0,index = 0;
        ArrIn(n) {
            cin>>arr[i];
            index = arr[index] < arr[i] ? i : index;
        }
        //sort(arr,arr+n);
        vector<ll> ans(n);
        ans[0] = arr[index];
        // Gcd of i elements --->
        ll bg = ans[0];
        map<ll,bool> visited;

        visited[index] = true;
        for(ll i=1;i<n;i++){
            // position i ->;
            maxVal = 0,index=0;
           for(ll j=0;j<n;j++){
             if(!visited[j]&&__gcd(arr[j],bg) > maxVal){
                index = j;
                maxVal = __gcd(arr[j],bg);
             }
           }
           visited[index] = true;
           ans[i] = arr[index];
           bg = maxVal;
        }
        for(int i=0;i<n;i++){
            cout<<ans[i]<<" ";
        }
        cout<<endl;
    }
    return 0;
}    