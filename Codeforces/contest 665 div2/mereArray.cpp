//Mere Array
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
        bool allDivisibility = true;
        bool isSorted = true;
        ll num = -1;
        ll maxEle = INT_MIN;
        ll minEle = INT_MAX;
        cin>>n;
        ArrIn(n){
            cin>>arr[i];
            minEle = min(minEle,arr[i]);
            maxEle = max(maxEle,arr[i]);
            if(i > 0){
                if(arr[i-1]>arr[i]) isSorted = false;
                if(num == -1) {
                    if(arr[i-1]> arr[i]) num = arr[i-1] % arr[i];
                    else num = arr[i] % arr[i-1];
                }
                else if(arr[i-1] > arr[i]){
                    ll n = arr[i-1] % arr[i];
                    if(n != num) allDivisibility = false;
                }
                else{
                    ll n = arr[i] % arr[i-1];
                    if(n != num) allDivisibility = false;
                }
            }
        }
        if(isSorted || allDivisibility){
            cout<<"YES"<<endl;
        }
        else {
            bool flag = true;
            for(int i=0;i<n-1;i++){
                if(arr[i]> arr[i+1] && arr[i]% minEle !=0){
                    flag = false;
                    break;
                }
            }
           if(flag){
            cout<<"YES"<<endl;
           } 
           else{
            cout<<"NO\n";
           }
        }
    }    
    return 0;
}    