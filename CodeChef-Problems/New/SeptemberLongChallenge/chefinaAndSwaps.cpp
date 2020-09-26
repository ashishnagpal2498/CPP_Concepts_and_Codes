//Chefina and Swaps
#include<bits/stdc++.h>
#define ll long long int
#define endl "\n"
#define ArrIn(n) for(int i=0;i<n;i++)
#define ArrOut for(int i=0;i<n;i++) {cout<<arr[i]<<" "; }
#define mod 1e9+7
using namespace std;
ll t,n;
map<ll,ll> arr;
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin>>t;
    ll sum = 0;
    for(ll i=1;i<=1e5;i++){
        sum+=i;
        if(sum&1){
            arr[i] = 0;
        }
        else{
            ll smallSum = 0;
            int j = i;
            while(j>=0 && smallSum<=(sum/2)) {smallSum+=j; j--;}
            arr[i] = i-j;
            // // arr[i] = (sqrtl(sum));
            // // if(arr[i]&1) {arr[i]/=2; arr[i]++;}
            // // else arr[i]/=2;
            // arr[i] = sqrtl(i);
            // if(arr[i]*arr[i] == i);
            // else arr[i]++;
        }
    }
    // for(int i=1e5+1;i<=1e9;i++){
    //     sum+=i;
    //     int index = i%(int)(1e5);
    //     if(sum&1){
    //         arr[index] = 0;
    //     }
    //     else{
    //         arr[index] = ceil(sqrt(i));
    //     }
    // }
    while(t--){
        cin>>n;
        ll ans = arr[n];
        cout<<ans<<endl;
    }
    return 0;
}    