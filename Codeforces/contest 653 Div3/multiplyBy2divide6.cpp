// multiply by 2 divide by 6
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
        ll ans =0;
        bool flag = true;
        while(n != 1){
            ans++;
            if(n%3 !=0){
                cout<<-1<<endl;
                flag = false;
                break;
            }
            if(n%6 ==0) n/=6;
            else n*=2;
        }
        if(flag) {
            cout<<ans<<endl;
        }
    }    
    return 0;
}    