// Spoj -> MMMGame
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
        ll zorVal = 0;
        int eachPile1 = 0;
        ArrIn(n){
            cin>>arr[i];
            if(arr[i] == 1) eachPile1++;
            zorVal = zorVal ^ arr[i];
        }
        if((zorVal == 0 && eachPile1 !=n) || (eachPile1==n && n&1)){
            cout<<"Brother"<<endl;
        }    
        else{
            cout<<"John"<<endl;
        }
    }
    return 0;
}    