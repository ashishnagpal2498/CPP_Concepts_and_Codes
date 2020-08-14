//Bad Triangle
#include<bits/stdc++.h>
#define ll long long int
#define endl "\n"
#define ArrIn(n) for(int i=0;i<n;i++)
#define ArrOut for(int i=0;i<n;i++) {cout<<arr[i]<<" "; }
#define mod 1e9+7
ll modExp(ll a,ll j){
    ll ans=1;
    while(j)
    {   if(j&1)
        {
            ans = (ans * a);
        }
        a = (a*a);   
        j>>=1;
    }
    return ans;
}
using namespace std;
ll t,n;
ll arr[200005];
void solution(){
    bool flag = false;
    ArrIn(n){
        if(i+2<n && ( (arr[i+1] - arr[i]>1 && arr[i+2] - arr[i-1] > 1)  
            || (arr[i] == arr[i+1] && arr[i+2] - arr[i+1]>1)
             || (arr[i+1] == arr[i+2] && arr[i+1] - arr[i]>1))){
            flag = true;
            cout<<i+1<<" "<<i+2<<" "<<i+3<<endl;
            break;
        }
    }
    if(!flag){ cout<<-1<<endl;}
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin>>t;
    while(t--){
        cin>>n;
        ArrIn(n) cin>>arr[i];
        solution();
        // cout<<endl;
    }    
    return 0;
}    