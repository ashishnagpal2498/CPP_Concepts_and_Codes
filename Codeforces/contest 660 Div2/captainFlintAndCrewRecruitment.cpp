// Contest 660 Div 2 Captain Flint Crew Recruitment
#include<bits/stdc++.h>
#define ll long long int
#define endl "\n"
#define ArrIn(n) for(int i=0;i<n;i++)
#define ArrOut for(int i=0;i<n;i++) {cout<<arr[i]<<" "; }
#define mod 1e9+7
using namespace std;
ll t,n;
ll nearPrimes[200005];
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin>>t;
    // map<ll,bool> 
    while(t--){
        cin>>n;
        // least number can make
        ll num1 = 6+10+14;
        if(n>=num1){
            cout<<"YES\n";
            cout<<6<<" "<<10<<" "<<14<<" "<<(n-num1)<<endl;
        }
        else{
            cout<<"NO"<<endl;
        }
    }
    return 0;
}    