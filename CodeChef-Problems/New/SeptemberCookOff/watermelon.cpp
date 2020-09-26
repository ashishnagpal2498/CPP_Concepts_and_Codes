// Watermelon
#include<bits/stdc++.h>
#define ll long long int
using namespace std;
ll t,n;
ll arr[20005];
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin>>t;
    while(t--){
        cin>>n;
        ll sum = 0;
        for (int i = 0; i < n; ++i)
        {
            /* code */
            cin>>arr[i];
            sum+=arr[i];
        }
        // sort(arr,arr+n);
        // bool flag = true;
        if(sum >= 0){
            cout<<"YES\n";
        }
        else{
            cout<<"NO\n";
        }
    }
    return 0;
}