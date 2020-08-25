// Codeforce Educational Round 93
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
        ArrIn(n)cin>> arr[i];

        if(arr[n-1]>= arr[0]+arr[1]){
            cout<<1<<" "<<2<<" "<<n<<endl;
        }    
        else{
            cout<<-1<<endl;
        }
        
    }
    return 0;
}    